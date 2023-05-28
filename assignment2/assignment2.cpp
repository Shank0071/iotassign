#include <DHT.h>

#define DHTPIN D1         // GPIO pin where the DHT11 sensor is connected
#define DHTTYPE DHT11     // DHT sensor type

const int buzzerPin = D2; // GPIO pin where the buzzer is connected

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  dht.begin();
}

void loop() {
  delay(2000);  // Wait for 2 seconds between readings

  float temperature = dht.readTemperature();
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature > 35) {
    // Temperature exceeds 35 degrees Celsius, trigger the buzzer
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
  }
}
