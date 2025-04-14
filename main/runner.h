#ifndef RUNNER_H
#define RUNNER_H
#include "link.h"
#include <Stepper.h>
#include <ESP32Servo.h>

class Runner
{
    public:
        // Main loop of the program (for C++ code clarity the Arduino loop() function is not really used (only to start the runner))
        void run();
        // contructor 
        Runner();
    
    private:
        char* init();
        void initStepper();
        void initServo();
        void initLedRgb();
        void initDistance();
        void initFSR();

        // Link for the serial communication
        Link link;

        // pointer use to set a stepper
        Stepper *stepper;
        // point use to set a servo
        Servo *servo;
};

#endif