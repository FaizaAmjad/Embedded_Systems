// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 6
// Exercise 3
// Submission code: BPA0HX (provided by your TA-s)


#include <Smartcar.h>

ArduinoRuntime arduinoRuntime;
BrushedMotor leftMotor(arduinoRuntime, smartcarlib::pins::v2::leftMotorPins);
BrushedMotor rightMotor(arduinoRuntime, smartcarlib::pins::v2::rightMotorPins);
DifferentialControl control(leftMotor, rightMotor);

#define triggerPin 2
#define echoPin 4
const unsigned int maxDistance = 150;  // Maximum distance for parking radar
const unsigned int minDistance = 20;   // Minimum distance for parking radar
//const auto pulsesPerMeter = 600;

const unsigned int carSpeed = -30;
// Define LED pin
#define redPin 19
#define yellowPin 3
#define bluePin 1
#define greenPin 23

#define buzzerPin 16

int range1= 50; //100-150 safe
int range2= 100;// 50-99 little safe

// Ultrasonic
SR04 rear{arduinoRuntime, triggerPin, echoPin, maxDistance};  // Rename the sensor for the rear side

SimpleCar car(control);

void carParking();
void mapSpeed(int distance);
void checkDistance(int distance);
void turnOffAll();
void redOn();
void yellowOn();
void blueOn();
void greenOn();

void setup()
{
    Serial.begin(9600);
     // Initialize LEDs
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    pinMode(buzzerPin, OUTPUT);
    car.setSpeed(carSpeed);
    delay(1000);

}

// Detects obstacles within distance range and implements parking radar
void checkDistance()
{
    turnOffAll();
    const auto distance = rear.getDistance();
    mapSpeed(distance);
    turnOnLeds(distance);
    sound(distance);
    delay(500);
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println();
}

void mapSpeed(int distance){
  //Gradually decrease speed based on the distance to the obstacle
  if(distance > 0 && distance < minDistance){
    car.setSpeed(0);
  }else if (distance > 0 && distance < range1){
    car.setSpeed(5);
  }else if (distance > 0 && distance < range2){
    car.setSpeed(10);
  }else if (distance > 0 && distance < maxDistance){
    car.setSpeed(20);
  }else {
    car.setSpeed(30);
  }
}


void turnOnLeds(int distance){
  
  if(distance > 0 && distance < minDistance){
      //very dangerous less than 20
      redOn();
      yellowOn();
      blueOn();
      greenOn();
  } else if(distance > 0 && distance < range1){
      //under 50 dangerous
      yellowOn();
      blueOn();
      greenOn();
  } else if(distance > 0 && distance < range2){
      //under 100 ok
      blueOn();
      greenOn();
  } else if( distance > 0 && distance < maxDistance){
      //under 150
      greenOn();
  }
}

void turnOffAll(){
  digitalWrite(redPin,LOW);
  digitalWrite(yellowPin,LOW);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,LOW);
}

void redOn(){  digitalWrite(redPin,HIGH);}
void yellowOn(){  digitalWrite(yellowPin,HIGH);}
void blueOn(){  digitalWrite(bluePin,HIGH);}
void greenOn(){  digitalWrite(greenPin,HIGH);}

void sound(int distance){
  if(distance > 0 && distance < minDistance){
    tone(buzzerPin,1000);
  }else if (distance > 0 && distance < range1){
    tone(buzzerPin,400);
  }else if (distance > 0 && distance < range2){
    tone(buzzerPin,200);
  }else if (distance > 0 && distance < maxDistance){
    tone(buzzerPin,100);
  }else {
    noTone(buzzerPin);
  }
}

void loop()
{
    checkDistance();
}
