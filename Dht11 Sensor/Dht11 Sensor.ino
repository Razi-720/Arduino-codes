#include <dht11.h>
#define DHT11PIN 4

dht11 DHT11;

int ledMax = 13; // Pin for the LED to indicate temperature is rises the maximum  threshold
int ledMin = 12; // Pin for the LED to indicate temperature has falls below minimum threshold

void  setup()
{
  Serial.begin(9600);
  pinMode(ledMax, OUTPUT);
  pinMode(ledMin, OUTPUT);
  dht.begin();
}

void loop()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  float temperature = dht.readTemperature();

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature  (C): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(2000);

    if (temperature < 25.0) { // Adjust the threshold as needed
    digitalWrite(ledMax, HIGH); // Turn on above threshold LED
    digitalWrite(ledMin, LOW);  // Turn off below threshold LED
  } 
  else if (temperature > 30.0) {
    digitalWrite(ledMax, LOW);  // Turn off above threshold LED
    digitalWrite(ledMin, HIGH); // Turn on below threshold LED
  }
  else {
    digitalWrite(ledMax, LOW);  // Turn off above threshold LED
    digitalWrite(ledMin, LOW);

}
