// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 4
// Exercise 2
// Submission code: 453182 (provided by your TA-s)


#include <Servo.h>

// declaring servo variables
Servo secondsServo; // initializing servo object
int servoPosition = 0; //initialising  to 0 the position in start

// timer variable to keep track of the seconds milli
unsigned long seconds = 0;

void setup()
{
    Serial.begin(9600);// set serial communication
    // attach servo to pin
    secondsServo.attach(9);
    // configure timer 0
    setup_timer0();
}

void setup_timer0()
{
    cli();      // disable interrupts
    TCCR0A = 0; // set entire TCCR0A register to 0
    TCCR0B = 0; // same for TCCR0B
    TCNT0 = 0;  // initialize counter value to 0

    OCR0A = 249;                         // (CLOCK_SPEED / (PRESCALER * INTERRUPT_FREQ)) - 1;
    TCCR0A |= (1 << WGM01);              // turn on CTC mode
    TCCR0B |= (1 << CS01) | (1 << CS00); // set CS01 and CS00 bits for 64 prescaler
    TIMSK0 |= (1 << OCIE0A);             // enable timer to compare interrupt
    sei();                               // enable interrupts
}

// use interrupts instead of loop
void loop(){}

// interrupt service routine for timer 0
ISR(TIMER0_COMPA_vect)
{
    cli();   // disable interrupts
    seconds++; // increments seconds
    // if 1000 ms have passed, update the servos
    if (seconds % 1000 == 0)
    {    //printing timer in seconds
        Serial.print("Timer: ");
        Serial.println((String)(seconds / 1000) + " seconds"); // print the time in seconds instead of milli
        servoPosition = ((seconds / 1000) % 60) * 3;           // calculate the angle for the seconds servo
        secondsServo.write(servoPosition);                  // write the angle to the servo
                      
    }
    sei(); // enable interrupts
}
