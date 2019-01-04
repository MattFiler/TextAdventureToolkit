using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class InputUppercase : MonoBehaviour {

    public InputField User_Input;
	
	void Update () {
        if (User_Input.text != User_Input.text.ToUpper())
        {
            User_Input.text = User_Input.text.ToUpper();
        }
    }
}
