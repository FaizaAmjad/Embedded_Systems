// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 3
// Exercise 4
// Submission code: 809093 (provided by your TA-s)
#include <Keypad.h>

// Define the number of rows and columns in the keypad
const byte ROWS = 4;
const byte COLS = 4;

// Define the key mapping matrix
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the pin numbers for rows and columns
byte rowPins[ROWS] = {11, 10, 9, 8};  // Connect these to the row pins of the keypad
byte colPins[COLS] = {7, 6, 5, 4};  // Connect these to the column pins of the keypad

// Create a Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Get the pressed key
  char pressedKey = keypad.getKey();

  // If a key is pressed, print its value
  if (pressedKey) {
    Serial.println(pressedKey);
  }

  // Delay for one second
  delay(100);
}
