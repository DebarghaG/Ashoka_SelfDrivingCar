// This code will be controlling the angle at which the stepper motor is rotated to.

#include <Stepper.h> // Include the header file

// Change the number of steps to the final count of the motor being used.
#define STEPS 32

// Creating an instance of the stepper class.
Stepper stepper(STEPS, 8, 10, 9, 11);

int val = 0;

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(200);
}

void loop() {

  if (Serial.available()>0)
  {
    val = Serial.parseInt();
    // Can the computer passes this value to the arduino for the steering input.
    stepper.step(val);
    
    Serial.println(val); //for debugging
  }


}
