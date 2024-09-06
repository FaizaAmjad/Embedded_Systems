// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 6
// Exercise 2
// Submission code: BPA0HX (provided by your TA-s)
#include <Smartcar.h>

ArduinoRuntime arduinoRuntime;
BrushedMotor leftMotor(arduinoRuntime, smartcarlib::pins::v2::leftMotorPins);
BrushedMotor rightMotor(arduinoRuntime, smartcarlib::pins::v2::rightMotorPins);
DifferentialControl control(leftMotor, rightMotor);

SimpleCar car(control);

int angle = 0;

void setup()
{
    // Move forward for 1 seconds
    carGo();   
   delay(5000);
    // Start turning sharp left
    turn(-90);
    delay(5000);
    // Straighten the car and move
    turn(0);    // Move forward for 1 seconds
    carGo();   
    delay(5000);
    // Start turning sharp left
    turn(-90);
    delay(5000);
    // Straighten the car and move
    turn(0);
    // Move forward for 1 seconds
    carGo();   
    delay(5000);
    // Start turning sharp left
    turn(-90);
    delay(5000);
    // Straighten the car and move
    turn(0);
    // Move forward for 1 seconds
    carGo();
    delay(5000);
    car.setSpeed(0);
}

void loop() {

  
}

void carGo(){
 car.setSpeed(30);

}

void turn(int a){
  car.setAngle(a);
}
