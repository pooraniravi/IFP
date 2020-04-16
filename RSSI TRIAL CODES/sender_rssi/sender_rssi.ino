#include <XBee.h>

XBee xbee = XBee();

uint8_t payload[] = { 'H', 'i' };

XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x403e0f30);

Tx16Request tx16 = Tx16Request(addr64, payload, sizeof(payload));

void setup()
{
    Xbee.begin(9600);
    Serial.begin(9600);
}

void loop()
{
    xbee.send( tx16 );
    delay(50);
}
