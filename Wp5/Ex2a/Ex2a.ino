// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 5
// Exercise 2a
// Submission code: 103681 (provided by your TA-s)
const int tempSensor = A0;  // Analog input pin for temperature sensor
int red= 13; //LED
int orange= 12; //LED
int yellow= 11; //LED
int green= 10; //LED
int blue= 9; //LED
int celsius= 0; //initialising temp variable as 0
int previousTemp= 0; //stores old temperature

// Define temperature ranges for LED activation
const int tempRange1 = 0; // -40 to -1 degrees Celsius
const int tempRange2 = 30; // 0 to 30 degrees Celsius
const int tempRange3 = 60; // 31 to 60 degrees Celsius
const int tempRange4 = 100; // 61 to 100 degrees Celsius
//temp range 5 is >100
  
void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(tempSensor,INPUT);//temp sensor
  pinMode(red,OUTPUT);// all leds as output
  pinMode(orange,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT); 
  delay(2000); // Wait for 1 second-checked every one second  

}

void loop() {
  
  // Call function to check temperature every interval milliseconds
  //temperature in celsius  
  celsius = map(((analogRead(tempSensor)-200) ), 0, 1023, -40, 125);
  //celsius= analogRead(tempSensor);
  //celsius= analogRead(tempSensor);
  if(previousTemp!= celsius){
     previousTemp= celsius;
     turnOffAll();
     checkTemp(); 
     Serial.print("Temperature: ");
     Serial.println(celsius);
  }
  delay(1000); // Wait for 1 second-checked every one second  

} 

//change leds with temperature
void checkTemp(){
  
  //1 light on- less than 0
  if(celsius<tempRange1){blueLed();}
  //2 lights on- less than 30
  else if(celsius<=tempRange2){blueLed(); greenLed();}
  //3 lights on-less than 60
  else if(celsius<=tempRange3){ blueLed(); greenLed(); yellowLed();}
  //4 lights on- less than 100
  else if(celsius<=tempRange4){ blueLed(); greenLed(); yellowLed(); orangeLed();}
  //all lights on
  else{blueLed(); greenLed(); yellowLed(); orangeLed(); redLed();}   
}

//method to turn off all lights when interrupt called
void turnOffAll(){
digitalWrite(red, LOW);   
digitalWrite(orange, LOW);   
digitalWrite(yellow, LOW);   
digitalWrite(green, LOW);   
digitalWrite(blue, LOW);  
}

//methods to turn on lights
void redLed(){digitalWrite(red, HIGH);}
void orangeLed(){digitalWrite(orange, HIGH);}
void yellowLed(){digitalWrite(yellow, HIGH);}
void greenLed(){digitalWrite(green, HIGH);}
void blueLed(){digitalWrite(blue, HIGH);}
