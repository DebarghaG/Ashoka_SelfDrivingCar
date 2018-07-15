// This code will be controlling the angle at which the stepper motor is rotated to.

#include <Stepper.h> // Include the header file

// Change the number of STEPS_STEER to the final count of the motor being used.
#define STEPS_STEER 32
#define STEPS_ACC 32
#define STEPS_BRAKE 32

// Creating an instance of the stepper class.
Stepper stepper_steer(STEPS_STEER, 10, 9, 11);
// Change the port numbers for the stepper for the accelerator
Stepper stepper_acc(STEPS_ACC, 6 , 7 , 8 );
// Change the port numbers for the stepper for the brake
Stepper stepper_brake(STEPS_BRAKE, 3,4,5);

int val = 0;
int degree = 0;
int speed = 0;
int brake = 0;

void setup() {
  Serial.begin(9600);
  stepper_steer.setSpeed(200);
  stepper_acc.setSpeed(200);
  stepper_brake.setSpeed(200);
}

void loop() {

  if (Serial.available()>0)
  {
    val = Serial.parseInt();
    // This loop now deconstructs val to find the individual values of steer, speed and brake.
    for(int i=0; i<6: i++)
    {
      int rem = val% 10; // This is extracting the last digit value.
      if(i<2)
      {
        brake = brake+(rem*10)
      }
      else if( i<4 )
      {
        speed = speed+(rem*10)
      }
      else
      {
        steer = steer+(rem*10)
      }

      val = val / 10; //Removing the last digit.
    }
    // Can the computer passes this value to the arduino for the steering input.
    stepper_steer.step(val);
    stepper_acc.step(speed);
    stepper_brake.step(brake);

    //Flush the variables :
    steer = 0;
    speed = 0;
    brake = 0; 

    Serial.println(val); //for debugging
  }


}
