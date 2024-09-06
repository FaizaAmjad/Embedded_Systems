// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 3
// Exercise 2
// Submission code: 809093 (provided by your TA-s)
// C++ code
// constants
int red= 13; //LED
int yellow= 12; //LED
int green= 8; //LED
int tempSensor = A5; //TEMPsensor
int lightSensor = A4; //TEMPsensor
int celsius= 0; //variable initialised for noting temp
int lightInt= 0; //variable initialising light intensity percentage
int lightPer=0; //initialising light intensity percenatge for comparison

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(tempSensor, INPUT);//temp sensor as input
  pinMode(lightSensor, INPUT);//light sensor as input
  Serial.begin(9600);
}

void loop()
{
  //(analogRead(tempSensor) - 30) * 3.04: This subtracts 30 from the analog reading to account for any offset 
  //and then multiplies the result by 3.04. This step likely adjusts the raw sensor value to a more suitable range
  //for mapping to Celsius temperature values.
  //long map(long x, long in_min, long in_max, long out_min, long out_max); in= input value, out= output values
  //reads temperature
  celsius = map(((analogRead(tempSensor) - 30) * 3.04), 0, 1023, -40, 125);
  //reads light intensity
  //my sensor ranges from 4- 448 so making them within the percentage range
  lightInt= analogRead(lightSensor);//value from sensor
  //percentage of light intensity
  lightPer = map(analogRead(lightSensor), 4, 448, 0, 100);
  Serial.print("TEMP: ");
  Serial.print(celsius);//prints temperature
  Serial.print(" Light percentage ");
  Serial.print(lightPer);//prints light intensity
  Serial.print("\n");


  if(lightPer==0){
    //normal condition 1
    if(celsius<-12 ){turnOnGreen();}
    else{turnOnRed();} //temperature is higher for intensity
  }
  
  else if(lightPer>=1 && lightPer<=20 ){
    //normal condition 2
    if((celsius>=-12 && celsius<=0)){turnOnGreen();}
    else if(celsius<-12){turnOnYellow();}//too low temp for this intensity
    else{turnOnRed();}//too high temp 
  }  

  else if(lightPer>=21 && lightPer<=60 ){
    //normal condition 3
    if(celsius>=0 && celsius<=20){turnOnGreen();}
    else if(celsius<0){turnOnYellow();}//too low temp for this intensity
    else{turnOnRed();}//too high temp
  }
  
  else if(lightPer>=61 && lightPer<=100){
    //normal condition 4
    if((celsius>=21)){turnOnGreen();}
    else{turnOnYellow();}//too low temp for this intensity   
  }
 
  delay(500); // Repeats every 5 millisecond
}
    
    void turnOnGreen(){
     digitalWrite(red, LOW);//turn off led
     digitalWrite(yellow, LOW);//turn off led 
     digitalWrite(green, HIGH);//turn on led 
    }    
    
    void turnOnRed(){
    digitalWrite(green, LOW);//turn off led
    digitalWrite(yellow, LOW);//turn off led 
    digitalWrite(red, HIGH);//turn on led
    }    
    
    void turnOnYellow(){
     digitalWrite(green, LOW);//turn off led
     digitalWrite(red, LOW);//turn off led 
     digitalWrite(yellow, HIGH);//turn on led
    }   