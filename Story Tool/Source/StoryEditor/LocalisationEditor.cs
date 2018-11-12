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
                if (!File.Exists(languageFile))
                {
                    //Create default file if doesn't exist
                    XElement.Parse("<language></language>").Save(languageFile);
                }
                LanguageSelect.Items.Add(supportedLanguages[i]);
            }
            LanguageSelect.SelectedIndex = 0;
        }

        /* Load all strings for newly selected language */
        private void LanguageSelect_SelectedIndexChanged(object sender, EventArgs e)
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
            var newStringID = Interaction.InputBox("String unique identifier", "Add a new localised string...", "GAME_STRING_01");
            var newStringText = Interaction.InputBox("String text content", "Add a new localised string...", "An example of a string in English. Change this to suit your language and purpose.");

            if (newStringID == "" || newStringText == "")
            {
                MessageBox.Show("Please fill out both inputs.\nData cannot be blank.", "An error occured.", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                //Update list
                StringIdentifierList.Items.Add(newStringID);
                StringList.Items.Add(newStringText);

                //Update file
                languageDoc.Element("language").Add(XElement.Parse("<string id=\"" + newStringID + "\" text=\"" + newStringText + "\"></string>"));
                languageDoc.Save(gameFolder + "/" + LanguageSelect.SelectedItem + ".xml");
            }
        }

        /* Edit selected string */
        private void EditString_Click(object sender, EventArgs e)
        {
            StringIdentifierList.Enabled = false;
            StringList.Enabled = false;

            //Take new edited inputs
            var newStringID = Interaction.InputBox("String unique identifier", "Add a new localised string...", StringIdentifierList.SelectedItem.ToString());
            var newStringText = Interaction.InputBox("String text content", "Add a new localised string...", StringList.SelectedItem.ToString());

            //Update file and list
            XElement currentItem = getSelectedXmlItem();
            currentItem.Attribute("id").Value = newStringID;
            currentItem.Attribute("text").Value = newStringText;
            languageDoc.Save(gameFolder + "/" + LanguageSelect.SelectedItem + ".xml");
            StringIdentifierList.Items[StringIdentifierList.SelectedIndex] = newStringID;
            StringList.Items[StringList.SelectedIndex] = newStringText;

            StringIdentifierList.Enabled = true;
            StringList.Enabled = true;
        }

        /* Remove selected string */
        private void RemoveString_Click(object sender, EventArgs e)
        {
            var confirmation = MessageBox.Show("You are about to delete '" + StringIdentifierList.SelectedItem + "'.\nAre you sure this is correct?", "Please confirm this action.", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (confirmation == DialogResult.Yes)
            {
                //Update file
                getSelectedXmlItem().Remove();
                languageDoc.Save(gameFolder + "/" + LanguageSelect.SelectedItem + ".xml");

                //Update list
                int indexToDelete = StringList.SelectedIndex;
                StringIdentifierList.Items.RemoveAt(indexToDelete);
                StringList.Items.RemoveAt(indexToDelete);
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
                if (languageString.Attribute("id").Value == StringIdentifierList.SelectedItem)
                {
                    return languageString;
                }
            }
            return XElement.Parse("<string></string>"); //shouldn't get here.
        }
    }
}
