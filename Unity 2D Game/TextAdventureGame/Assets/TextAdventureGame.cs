using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.IO;
using SimpleJSON;
using UnityEngine.EventSystems;

public class TextAdventureGame : MonoBehaviour
{
    /* 
    ------
    PUBLIC 
    ------
    */

    // Game UI Elements
    public Text Game_Title;
    public Text Game_Developer;
    //
    public Text Zone_Intro_Text;
    public Text Game_Response_Text;
    //
    public InputField User_Input;

    // Game Constants
    public int Max_GameData_Space = 250;

    /*
    -------
    PRIVATE
    -------
    */

    // Game UI Outputs
    string Zone_Intro_Text_Queued = "";
    string Game_Response_Text_Queued = "";

    // Game Progress Logs
    int current_level = 0;
    int current_zone = 0;
    int current_state = 0;

    // JSON Data
    string jsonString = "";

    // Parsed Input
    string inputAction = "";
    string inputSubject = "";
    bool inputIsValid = true;

    /* Read in the text adventure from a JSON file */
    void Start()
    {
        jsonString = File.ReadAllText(Application.streamingAssetsPath + "/story.json");
        var logic = JSON.Parse(jsonString);

        User_Input.onEndEdit.AddListener(delegate { handleUserInput(); });
        EventSystem.current.SetSelectedGameObject(GameObject.Find("User_Input"));

        Game_Title.text = getGameTitle();
        Game_Developer.text = getGameDeveloper();
        Zone_Intro_Text.text = getZoneIntro();
    }

    /* Return the number of levels */
    private int levelsInThisGame()
    {
        var logic = JSON.Parse(jsonString);
        return logic.AsObject.Count - 1; //-1 to account for game_core
    }
    /* Return the number of zones per level */
    private int zonesInThisLevel(int level_id)
    {
        var logic = JSON.Parse(jsonString);
        return logic[level_id.ToString()].AsObject.Count - 1; //-1 to account for level_name
    }
    /* Return the number of states per zone */
    private int statesInThisZone(int level_id, int zone_id)
    {
        var logic = JSON.Parse(jsonString);
        return logic[level_id.ToString()][zone_id.ToString()].AsObject.Count - 1; //-1 to account for zone_name
    }

    /* Get the game's title */
    private string getGameTitle()
    {
        var logic = JSON.Parse(jsonString);
        return logic["game_core"]["title"];
    }
    /* Get the game's developer */
    private string getGameDeveloper()
    {
        var logic = JSON.Parse(jsonString);
        return logic["game_core"]["developer"];
    }
    /* Get the game's disabled input text */
    private string getInputDisabledText()
    {
        var logic = JSON.Parse(jsonString);
        return logic["game_core"]["input_disabled"];
    }

    /* Handle response of action */
    private void handleUserInput()
    {
        parseInput();
        GameObject.Find("User_Input").GetComponent<InputField>().ActivateInputField();
    }

    /* Handle response of action */
    private void parseInput()
    {
        var logic = JSON.Parse(jsonString);

        string userInput = User_Input.text;
        User_Input.text = "";

        // Work out input prefix
        inputAction = "";
        for (int i = 0; i < getNumberOfActionTypes(); i++)
        {
            string testPrefix = getActionText(i);
            if (testPrefix.Length <= userInput.Length)
            {
                if (userInput.Substring(0, testPrefix.Length).ToUpper() == testPrefix)
                {
                    if (inputAction.Length < testPrefix.Length)
                    {
                        inputAction = testPrefix;
                    }
                }
            }
        }

        // Work out input subject
        inputSubject = "*";
        int prefixTrim = (userInput.Length - inputAction.Length) - 1;
        if (prefixTrim > 0)
        {
            inputSubject = userInput.Substring(inputAction.Length + 1, prefixTrim).ToUpper();
        }

        // Check for validity
        var logicBranch = logic[current_level.ToString()][current_zone.ToString()][current_state.ToString()][inputAction][inputSubject];
        if (logicBranch.AsObject.Count == 0)
        {
            Game_Response_Text.text = getInvalidInputResponse();
            inputIsValid = false;
        }
        else
        {
            // Check matched prefix for referenced script
            var referenced = logicBranch["referenced"];
            if (referenced.AsArray.Count != 0)
            {
                inputAction = referenced[0];
                inputSubject = referenced[1];
            }
            logicBranch = logic[current_level.ToString()][current_zone.ToString()][current_state.ToString()][inputAction][inputSubject];

            //If valid input action, act on it
            if (logicBranch.AsObject.Count == 0)
            {
                inputIsValid = false;
            }
            else
            {
                inputIsValid = true;
                Game_Response_Text.text = logicBranch["system_reply_ok"]; //TEMP ONLY
                performCurrentAction();
            }
        }
    }

