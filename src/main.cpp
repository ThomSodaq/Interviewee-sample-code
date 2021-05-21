#include <Arduino.h>
#include "Wire.h"

void setup()
{
    SerialUSB.begin(115200);
    SerialUSB.println("Hello world!");
    delay(1000);
    // This code uses a TMP1075 temperature sensor
    // See https://www.ti.com/lit/ds/symlink/tmp1075.pdf?ts=1621504593287
    Wire.begin(0x48);
    Wire.beginTransmission(0x48);
    Wire.write(0x0F);
    Wire.endTransmission(false);
    Wire.requestFrom(0x48, 2, true);
    uint16_t result = Wire.read() << 8 | Wire.read();
    SerialUSB.print("I received ");
    SerialUSB.println(result, 16);
    // Some questions:
    // 1. What is the protocol used to communicate with the TMP1075 sensor?
    // 2. The code uses two specific values, 0x48 and 0x0F, what are they and what are they used for?
    // 3. The result is stored, with this result something can be confirmed. What's the purpose and with what value should this be compared to?
    // 4. This code uses so called "magic numbers", this is typically considered practice. How would you improve this?
    // 5. Can you explain in a couple sentences what this code does?
}

void loop() {}