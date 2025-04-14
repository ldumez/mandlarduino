#ifndef COMMON_H
#define COMMON_H

// =============
// Configurations
// =============

// Stepper configuration
#define STEPPER_NB_STEPS        2048
#define STEPS                   512 // 90 deg
#define STEPPER_SPEED_RPM       15 

// Servo confifugration
#define EYE_CLOSE_DEG       0
#define EYE_OPEN_DEG        180


// =============
// Return ACK and NACK values
// =============

// Value to return to Unity must be string typed
#define ACK     "0x43" // C
#define NACK    "0x44" // D

// =============
// Commands recerived from Unity are hex typed
// =============

#define CMD_INIT            0x45 // E

#define CMD_OPEN_EYE        0x46 // F
#define CMD_CLOSE_EYE       0x47 // G

#define CMD_OPEN_DOOR       0x48 // H
#define CMD_CLOSE_DOOR      0x49 // I
#define CMD_LOCK_DOOR       0x4A // J
#define CMD_UNLOCK_DOOR     0x4B // K

#define CMD_READ_DISTANCE   0x4C // L
#define CMD_READ_FSR        0x4D // M

#define CMD_LED_RED_ON      0x4E // N
#define CMD_LED_RED_OFF     0x4F // O

#define CMD_LED_GREEN_ON    0x50 // P
#define CMD_LED_GREEN_OFF   0x51 // Q

#define CMD_LED_BLUE_ON     0x52 // R
#define CMD_LED_BLUE_OFF    0x53 // S

// =============
// Pin Value
// =============

// Distance sensor gpio pins
#define TRIGGER_PIN         20
#define ECHO_PIN            22

// FSR Analog pin
#define FSR_PIN             A2

// LED gpio pins
#define LED_RED_PIN         32
#define LED_GREEN_PIN       15
#define LED_BLUE_PIN        33

// Stepper motor gpio pins
#define RELAY_PIN           14
#define STEPPER_IN1_PIN     27
#define STEPPER_IN2_PIN     13 // Hardware issue Pin IN2 and IN3 are inverted on the stepper control board
#define STEPPER_IN3_PIN     12 
#define STEPPER_IN4_PIN     4 // Pin A5

// Servo motor PWM pins (Look at the doc to find PWN capable pins)
// https://lastminuteengineers.com/wp-content/uploads/iot/ESP32-PWM-Pins.png
// https://cdn-learn.adafruit.com/assets/assets/000/123/406/original/adafruit_products_Adafruit_ESP32_Feather_V2_Pinout.png?1691707257
#define SERVO_PIN           25 // Pin A1


#endif