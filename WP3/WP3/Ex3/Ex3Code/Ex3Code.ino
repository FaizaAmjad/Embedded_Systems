// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 3
// Exercise 3a
// Submission code: 809093 (provided by your TA-s)
const int analogInputPin = A0;  // Analog input pin for temperature sensor
const int multimeterPin = A0;  // Analog output pin for multimeter

void setup() {
  Serial.begin(9600);  // Initialize serial communication 
}
void loop() {
  // Read analog voltage from temperature sensor
  int sensorValue = analogRead(analogInputPin);

  // Calculate voltage with multiplying voltageRange 5.0
  // and dividing with analogMaxValue "1023"
  //
  float voltage = sensorValue * (5.0 / 1023);

  // Calculate temperature using the updated formula
  // Convert from 10mV per 500mV offset to degree celcius
  // ((Volatage- 500 mV)* 100)
  float temperature = (voltage - 0.5) * 100;
 
  // Print information to serial monitor
  Serial.print("\n Sensor value: ");
  Serial.print(sensorValue);
  Serial.print("\n Voltage: ");
  Serial.print(voltage, 2);
  Serial.println(" volts");
  Serial.print(" Temperature: ");
  Serial.print(temperature, 2);
  Serial.println(" °C");

  // Delay for 500ms
  delay(1000);
}

