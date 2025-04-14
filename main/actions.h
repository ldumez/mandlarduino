#ifndef ACTION_H
#define ACTION_H
#include <Stepper.h>
#include <ESP32Servo.h>

char* openDoor_action(Stepper *stepper);
char* closeDoor_action(Stepper *stepper);
char* lockDoor_action();
char* unlockDoor_action();
char* openEye_action(Servo *servo);
char* closeEye_action(Servo *servo);
char* ledRedOn_action();
char* ledRedOff_action();
char* ledGreenOn_action();
char* ledGreenOff_action();
char* ledBlueOn_action();
char* ledBlueOff_action();
int readFsr_action();
float readDistance_action();

#endif
