using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Text;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace StoryEditor
{
    public partial class LocalisationNewString : Form
    {
        private string gameFolder = "";
        private string[] supportedLanguages = { "english", "spanish", "french", "german" };
        private XDocument[] languageDocs = { null, null, null, null };
        private string[] languageDocPaths = { null, null, null, null };
        private int currentLanguage = -1;
        private int requestedLanguage = -1;

        public LocalisationNewString(string folderName, string stringID, int defaultLanguage = 0)
        {
            InitializeComponent();
            gameFolder = folderName;
            StringID.Text = stringID;
            requestedLanguage = defaultLanguage;

            //Configure font for preview panel
            PrivateFontCollection previewFont = new PrivateFontCollection();
            previewFont.AddFontFile("elements/font.ttf");
            LocalisedString.Font = new Font(previewFont.Families[0], 15);
        }

        /* Populate language data on load */
        private void LocalisationNewString_Load(object sender, EventArgs e)
        {
            LanguageSelect.Items.Clear();
            for (int i = 0; i < supportedLanguages.Count(); i++)
            {
                languageDocPaths[i] = gameFolder + "/" + supportedLanguages[i] + ".xml";
                languageDocs[i] = XDocument.Load(languageDocPaths[i]);
                LanguageSelect.Items.Add(supportedLanguages[i]);
                if (languageElementText(i) == null)
                {
                    languageDocs[i].Element("language").Add(XElement.Parse("<string id=\"" + StringID.Text + "\" text=\"\"></string>"));
                }
            }
            LanguageSelect.SelectedIndex = requestedLanguage;
        }

        /* Update when new language selected */
        private void LanguageSelect_SelectedIndexChanged(object sender, EventArgs e)
        {
            //Save old input to local XML structure and load new one
            if (currentLanguage != -1)
            {
                languageElementText(currentLanguage).Value = LocalisedString.Text;
            }
            currentLanguage = LanguageSelect.SelectedIndex;
            LocalisedString.Text = languageElementText(currentLanguage).Value;
        }

        /* Save all languages for string */
        private void SaveAll_Click(object sender, EventArgs e)
        {
            languageElementText(currentLanguage).Value = LocalisedString.Text;
            for (int i = 0; i < supportedLanguages.Count(); i++)
            {
                languageDocs[i].Save(languageDocPaths[i]);
            }
            this.Close();
        }

        /* Return a getter/setter for the current language */
        private XAttribute languageElementText(int language)
        {
            try
            {
                foreach (var languageString in languageDocs[language].Element("language").Elements())
                {
                    if (languageString.Attribute("id").Value == StringID.Text)
                    {
                        return languageString.Attribute("text");
                    }
                }
            } catch { }
            return null;
        }

        /* Apply current text to all */
        private void ApplyToAll_Click(object sender, EventArgs e)
        {
            var confirmation = MessageBox.Show("You are about to apply the current string to ALL languages.\nAre you sure this is correct?", "Please confirm this action.", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (confirmation == DialogResult.Yes)
            {
                for (int i=0; i<supportedLanguages.Count(); i++)
                {
                    languageElementText(i).Value = LocalisedString.Text;
                }
                MessageBox.Show("Applied to all.", "Operation completed.", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
    }
}
