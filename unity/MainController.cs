using System;
using System.Collections.Generic;
using UnityEngine;

// "Master" class which runs the system's logic
public class MainController : MonoBehaviour
{
    private SerialCommunication serialCommunication;
    private IdDetector idDetector;

    public float distanceThreshold = 50f; // person detected if value below 50cm
    public int fsrThreshold = 3000; // FSR value is between 0 and 4095
    private bool isScanning = false;
    private bool isIdentified = false;

    // List of commands
    Dictionary<string, byte> commandTable = new Dictionary<string, byte> {
        { "Init", 0x45},
        { "OpenEye", 0x46},
        { "CloseEye", 0x47},
        { "OpenDoor", 0x48},
        { "CloseDoor", 0x49},
        { "LockDoor", 0x4A}, // cut the stepper motor's power (relay -- not used)
        { "UnlockDoor", 0x4B},
        { "ReadDistance", 0x4C},
        { "ReadFSR", 0x4D},
        { "RedLedOn", 0x4E},
        { "RedLedOff", 0x4F},
        { "GreenLedOn", 0x50},
        { "GreenLedOff", 0x51},
        { "BlueLedOn", 0x52},
        { "BlueLedOff", 0x53}
    };

    // Init function for resetting the Arduino
    void Start()
    {
        // init components
        
        // init arduino

        // subscribe to user identification event (complete later)
    }

    // Main loop for checking human presence continuously
    private void Update()
    {
        // read distance sensor at every frame
        
            // if presence detected, start ID card detection
            
            // if identification already running, do nothing (wait to happen)

            // if identification finished or the person walked away, stop ID process
    }

    // Read distance sensor for detecting human presence
    public float ReadDistance()
    {
        // ask distance to arduino
        
        // read answer, parse to float, and return
    }

    // Read pressure sensor for closing the door
    public int ReadFSR()
    {
        // ask FSR value to arduino
       
        // read answer, parse to int, and return
    }

    // Starts ID process by opening the eye lid, turning the LED to blue, and starting camera detection
    private void StartIdentificationSequence()
    {
            // turn LED to blue
            
            // start checking for identification event (complete later)
    }

    private void SetUserAsIdentified()
    {
        // update isIdentified flag value

        // (do not run code if event happens outside of identification sequence)
    }

    private void EndIdentificationSequence()
    {
        // if person is identified just now, turn LED to green

        // if person has gone through the door or left, turn LED back to red
    }
    

    private void OpenAndCloseDoor()
    {
        // if person is identified, open the door
        
        // wait for FSR sensor to be activated
        
        // close the door
    }
}
