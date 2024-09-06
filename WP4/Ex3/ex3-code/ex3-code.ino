// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 4
// Exercise 3
// Submission code: 453182 (provided by your TA-s)

#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN 12   // Pin for NeoPixel ring
#define NUM_LEDS 12       // Number of LEDs in the NeoPixel ring
#define RED_LED 13        // Pin for the standard red LED

Adafruit_NeoPixel ring(NUM_LEDS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
//neo... are pixel type flags

int const tempSensor= A0;       // Analog input pin for the temperature sensor
int const speaker = 8;          //speaker pin
int celsius = 0;          // Variable to store temperature
int previousTemp = 0;     // Variable to store previous temperature

// Define temperature ranges for LED activation
const int tempRange1 = 0;    // -40 to -1 degrees Celsius
const int tempRange2 = 30;   // 0 to 30 degrees Celsius
const int tempRange3 = 60;   // 31 to 60 degrees Celsius
const int tempRange4 = 100;  // 61 to 100 degrees Celsius

  
void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(tempSensor, INPUT);  // Set temperature sensor pin as input
  pinMode(RED_LED, OUTPUT);  // Set red LED pin as output
  pinMode(speaker, OUTPUT);  // Set red LED pin as output
  pinMode(NEOPIXEL_PIN, OUTPUT);  // Set ring pin as output
  ring.begin();              // Initialize NeoPixel ring
  ring.show();               // Initialize all pixels to 'off'
}

void loop() {
  // Read temperature in Celsius  
  celsius = map(((analogRead(tempSensor) - 20) * 3.04), 0, 1023, -40, 125);
  
  // Check if temperature has changed
  if (previousTemp != celsius) {
    previousTemp = celsius;
    turnOffAll();   // Turn off all LEDs
    checkTemp();    // Update NeoPixel ring based on temperature
  }
  
  Serial.println(celsius);
  delay(1000); // Wait for 1 second
}

// Change NeoPixel ring LEDs based on temperature
void checkTemp() {
  // 1 LED on- less than 1
  if (celsius < tempRange1) {
    setColor(0, 0, 255, 1);  // Blue
  } 
  // 2 LEDs on- less than 31
  else if (celsius <= tempRange2) {
    setColor(0, 255, 0, 4);  // Green
  } 
  // 3 LEDs on-less than 61
  else if (celsius <= tempRange3) {
    setColor(255, 255, 0, 7);  // Yellow
  } 
  // 4 LEDs on-less than 101
  else if (celsius <= tempRange4) {
    setColor(255, 165, 0, 10);  // Orange
  } 
  // All LEDs on
  else {
      setColor(255, 0, 0, 12); // red
    digitalWrite(RED_LED, HIGH); // Turn on standard red LED
    digitalWrite(speaker, HIGH); // Turn on speaker

  }
}

// Method to turn off all LEDs
void turnOffAll() {
  ring.clear();        // Clear NeoPixel ring
  ring.show();         // Update NeoPixel ring
  digitalWrite(RED_LED, LOW); // Turn off standard red LED
  digitalWrite(speaker, LOW); // Turn off speaker
}

// Method to set color for NeoPixel at given position
void setColor(int red, int green, int blue, int leds) {
  for (int i = 0; i <= leds; i++) {
    ring.setPixelColor(i, ring.Color(red, green, blue)); // Set color for each LED
  }
  ring.show();  // Update NeoPixel ring
}
