using System;
using UnityEngine;
using Vuforia;

// Uses Vuforia AR plugin to activate the webcam and search for a target image
public class IdDetector : MonoBehaviour
{
    public GameObject imageTarget; // vuforia-tracked image
    private ObserverBehaviour observer; // vuforia image tracking script

    public Action OnIdentification; // even that MainController.cs subscribes to to detect when a person is identified.

    private void Start()
    {
        // fetch ImageTargetBehavior component on our ImageTarget (inherits from ObserverBehaviour)
        
        // subscribe to Vuforia's detection (running from Play)
    }

    // Called when OnTargetStatusChanged event is raised
    private void UpdateTrackingStatus(ObserverBehaviour behaviour, TargetStatus status)
    {
        // if the image is detected and tracked, trigger OnIdentification event for MainController.cs to open the door

        // (go and edit MainController to handle that event after writing that)
    }
}
