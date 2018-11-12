using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;
using System.Xml.Linq;
using Microsoft.VisualBasic;

namespace StoryEditor
{
    public partial class TextAdventureMaker : Form
    {
        //Load workspaces xml
        private string workspaceFilename = "elements/debug_workspaces.xml";
        private XDocument doc = XDocument.Load("elements/debug_workspaces.xml");

        public TextAdventureMaker()
        {
            InitializeComponent();
        }

        /* Open Brainiac */
        private void OpenEditor_Click(object sender, EventArgs e)
        {
            if (File.Exists(AppDomain.CurrentDomain.BaseDirectory + "elements/Brainiac.exe"))
            {
                //Set current game as selected workspace
                doc.Element("workspaces").Attribute("selected").Value = ExistingGames.SelectedItem.ToString();
                doc.Save(workspaceFilename);

                //Start Brainiac
                ProcessStartInfo process = new ProcessStartInfo();
                process.WorkingDirectory = AppDomain.CurrentDomain.BaseDirectory + "elements";
                process.FileName = "Brainiac.exe";
                Process myProcess = Process.Start(process);
            }
            else
            {
                MessageBox.Show("Cannot find editor! Please check your install.", "Fatal error occured.", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        /* Compile to JSON */
        private void OpenGenerator_Click(object sender, EventArgs e)
        {
            try
            {
                convertStoryToJSON();
            }
            catch
            {
                MessageBox.Show("An unexpected error occured.\nPlease check your game flowchart is to standard.", "Fatal error occured.", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        /* Open Game */
        private void OpenTextAdventure_Click(object sender, EventArgs e)
        {
            if (File.Exists(AppDomain.CurrentDomain.BaseDirectory + "TextAdventureGame.exe"))
            {
                Process myProcess = Process.Start(AppDomain.CurrentDomain.BaseDirectory+"TextAdventureGame.exe");
            }
            else
            {
                MessageBox.Show("Cannot find game! Please check your install.", "Fatal error occured.", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        /* Open String Editor */
        private void OpenLocalisationEditor_Click(object sender, EventArgs e)
        {
            LocalisationEditor stringEd = new LocalisationEditor(getCurrentWorkspace().Attribute("folder").Value, getCurrentWorkspace().Attribute("name").Value);
            stringEd.Show();
        }

        /* Create a new game instance */
        private void CreateNewGame_Click(object sender, EventArgs e)
        {
            //Gather game information from user
            var newGameTitle = Interaction.InputBox("What is the name of this game?", "Creating a new text adventure...", "Text Adventure Game");
            var newGameDeveloper = Interaction.InputBox("Who is the developer?", "Creating a new text adventure...", "John Smith");
            var newGameInvalidInput = Interaction.InputBox("What should the game reply for an invalid input?", "Creating a new text adventure...", "I'm sorry, I don't understand.");
            var newGameWaitText = Interaction.InputBox("What should the game use to disable input while responding?", "Creating a new text adventure...", "<< WAIT >>");

            if (newGameTitle == "" || newGameDeveloper == "" || newGameInvalidInput == "" || newGameWaitText == "")
            {
                MessageBox.Show("One or more inputs was empty, please try again!", "An error occured.", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                string folderName = makeDirectoryName(newGameTitle);

                //Update workspaces list
                XElement newWorkspace = XElement.Parse("<workspace name=\"" + newGameTitle + "\" folder=\"" + folderName + "\" export=\"" + folderName + "\"></workspace>");
                newWorkspace.Add(XElement.Parse("<plugin>TextAdventure.dll</plugin>"));
                doc.Element("workspaces").Add(newWorkspace);

                //Create working directory and insert the starting template
                Directory.CreateDirectory("elements/" + folderName);
                XDocument demo = XDocument.Load("elements/demo.xml");
                XElement demoBookmark = demo.Element("Behavior").Element("Node").Element("Connector").Element("Node");
                demoBookmark.Attribute("GameTitle").Value = newGameTitle;
                demoBookmark.Attribute("GameDeveloper").Value = newGameDeveloper;
                demoBookmark.Element("Connector").Element("Node").Attribute("DisabledInput").Value = newGameWaitText;
                demoBookmark.Element("Connector").Element("Node").Attribute("InvalidInput").Value = newGameInvalidInput;
                demo.Save("elements/" + folderName + "/main.xml");

                //Reload
                reloadWorkspaceList();
            }
        }

        /* Delete a game instance */
        private void DeleteSelectedGame_Click(object sender, EventArgs e)
        {
            var confirmation = MessageBox.Show("You are about to delete '" + ExistingGames.SelectedItem + "'.\nAre you sure this is correct?", "Please confirm this action.", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (confirmation == DialogResult.Yes)
            {
                //Delete data folder and from workspaces list
                Directory.Delete("elements/" + getCurrentWorkspace().Attribute("folder").Value, true);
                getCurrentWorkspace().Remove();
                reloadWorkspaceList();
            }
        }

        /* Form Load */
        private void TextAdventureMaker_Load(object sender, EventArgs e)
        {
            reloadWorkspaceList();
        }

        /* Save and reload workspace list */
        private void reloadWorkspaceList()
        {
            doc.Save(workspaceFilename);
            ExistingGames.Items.Clear();
            int index = 0;
            foreach (var workspace in doc.Element("workspaces").Elements())
            {
                ExistingGames.Items.Insert(index, workspace.Attribute("name").Value);
                index++;
            }
            if (index != 0)
            {
                ExistingGames.SelectedIndex = index - 1;
                formInteractionEnabled(true);
            }
            else
            {
                formInteractionEnabled(false);
            }
        }

        /* Enable/Disable Interaction */
        private void formInteractionEnabled(bool enabled)
        {
            DeleteSelectedGame.Enabled = enabled;
            OpenEditor.Enabled = enabled;
            OpenGenerator.Enabled = enabled;
            OpenTextAdventure.Enabled = enabled;
            SaveGameToShare.Enabled = enabled;
        }

        /* Make game directory name */
        private string makeDirectoryName(string input)
        {
            return BitConverter.ToString(Encoding.Default.GetBytes(input)).Replace("-", "");
        }

        /* Find and return current workspace element */
        private XElement getCurrentWorkspace()
        {
            foreach (var workspace in doc.Element("workspaces").Elements())
            {
                var workspaceName = workspace.Attribute("name").Value;
                if (workspaceName == ExistingGames.SelectedItem)
                {
                    return workspace;
                }
            }
            return XElement.Parse("<workspace></workspace>"); //Shouldn't get here!
        }

        /* Convert Brainiac XML to JSON */
        private void convertStoryToJSON()
        {
            //Load XML from brainiac and setup our variables
            var gameDoc = XDocument.Load("elements/" + getCurrentWorkspace().Attribute("folder").Value + "/main.xml");
            XElement gameCoreXML = gameDoc.Element("Behavior").Element("Node").Element("Connector").Element("Node");
            string finalOutput = "{";
            List<string> prefixes = new List<string>();

            //Start traversing XML...
            int levelCount = 0;
            foreach (var levelNode in gameCoreXML.Element("Connector").Elements())
            {
                if (levelNode.FirstAttribute.Value == "TextAdventure.Nodes.GameLevel") //Level 
                {
                    finalOutput += "\"" + levelCount.ToString() + "\":{\"level_name\":\"" + levelNode.Attribute("Name").Value + "\", ";
                    int zoneCount = 0;
                    foreach (var ZoneNode in levelNode.Element("Connector").Elements())
                    {
                        if (ZoneNode.FirstAttribute.Value == "TextAdventure.Nodes.LevelZone") //Zone in current level
                        {
                            finalOutput += "\"" + zoneCount.ToString() + "\":{\"zone_name\":\"" + ZoneNode.Attribute("Name").Value + "\", ";
                            int stateCount = 0;
                            foreach (var stateNode in ZoneNode.Element("Connector").Elements())
                            {
                                if (stateNode.FirstAttribute.Value == "TextAdventure.Nodes.ZoneState") //State in current zone
                                {
                                    finalOutput += "\"" + stateCount.ToString() + "\":{\"state_name\":\"" + stateNode.Attribute("Name").Value + "\", ";
                                    foreach (var inputActionNode in stateNode.Element("Connector").Elements())
                                    {
                                        if (inputActionNode.FirstAttribute.Value == "TextAdventure.Nodes.ZoneIntro") //Zone intro text for state
                                        {
                                            finalOutput += "\"zone_intro\":\"" + inputActionNode.Attribute("IntroText").Value + "\", ";
                                        }
                                        if (inputActionNode.FirstAttribute.Value == "TextAdventure.Nodes.InputAction") //Input action in current zone
                                        {
                                            string thisAction = inputActionNode.Attribute("Action").Value;
                                            if (!prefixes.Contains(thisAction))
                                            {
                                                prefixes.Add(thisAction);
                                            }
                                            finalOutput += "\"" + thisAction + "\":{";
                                            foreach (var inputSubjectNode in inputActionNode.Element("Connector").Elements())
                                            {
                                                if (inputSubjectNode.FirstAttribute.Value == "TextAdventure.Nodes.InputSubject") //Input subject for current action
                                                {
                                                    //Here our logic is handled...
                                                    finalOutput += "\"" + inputSubjectNode.Attribute("Subject").Value + "\":{";
                                                    List<string> gameDataToAdd = new List<string>();
                                                    List<string> gameDataToRemove = new List<string>();
                                                    foreach (var inputScriptNode in inputSubjectNode.Element("Connector").Elements())
                                                    {
                                                        if (inputScriptNode.FirstAttribute.Value == "TextAdventure.Nodes.ReferencedInput")
                                                        {
                                                            //Action is referenced from another node group.
                                                            finalOutput += "\"referenced\": [\"" + inputScriptNode.Attribute("InputAction").Value + "\",\"" + inputScriptNode.Attribute("InputSubject").Value + "\"]";
                                                        }
                                                        else
                                                        {
                                                            if (inputScriptNode.FirstAttribute.Value == "TextAdventure.Nodes.GameDataExists")
                                                            {
                                                                //Optional/Required GameData Condition
                                                                if (inputScriptNode.Attribute("GameDataCondition").Value == "OPTIONAL:0")
                                                                {
                                                                    finalOutput += "\"optional_gamedata\": ";
                                                                }
                                                                else
                                                                {
                                                                    finalOutput += "\"required_gamedata\": ";
                                                                }
                                                                finalOutput += "[\"" + inputScriptNode.Attribute("GameData").Value + "\"], ";

                                                                //Response of condition for true/false outcomes.
                                                                //OPTIONAL and REQUIRED use these outcomes, however REQUIRED will ignore all following logic if false.
                                                                foreach (var dataConditionResult in inputScriptNode.Elements())
                                                                {
                                                                    if (dataConditionResult.Attribute("Identifier").Value == "ConditionTrue")
                                                                    {
                                                                        if (dataConditionResult.Element("Node").LastAttribute.Name == "SystemResponse")
                                                                        {
                                                                            finalOutput += "\"system_reply_ok\": \"" + dataConditionResult.Element("Node").LastAttribute.Value + "\", ";
                                                                        }
                                                                    }
                                                                    else if (dataConditionResult.Attribute("Identifier").Value == "ConditionFalse")
                                                                    {
                                                                        if (dataConditionResult.Element("Node").LastAttribute.Name == "SystemResponse")
                                                                        {
                                                                            finalOutput += "\"system_reply_issue\": \"" + dataConditionResult.Element("Node").LastAttribute.Value + "\", ";
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                            if (inputScriptNode.FirstAttribute.Value == "TextAdventure.Nodes.ModifyGameData")
                                                            {
                                                                //Add/Remove game data
                                                                if (inputScriptNode.Attribute("Action").Value == "ADD:0")
                                                                {
                                                                    gameDataToAdd.Add(inputScriptNode.Attribute("ModifyGameDataLocationName").Value);
                                                                }
                                                                else
                                                                {
                                                                    gameDataToRemove.Add(inputScriptNode.Attribute("ModifyGameDataLocationName").Value);
                                                                }
                                                            }
                                                            if (inputScriptNode.FirstAttribute.Value == "TextAdventure.Nodes.Response")
                                                            {
                                                                //Basic response not in a context of condition
                                                                finalOutput += "\"system_reply_ok\": \"" + inputScriptNode.Attribute("SystemResponse").Value + "\", ";
                                                            }
                                                            if (inputScriptNode.FirstAttribute.Value == "TextAdventure.Nodes.MoveTo")
                                                            {
                                                                //Move to...
                                                                if (inputScriptNode.Attribute("MoveToLocationType").Value == "LEVEL:0")
                                                                {
                                                                    //Level
                                                                    finalOutput += "\"new_level\": \"";
                                                                }
                                                                else if (inputScriptNode.Attribute("MoveToLocationType").Value == "ZONE:1")
                                                                {
                                                                    //Zone
                                                                    finalOutput += "\"new_zone\": \"";
                                                                }
                                                                else
                                                                {
                                                                    //State
                                                                    finalOutput += "\"new_state\": \"";
                                                                }
                                                                finalOutput += inputScriptNode.Attribute("MoveToLocationName").Value + "\", ";
                                                            }
                                                        }
                                                    }
                                                    if (finalOutput.Substring(finalOutput.Length - 2) == ", ")
                                                    {
                                                        //Tidy up
                                                        finalOutput = finalOutput.Substring(0, finalOutput.Length - 2);
                                                    }
                                                    if (gameDataToAdd.Count() > 0)
                                                    {
                                                        //Concat gamedata to add (we can have multiple nodes of this)
                                                        finalOutput += ", \"add_gamedata\": [";
                                                        for (int i = 0; i < gameDataToAdd.Count(); i++)
                                                        {
                                                            finalOutput += "\"" + gameDataToAdd[i] + "\",";
                                                        }
                                                        finalOutput = finalOutput.Substring(0, finalOutput.Length - 1);
                                                        finalOutput += "]";
                                                    }
                                                    if (gameDataToRemove.Count() > 0)
                                                    {
                                                        //Concat gamedata to remove (we can have multiple nodes of this)
                                                        finalOutput += ", \"remove_gamedata\": [";
                                                        for (int i = 0; i < gameDataToRemove.Count(); i++)
                                                        {
                                                            finalOutput += "\"" + gameDataToRemove[i] + "\",";
                                                        }
                                                        finalOutput = finalOutput.Substring(0, finalOutput.Length - 1);
                                                        finalOutput += "]";
                                                    }
                                                    finalOutput += "}, ";
                                                }
                                            }
                                            //Tidy up
                                            finalOutput = finalOutput.Substring(0, finalOutput.Length - 2);
                                            finalOutput += "}, ";
                                        }
                                    }
                                    //Tidy up & increment
                                    finalOutput = finalOutput.Substring(0, finalOutput.Length - 2);
                                    finalOutput += "}, ";
                                    stateCount++;
                                }
                            }
                            //Tidy up & increment
                            finalOutput = finalOutput.Substring(0, finalOutput.Length - 2);
                            finalOutput += "}, ";
                            zoneCount++;
                        }
                    }
                    //Tidy up & increment
                    finalOutput = finalOutput.Substring(0, finalOutput.Length - 2);
                    finalOutput += "}, ";
                    levelCount++;
                }
            }

            //Work out all prefixes used in the game
            string prefixesString = "";
            for (int i = 0; i < prefixes.Count(); i++)
            {
                prefixesString += prefixes[i] + "\",\"";
            }
            prefixesString = prefixesString.Substring(0, prefixesString.Length - 3);

            //Json-ify core game data
            finalOutput += "\"game_core\":{\"title\": \"" +
                gameCoreXML.Attribute("GameTitle").Value + "\", \"developer\": \"" +
                gameCoreXML.Attribute("GameDeveloper").Value + "\", \"invalid_input\": \"" +
                gameCoreXML.Element("Connector").Element("Node").Attribute("InvalidInput").Value + "\", \"fatal_error\": \"A FATAL ERROR OCCURRED!\\n\\nPLEASE CHECK YOUR SCRIPTING.\", \"input_disabled\": \"" +
                gameCoreXML.Element("Connector").Element("Node").Attribute("DisabledInput").Value + "\", \"prefixes\": [\"" + prefixesString + "\"]}}";

            //Write out to file for use in game
            Directory.CreateDirectory("data/");
            File.WriteAllText("data/story.json", finalOutput);

            //Success
            MessageBox.Show("Successfully compiled selected game!\nPlay it to try out the logic.", "Operation completed.", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        /* Copy final product to output directory */
        private void SaveGameToShare_Click(object sender, EventArgs e)
        {
            if (File.Exists("data/story.json"))
            {
                //Create directories
                Directory.CreateDirectory("share");
                Directory.CreateDirectory("share/data");

                //Remove existing
                if (File.Exists("share/data/story.json"))
                {
                    File.Delete("share/data/story.json");
                    File.Delete("share/game.dat");
                    File.Delete("share/data/TextAdventureGame.exe");
                }

                //Copy in data
                File.Copy("data/story.json", "share/data/story.json");
                File.Copy("game.dat", "share/game.dat");
                File.Copy("TextAdventureGame.exe", "share/TextAdventureGame.exe");

                //Open directory
                Process.Start("share");
            }
            else
            {
                MessageBox.Show("Please compile your game before saving.", "Cannot save uncompiled game.", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void EditSelectedGame_Click(object sender, EventArgs e)
        {
            /* DEPRECIATED */
        }
    }
}
