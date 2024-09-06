// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 5
// Exercise 1
// Submission code: 103681 (provided by your TA-s)
// C++ code
// Define LED and button connections
const byte ledPin1 = 13;
const byte ledPin2 = 10;
const byte buttonPin = 2;
 
// volatile Boolean to represent toggle state
// global volatile variable for interrupts
volatile bool toggleState = false;

// Check status of button
// Toggle LED if button pressed 
void checkButton() 
{
  // If button is pressed 
  if (digitalRead(buttonPin) == LOW) {
    // Change state of toggle
    toggleState = !toggleState;
    // Indicate state on LED
    digitalWrite(ledPin2, toggleState);
    Serial.print("Button Running!");
  }
}

void setup()
{
  //Set LEDs as output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  //Set button pin as INPUT with pullup
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  // Attach Interrupt to Interrupt Service Routine
  attachInterrupt(digitalPinToInterrupt(buttonPin),checkButton, FALLING);
}

void loop()
{
  digitalWrite(ledPin1, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(ledPin1, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
