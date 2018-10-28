#include <Arduino.h>

#include "DHT.h"

#define LED 3
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
  //pinMode(SENSOR, INPUT_PULLUP);
  Serial.begin(9600);
  delay(1000);
  dht.begin();
}

void loop() {    
    // Wait a few seconds between measurements.
    delay(2000);
    digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
    
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = dht.readTemperature(true);
  
    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
  
    // Compute heat index in Fahrenheit (the default)
    float hif = dht.computeHeatIndex(f, h);
    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);
  
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F\t");
    Serial.print("Heat index: ");
    Serial.print(hic);
    Serial.print(" *C ");
    Serial.print(hif);
    Serial.println(" *F");

    digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)
    
    /*
    delay(100);

    pinMode(SENSOR, OUTPUT);
    //DDRD = DDRD | 0x04;
    digitalWrite(SENSOR, LOW);  // Start sample
    //PORTD = PORTD & 0xFB;
    delay(20);  // min 18ms or 500 us according to different doc
    //PORTD = PORTD | 0x04;
    //DDRD = DDRD & 0xFB;
    digitalWrite(SENSOR, HIGH);
    delayMicroseconds(40);
    pinMode(SENSOR, INPUT_PULLUP);
    delayMicroseconds(10);
    
    
    // Wait for response
    int s;
    int data[500];
    int cnt = 0;
    while(cnt<500) {
        data[cnt] = PORTD & 0x04; //digitalRead(SENSOR);
        delayMicroseconds(10);
        cnt++;
    }
    cnt = 0;
    while(cnt<500) {
        Serial.print(data[cnt]);
        Serial.print(" ");
        cnt++;
    }
    */


    //while(true) {}
}


