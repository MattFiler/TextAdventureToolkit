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

    // Audio
    public AudioClip key0;
    public AudioClip key1;
    public AudioClip key2;
    public AudioClip key3;
    public AudioClip key4;
    public AudioClip key5;
    public AudioClip key6;
    public AudioClip key7;
    public AudioClip key8;
    public AudioClip key9;

    /*
    -------
    PRIVATE
    -------
    */

    // Game UI Outputs
    string Zone_Intro_Text_Queued = "";
    string Game_Response_Text_Queued = "";

    // Game Progress Logs
    int currentLevel = 0;
    int currentZone = 0;
    int currentState = 0;

    // Animation Instances
    ANIMATION ZoneIntroAnim = new ANIMATION();
    ANIMATION GameResponseAnim = new ANIMATION();

    // GameData
    List<string> gameData = new List<string>();
    enum gameDataType { REQUIRED_DATA, OPTIONAL_DATA, DATA_DOES_NOT_EXIST, DATA_EXISTS, DATA_IS_NOT_SPECIFIED }

    // Audio
    AudioSource audioSource;

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
        Zone_Intro_Text_Queued = getZoneIntro();

        audioSource = GetComponent<AudioSource>();
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
        var logic = JSON.Parse(jsonString);

        var logicBranch = parseInput();
        if (inputIsValid)
        {
            gameDataType requiredData = gameDataExistsForCurrentAction("required");
            gameDataType optionalData = gameDataExistsForCurrentAction("optional");

            if (requiredData != gameDataType.DATA_DOES_NOT_EXIST && optionalData != gameDataType.DATA_DOES_NOT_EXIST)
            {
                if (logicBranch["system_reply_ok"].IsString)
                {
                    Game_Response_Text_Queued = logicBranch["system_reply_ok"];
                }
                else
                {
                    Game_Response_Text_Queued = getErrorResponse();
                }
            }
            else
            {
                if (logicBranch["system_reply_issue"].IsString)
                {
                    Game_Response_Text_Queued = logicBranch["system_reply_issue"];
                }
                else
                {
                    Game_Response_Text_Queued = getErrorResponse();
                }
            }

            if (requiredData != gameDataType.DATA_DOES_NOT_EXIST)
            {
                performCurrentAction();
                handleGameData();
            }
        }

        User_Input.ActivateInputField();
    }

    /* Handle response of action */
    private JSONNode parseInput()
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
        inputIsValid = false;
        var logicBranch = logic[currentLevel.ToString()][currentZone.ToString()][currentState.ToString()][inputAction][inputSubject];
        if (logicBranch.AsObject.Count == 0)
        {
            Game_Response_Text_Queued = getInvalidInputResponse();
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
            logicBranch = logic[currentLevel.ToString()][currentZone.ToString()][currentState.ToString()][inputAction][inputSubject];

            //If valid input action, act on it
            if (logicBranch.AsObject.Count != 0)
            {
                inputIsValid = true;
            }
        }
        Debug.Log(inputAction);
        Debug.Log(inputSubject);
        return logicBranch;
    }

    /* Show the game intro text */
    private string getZoneIntro()
    {
        var logic = JSON.Parse(jsonString);
        return logic[currentLevel.ToString()][currentZone.ToString()][currentState.ToString()]["zone_intro"];
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
        var actionLogic = logic[currentLevel.ToString()][currentZone.ToString()][currentState.ToString()][inputAction][inputSubject];

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

    /* Add/remove items to game memory when requested */
    private void handleGameData()
    {
        var logic = JSON.Parse(jsonString);

        var currentGameDataAdd = logic[currentLevel.ToString()][currentZone.ToString()][currentState.ToString()][inputAction][inputSubject]["add_gamedata"];
        var currentGameDataRemove = logic[currentLevel.ToString()][currentZone.ToString()][currentState.ToString()][inputAction][inputSubject]["remove_gamedata"];

        if (currentGameDataAdd.IsArray)
        {
            gameDataAction(currentGameDataAdd, true);
        }
        if (currentGameDataRemove.IsArray)
        {
            gameDataAction(currentGameDataRemove, false);
        }
    }
    private void gameDataAction(JSONNode currentGameData, bool shouldAdd)
    {
        foreach (var thisData in currentGameData)
        {
            if (isItemInGameData(thisData.ToString()))
            {
                if (!shouldAdd)
                {
                    gameData.Remove(thisData.ToString());
                }
            }
            else
            {
                if (shouldAdd)
                {
                    gameData.Add(thisData.ToString());
                }
            }
        }
    }

    /* Check if an item is in the game memory */
    private bool isItemInGameData(string item)
    {
        foreach (string data in gameData)
        {
            if (data == item)
            {
                return true;
            }
        }
        return false;
    }

    /* Check required/optional items for action are in memory */
    private gameDataType gameDataExistsForCurrentAction(string gameDataType)
    {
        var logic = JSON.Parse(jsonString);
        var requestedGameData = logic[currentLevel.ToString()][currentZone.ToString()][currentState.ToString()][inputAction][inputSubject][gameDataType + "_gamedata"];

        if (requestedGameData.IsArray)
        {
            foreach (var reqData in requestedGameData)
            {
                if (isItemInGameData(reqData.ToString()))
                {
                    return TextAdventureGame.gameDataType.DATA_EXISTS;
                }
            }
        }
        else
        {
            return TextAdventureGame.gameDataType.DATA_IS_NOT_SPECIFIED;
        }
        return TextAdventureGame.gameDataType.DATA_DOES_NOT_EXIST;
    }

    /* Find zone by name and move to it */
    private void moveToState(string name)
    {
        currentState = findStateByName(name);
        Zone_Intro_Text_Queued = getZoneIntro();
    }
    /* Find zone by name and move to it */
    private void moveToZone(string name)
    {
        currentZone = findZoneByName(name);
        currentState = 0;
        Zone_Intro_Text_Queued = getZoneIntro();
    }
    /* Find zone by name and move to it */
    private void moveToLevel(string name)
    {
        currentLevel = findLevelByName(name);
        currentZone = 0;
        currentState = 0;
        Zone_Intro_Text_Queued = getZoneIntro();
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
        Application.Quit();
    }

    /* Find state ID by name in current zone */
    private int findStateByName(string name)
    {
        var logic = JSON.Parse(jsonString);
        for (int i = 0; i < statesInThisZone(currentLevel, currentZone); i++)
        {
            if (logic[currentLevel.ToString()][currentZone.ToString()][i.ToString()]["level_name"]["state_name"] == name)
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
        for (int i = 0; i < zonesInThisLevel(currentLevel); i++)
        {
            if (logic[currentLevel.ToString()][i.ToString()]["zone_name"] == name)
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

    /* Per-frame Update */
    void Update()
    {
        /* Animate Text */
        Zone_Intro_Text.text = ZoneIntroAnim.animateText(Zone_Intro_Text_Queued, Zone_Intro_Text.text);
        Game_Response_Text.text = GameResponseAnim.animateText(Game_Response_Text_Queued, Game_Response_Text.text);

        if (!ZoneIntroAnim.didFinishAnimation() || !GameResponseAnim.didFinishAnimation())
        {
            User_Input.text = getInputDisabledText();
            User_Input.enabled = false;
        }
        else
        {
            User_Input.enabled = true;
            if (User_Input.text == getInputDisabledText())
            {
                User_Input.text = "";
            }
        }

        /* Key SFX */
        if (Input.anyKeyDown)
        {
            int randomKeySound = Random.Range(0, 9);
            switch (randomKeySound)
            {
                case 0:
                    audioSource.PlayOneShot(key0);
                    break;
                case 1:
                    audioSource.PlayOneShot(key1);
                    break;
                case 2:
                    audioSource.PlayOneShot(key2);
                    break;
                case 3:
                    audioSource.PlayOneShot(key3);
                    break;
                case 4:
                    audioSource.PlayOneShot(key4);
                    break;
                case 5:
                    audioSource.PlayOneShot(key5);
                    break;
                case 6:
                    audioSource.PlayOneShot(key6);
                    break;
                case 7:
                    audioSource.PlayOneShot(key7);
                    break;
                case 8:
                    audioSource.PlayOneShot(key8);
                    break;
                default:
                    audioSource.PlayOneShot(key9);
                    break;
            }
        }
    }
}

class ANIMATION
{
    float timePreviouslyAnimated = 0.0f;
    bool didFinish = false;

    public string animateText(string originalText, string outputText)
    {
        if (timePreviouslyAnimated + 0.01 < Time.time)
        {
            if (originalText != outputText)
            {
                if (didFinish)
                {
                    outputText = "";
                    didFinish = false;
                }
                else
                {
                    if (originalText.Substring(0, outputText.Length) == outputText)
                    {
                        outputText = originalText.Substring(0, outputText.Length + 1);
                        timePreviouslyAnimated = Time.time;
                    }
                }
            }
            else
            {
                didFinish = true;
            }
        }
        return outputText;
    }

    public bool didFinishAnimation()
    {
        return didFinish;
    }
}