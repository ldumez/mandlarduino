#include "link.h"
#include "Arduino.h"
#include "common.h"

char Link::read()
{
    while (!Serial.available());
    return Serial.read();
}

//=============
// Over load of the send function to be able the send float, int, or char buffer
void Link::send(char* cmd)
{   
    // Use print and not write because we want to send printable characters with end of line
    Serial.println(cmd);
}

void Link::send(float val)
{   
    // Use print and not write because we want to send printable characters with end of line
    Serial.println(val);
}

void Link::send(int val)
{   
    // Use print and not write because we want to send printable characters with end of line
    Serial.println(val);
}
//==============

void Link::sendAck()
{
    send(ACK);
}

void Link::sendNack()
{
    send(NACK);
}