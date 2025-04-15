using UnityEngine;
using System.IO.Ports;
using System.Collections.Generic;
using System;

// Class providing all necessary functions to communicate with the Arduino. 
// MainController.cs orchestrates the calls to this class' functions.
public class SerialCommunication : MonoBehaviour
{
    public SerialPort port;

    // note that acknowledgments are received as string from Arduino,
    // while commands are sent as hex from Unity (commands are defined in MainController.cs)
    Dictionary<string, string> ackTable = new Dictionary<string, string>
    {
        { "Ack", "0x43"},
        { "Nack", "0x44"},
    };

    void Awake()
    {
        // init 'port' public variable with serial port communication 

        // set timeout

        // start communication
    }

    
    public string ReadFromArduino()
    {
        // read from the serial port and return message
    }

    // Used to send a command (but not wait). Returns true if all goes well, false otherwise.
    public bool WriteToArduino(byte msg)
    {
        // create buffer and initialise with 'msg' 
        
        // send buffer on serial port
    }

    // Used to send a command and wait for acknowledgement. Returns true if 'ACK' received.
    // Else, throws an Exception
    public bool WriteToArduinoAndWaitAck(byte command)
    {
        // write command to arduino

        // check for Acknowledgment
    }

    void OnApplicationQuit()
    {
        // frees the port in a clean way
    }
}
