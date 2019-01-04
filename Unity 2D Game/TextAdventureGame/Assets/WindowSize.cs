using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WindowSize : MonoBehaviour {
    //Now controlled by player settings, but will keep this anyways.
	void Start () {
        Screen.SetResolution(1024, 768, false);
    }
}
