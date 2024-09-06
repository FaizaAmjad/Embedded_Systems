// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 3
// Exercise 3b
// Submission code: 809093 (provided by your TA-s)
// Define constants for pin connections
#define ROWS 4    // Number of rows in the keyboard
#define COLS 4    // Number of columns in the keyboard

// Define the key mapping matrix
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the pin numbers for the rows and columns
int rowPins[ROWS] = {11, 10, 9, 8};    // Connect these to the row pins of the keyboard
int colPins[COLS] = {7, 6, 5, 4};    // Connect these to the column pins of the keyboard

void setup() {
  Serial.begin(9600);

  // Set up row pins as OUTPUT and drive them HIGH
  pinMode(rowPins[0], OUTPUT);
  pinMode(rowPins[1], OUTPUT);
  pinMode(rowPins[2], OUTPUT);
  pinMode(rowPins[3], OUTPUT);
  digitalWrite(rowPins[0], HIGH);
  digitalWrite(rowPins[1], HIGH);
  digitalWrite(rowPins[2], HIGH);
  digitalWrite(rowPins[3], HIGH);

  // Set up column pins as INPUT with internal pull-up resistors
  pinMode(colPins[0], INPUT_PULLUP);
  pinMode(colPins[1], INPUT_PULLUP);
  pinMode(colPins[2], INPUT_PULLUP);
  pinMode(colPins[3], INPUT_PULLUP);
}

void loop() {
  // Iterate through each row
  for (int row = 0; row < ROWS; row++) {
    // Drive the current row LOW and check if it's pressed
    digitalWrite(rowPins[row], LOW);

    // Iterate through each column
    for (int col = 0; col < COLS; col++) {
      // Check if the current column is LOW (button pressed)
      if (digitalRead(colPins[col]) == LOW) {
        // Get the pressed key from the keys matrix
        char pressedKey = keys[row][col];

        // Print the pressed key
        Serial.println(pressedKey);

        // Delay to avoid rapid key detection due to button debounce
        delay(100);
      }
    }

    // Drive the current row HIGH again
    digitalWrite(rowPins[row], HIGH);
  }

  // Delay for one second before checking for keys again
  delay(100);
}

