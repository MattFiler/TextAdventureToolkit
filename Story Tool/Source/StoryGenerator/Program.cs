using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;
using System.Xml.XPath;

namespace StoryGenerator
{
    class Program
    {
        static void Main(string[] args)
        {
            if (File.Exists("output/main.xml"))
            {
                //Load XML from brainiac and setup our variables
                var doc = XDocument.Load("output/main.xml");
                XElement gameCoreXML = doc.Element("Behavior").Element("Node").Element("Connector").Element("Node");
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
                Directory.CreateDirectory("../data/");
                File.WriteAllText("../data/story.json", finalOutput);

                //Success
                Console.Write("Successfully compiled story!");
                //Console.ReadLine();
            }
            else
            {
                //Input file doesn't exist
                Console.Write("Couldn't find your story flowchart file!\nMake sure you followed the naming conventions.");
                Console.ReadLine();
            }
        }
    }
}
