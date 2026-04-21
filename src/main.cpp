#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme; // Sử dụng I2C

void setup()
{
    Serial.begin(115200);

    // Khởi tạo I2C trên chân 21 (SDA) và 22 (SCL)
    if (!bme.begin(0x76))
    {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1)
            ;
    }

    Serial.println("-- BME280 Read Test --");
}

void loop()
{
    float temp = bme.readTemperature();
    float hum = bme.readHumidity();

    // In ra Serial Monitor
    Serial.printf("Nhiet do: %.2f *C | Do am: %.2f %%\n", temp, hum);

    delay(2000); // Đợi 2 giây
}