    /* Show the game intro text */
    private string getZoneIntro()
    {
        var logic = JSON.Parse(jsonString);
        return logic[current_level.ToString()][current_zone.ToString()][current_state.ToString()]["zone_intro"];
    }

    /* Get the text to respond to an invalid input with */
    private string getInvalidInputResponse()
    {
        var logic = JSON.Parse(jsonString);
        return logic["game_core"]["invalid_input"];
    }
    /* Get the text to respond to an invalid input with */
    private string getErrorResponse()
    {
        var logic = JSON.Parse(jsonString);
        return logic["game_core"]["fatal_error"];
    }
    /* Get the number of prefixes available in the game */
    private int getNumberOfActionTypes()
    {
        var logic = JSON.Parse(jsonString);
        return logic["game_core"]["prefixes"].AsArray.Count;
    }
    /* Get the input text for an action */
    private string getActionText(int index)
    {
        var logic = JSON.Parse(jsonString);
        return logic["game_core"]["prefixes"][index];
    }

    /* Perform action when we are permitted to do so */
    private void performCurrentAction()
    {
        var logic = JSON.Parse(jsonString);
        var actionLogic = logic[current_level.ToString()][current_zone.ToString()][current_state.ToString()][inputAction][inputSubject];

        if (actionLogic["new_state"].IsString)
        {
            moveToState(actionLogic["new_state"]);
        }
        if (actionLogic["new_zone"].IsString)
        {
            moveToZone(actionLogic["new_zone"]);
        }
        if (actionLogic["new_level"].IsString)
        {
            moveToLevel(actionLogic["new_level"]);
        }
        if (actionLogic["game_over"].IsString)
        {
            gameOver(actionLogic["game_over"]);
        }
    }


    /* GAMEDATA HERE */


    /* Find zone by name and move to it */
    private void moveToState(string name)
    {
        current_state = findStateByName(name);
        Zone_Intro_Text.text = getZoneIntro();
    }
    /* Find zone by name and move to it */
    private void moveToZone(string name)
    {
        current_zone = findZoneByName(name);
        current_state = 0;
        Zone_Intro_Text.text = getZoneIntro();
    }
    /* Find zone by name and move to it */
    private void moveToLevel(string name)
    {
        current_level = findLevelByName(name);
        current_zone = 0;
        current_state = 0;
        Zone_Intro_Text.text = getZoneIntro();
    }
    
    /* Game over (won/lost?) */
    private void gameOver(string winState)
    {
        if (winState == "WIN")
        {
            //WIP
        }
        else if (winState == "LOSE")
        {
            //WIP
        }
    }

    /* Find state ID by name in current zone */
    private int findStateByName(string name)
    {
        var logic = JSON.Parse(jsonString);
        for (int i = 0; i < statesInThisZone(current_level, current_zone); i++)
        {
            if (logic[current_level.ToString()][current_zone.ToString()][i.ToString()]["level_name"]["state_name"] == name)
            {
                return i;
            }
        }
        return 99;
    }
    /* Find zone ID by name in current level */
    private int findZoneByName(string name)
    {
        var logic = JSON.Parse(jsonString);
        for (int i = 0; i < zonesInThisLevel(current_level); i++)
        {
            if (logic[current_level.ToString()][i.ToString()]["zone_name"] == name)
            {
                return i;
            }
        }
        return 99;
    }
    /* Find level ID by name */
    private int findLevelByName(string name)
    {
        var logic = JSON.Parse(jsonString);
        for (int i = 0; i < levelsInThisGame(); i++)
        {
            if (logic[i.ToString()]["level_name"] == name)
            {
                return i;
            }
        }
        return 99;
    }
}