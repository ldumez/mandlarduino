#include "Runner.h"
#include "Actions.h"
#include "Link.h"
#include "Common.h"
#include "Arduino.h"

Runner::Runner()
{
    init();
}

char* Runner::init()
{
    // Initialisation can be call by Unity to reset the system
    initDistance();
    initFSR();
    initLedRgb();
    initServo();
    initStepper();
    return ACK;
}

void Runner::initStepper()
{
    // Relay setup, the system start with the relay ON
    pinMode(RELAY_PIN, OUTPUT);
    unlockDoor_action();

    // define the Stepper 
    stepper = new Stepper(  STEPPER_NB_STEPS, 
                            STEPPER_IN1_PIN, 
                            STEPPER_IN2_PIN, 
                            STEPPER_IN3_PIN, 
                            STEPPER_IN4_PIN
                         );
    stepper->setSpeed(STEPPER_SPEED_RPM);

}

void Runner::initServo()
{
    servo = new Servo;

    // define PWM to use the servo
    ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	servo->setPeriodHertz(50);    // standard 50 hz servo

	servo->attach(SERVO_PIN);
    servo->write(EYE_CLOSE_DEG); 
}

void Runner::initLedRgb()
{
    pinMode(LED_RED_PIN, OUTPUT);
	pinMode(LED_GREEN_PIN, OUTPUT);
	pinMode(LED_BLUE_PIN, OUTPUT);
    
    // Red must be ON at the system power up
    ledRedOn_action();
    ledGreenOff_action();
    ledBlueOff_action();
}

void Runner::initDistance()
{
    pinMode(TRIGGER_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
}

void Runner::initFSR()
{
    // Nothing to init
}

void Runner::run()
{
    char cmd_byte;
    while(1)
    {  
        // wait for a command
        cmd_byte = link.read();
        // analyse the command and execute the right function. 
        // Send the return of the function on the serial link.
        switch(cmd_byte)
        {
            case CMD_INIT:
                link.send(init());
                continue;
            case CMD_OPEN_EYE:
                link.send(openEye_action(servo));
                continue;
            case CMD_CLOSE_EYE:
                link.send(closeEye_action(servo));
                continue;
            case CMD_OPEN_DOOR:
                link.send(openDoor_action(stepper));
                continue;
            case CMD_CLOSE_DOOR:
                link.send(closeDoor_action(stepper));
                continue;
            case CMD_LOCK_DOOR:
                link.send(lockDoor_action());
                continue;           
            case CMD_UNLOCK_DOOR:
                link.send(unlockDoor_action());
                continue;
            case CMD_READ_DISTANCE:
                link.send(readDistance_action());
                continue;
            case CMD_READ_FSR:
                link.send(readFsr_action());
                continue;
            case CMD_LED_RED_ON:
                link.send(ledRedOn_action());
                continue;
            case CMD_LED_RED_OFF:
                link.send(ledRedOff_action());
                continue;
            case CMD_LED_GREEN_ON:
                link.send(ledGreenOn_action());
                continue;
            case CMD_LED_GREEN_OFF:
                link.send(ledGreenOff_action());
                continue;
            case CMD_LED_BLUE_ON:
                link.send(ledBlueOn_action());
                continue;
            case CMD_LED_BLUE_OFF:
                link.send(ledBlueOff_action());
                continue;
            default:
                // If the command is not implemented, return NACK
                link.sendNack();
                continue;
        }
    }
}