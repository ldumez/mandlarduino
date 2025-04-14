#include "Arduino.h"
#include "actions.h"
#include "common.h"

char* openDoor_action(Stepper *stepper)
{
    // Control the stepper motor to move STEPS forward
	stepper->step(STEPS);
    return ACK;
}

char* closeDoor_action(Stepper *stepper)
{
    // Control the stepper motor to move STEPS backward (-STEPS)
    stepper->step(-STEPS); 
    return ACK;
}

char* lockDoor_action()
{
    // Turn OFF the relay of the stepper motor
    digitalWrite(RELAY_PIN, LOW);
    return ACK;
}

char* unlockDoor_action()
{
    // Turn ON the relay of the stepper motor
    digitalWrite(RELAY_PIN, HIGH);
    return ACK;
}

char* openEye_action(Servo *servo)
{
    // Control the servo motor to make the open actions

    // Read the actual position of the servo
    int pos = servo->read();
    
    // Move the servo from the actual position to the position wanted
    for (pos; pos <= EYE_OPEN_DEG; pos++) {
        servo->write(pos);   
        delay(2);
    }
    return ACK;
}

char* closeEye_action(Servo *servo)
{
    // Control the servo motor to make the open actions

    // Read the actual position of the servo
    int pos = servo->read();

    // Move the servo from the actual position to the position wanted
    for (pos; pos >= EYE_CLOSE_DEG; pos--) { 
        servo->write(pos);
		delay(2);              
	}
    return ACK;
}

char* ledRedOn_action()
{
    // Control the red led
    digitalWrite(LED_RED_PIN, LOW);
    return ACK;
}

char* ledRedOff_action()
{
    // Control the red led
    digitalWrite(LED_RED_PIN, HIGH);
    return ACK;
}

char* ledGreenOn_action()
{
    // Control the green led
    digitalWrite(LED_GREEN_PIN, LOW);
    return ACK;
}

char* ledGreenOff_action()
{
    // Control the green led
    digitalWrite(LED_GREEN_PIN, HIGH);
    return ACK;
}

char* ledBlueOn_action()
{
    // Control the blue led
    digitalWrite(LED_BLUE_PIN, LOW);
    return ACK;
}

char* ledBlueOff_action()
{
    // Control the blue led
    digitalWrite(LED_BLUE_PIN, HIGH);
    return ACK;
}

int readFsr_action()
{
    // Read tje FSR sensor and return the value as string
    return analogRead(FSR_PIN);
}

float readDistance_action()
{
    // Read the Distance sensor and return the value as string
    
    // Trigger a burst of ultrasound
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10); 
    digitalWrite(TRIGGER_PIN, LOW);

    // Get the result by getting the time ECHO_PIN is HIGH
    unsigned long pulse_delay = pulseIn(ECHO_PIN, HIGH);
    float dist = -1;
    if (pulse_delay)
    {
        // Speed of the sound (cm/us) * time of the pulse / 2
        dist = float(0.01715 * pulse_delay);
    }

    // Make sure the read distance is done max once every 60ms
    // to prevent noise
    delay(60);
    return dist;
}
