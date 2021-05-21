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
    // 3. We retrieve 2 bytes from the sensor on line 16, using the datasheet, why do we need to shift the first read 8 to the left and OR it with the second read?
    // 4. The datasheet mentions that the communication is MSB first, what would have to change here if it was LSB first instead?
    // 5. The result of the read is stored, with this value something can be confirmed. What's the purpose of doing this and with what value should this be compared to?
    // 6. This code uses so called "magic numbers", this is typically considered bad practice. How would you improve this?
    // 7. Can you explain in a couple sentences what this code does?
    // 8. Extra: On line 16 we don't need to perform 2 read instructions. Why not? What would the simplified code (and comparison) look like?
}

void loop() {}