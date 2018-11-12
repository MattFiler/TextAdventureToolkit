using Microsoft.VisualBasic;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace StoryEditor
{
    public partial class LocalisationEditor : Form
    {
        private string gameFolder = "";
        private string[] supportedLanguages = { "english", "spanish", "french", "german" };
        private XDocument languageDoc;

        public LocalisationEditor(string folderName, string gameName)
        {
            InitializeComponent();
            gameFolder = "elements/"+folderName;
            this.Text = "Localisation for '" + gameName + "'";
        }

        /* Form Load */
        private void LocalisationEditor_Load(object sender, EventArgs e)
        {
            LanguageSelect.Items.Clear();
            for (int i=0; i<supportedLanguages.Count(); i++)
            {
                string languageFile = gameFolder + "/" + supportedLanguages[i] + ".xml";
                LanguageSelect.Items.Add(supportedLanguages[i]);
            }
            LanguageSelect.SelectedIndex = 0;
        }

        /* New language selected */
        private void LanguageSelect_SelectedIndexChanged(object sender, EventArgs e)
        {
            refreshLanguage();
        }

        /* Load all strings again for current language */
        private void refreshLanguage()
        {
            //Clear lists
            StringIdentifierList.Items.Clear();
            StringList.Items.Clear();

            //Re-fill with new content
            languageDoc = XDocument.Load(gameFolder + "/" + LanguageSelect.SelectedItem + ".xml");
            foreach (var languageString in languageDoc.Element("language").Elements())
            {
                StringIdentifierList.Items.Add(languageString.Attribute("id").Value);
                StringList.Items.Add(languageString.Attribute("text").Value);
            }
        }

        /* Add a new string */
        private void AddString_Click(object sender, EventArgs e)
        {
            var newStringID = Interaction.InputBox("Unique string identifier to reference this string by. This cannot be edited after creation!", "Adding a new localised string...", "GAME_STRING_01");
            if (newStringID != "")
            {
                //Open editor window
                LocalisationNewString editor = new LocalisationNewString(gameFolder, newStringID);
                editor.Show();
                editor.FormClosed += new FormClosedEventHandler(stringEditorClosed);
            }
        }

        /* Update list when editor is closed */
        void stringEditorClosed(object sender, FormClosedEventArgs e)
        {
            refreshLanguage();
            StringIdentifierList.Enabled = true;
            StringList.Enabled = true;
        }

        /* Edit selected string */
        private void EditString_Click(object sender, EventArgs e)
        {
            if (StringIdentifierList.SelectedIndex != -1)
            {
                //Disable inputs and open editor
                StringIdentifierList.Enabled = false;
                StringList.Enabled = false;

                LocalisationNewString editor = new LocalisationNewString(gameFolder, StringIdentifierList.SelectedItem.ToString(), LanguageSelect.SelectedIndex);
                editor.Show();
                editor.FormClosed += new FormClosedEventHandler(stringEditorClosed);
            }
            else
            {
                MessageBox.Show("Nothing selected!\nPlease select a string from the list to edit.", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        /* Remove selected string */
        private void RemoveString_Click(object sender, EventArgs e)
        {
            if (StringIdentifierList.SelectedIndex != -1)
            {
                var confirmation = MessageBox.Show("You are about to delete '" + StringIdentifierList.SelectedItem + "'.\nAre you sure this is correct?", "Please confirm this action.", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (confirmation == DialogResult.Yes)
                {
                    //Remove from files
                    for (int i = 0; i < supportedLanguages.Count(); i++)
                    {
                        XDocument languageDocument = XDocument.Load(gameFolder + "/" + supportedLanguages[i] + ".xml");
                        foreach (var languageString in languageDocument.Element("language").Elements())
                        {
                            if (languageString.Attribute("id").Value == StringIdentifierList.SelectedItem.ToString())
                            {
                                languageString.Remove();
                            }
                        }
                        languageDocument.Save(gameFolder + "/" + supportedLanguages[i] + ".xml");
                    }

                    //Update list
                    int indexToDelete = StringList.SelectedIndex;
                    StringIdentifierList.Items.RemoveAt(indexToDelete);
                    StringList.Items.RemoveAt(indexToDelete);
                }
            }
            else
            {
                MessageBox.Show("Nothing selected!\nPlease select a string from the list to remove.", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        /* Double highlighting on listboxes */
        private void StringIdentifierList_SelectedIndexChanged(object sender, EventArgs e)
        {
            StringList.SelectedIndex = StringIdentifierList.SelectedIndex;
        }
        private void StringList_SelectedIndexChanged(object sender, EventArgs e)
        {
            StringIdentifierList.SelectedIndex = StringList.SelectedIndex;
        }

        /* Return selected list item as XML item */
        private XElement getSelectedXmlItem()
        {
            foreach (var languageString in languageDoc.Element("language").Elements())
            {
                if (languageString.Attribute("id").Value == StringIdentifierList.SelectedItem.ToString())
                {
                    return languageString;
                }
            }
            return null; 
        }

        private void OpenEditor_Click(object sender, EventArgs e)
        {
            /* DEPRECIATED */
        }
    }
}
