#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller();
motor LeftMotor(PORT1, ratio18_1, false);
motor RightMotor(PORT2, ratio18_1, true);
motor ArmMotor(PORT5, ratio18_1, false);
motor Steve(PORT8, ratio18_1, true);
//Put both left and right motor in a drivetrain so that they can move
//together at the same time
drivetrain Drivetrain = drivetrain(LeftMotor, RightMotor, 319.19, 295, 40, mm, 1);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}

void autonomousPortion(){
  Brain.Screen.print("Autonomous Mode");
  Controller1.Screen.print("Autonomous Mode");

  //".driveFor" takes the units of distance, distance type,
  //veloctiy units, and velocity type.
  Drivetrain.driveFor(-250, distanceUnits::cm, 50, velocityUnits::pct);
  

}


void startUp(){
  Brain.Screen.clearScreen();
  Brain.Screen.print("Arcade Mode: Drive Only");
  Controller1.Screen.print("Arcade Mode: Drive Only");
}

void drive(){
   LeftMotor.spin(reverse, (Controller1.Axis3.value() + Controller1.Axis4.value())/2, pct);
   RightMotor.spin(reverse, (Controller1.Axis3.value() - Controller1.Axis4.value())/2, pct);
  
}

int armUp(){
  int armMotorPos;

  ArmMotor.spin(forward, 40, pct);
  armMotorPos = ArmMotor.position(degrees);

  return armMotorPos;
}

int armDown(){
  int armMotorPos;

  ArmMotor.spin(reverse, 40, pct);
  armMotorPos = ArmMotor.position(degrees);

  if (ArmMotor.position(degrees) == 1){
    ArmMotor.spin(reverse, 40 - 39.5, pct);
  }

  return armMotorPos;
}

void moveArm(){
  int armMotorPos = 0;

  while(true){
    if (Controller1.ButtonR2.pressing()){
      armMotorPos = armUp();
    }
    else if(Controller1.ButtonR1.pressing()){
      armMotorPos = armDown();
    }
    else if(!Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing()){
      ArmMotor.rotateTo(armMotorPos, deg, 0, rpm);
      break;
    }
  }
}

void SpinSteve(){
  Steve.spin(reverse, 40, pct);
}

void ReverseSteve(){
  Steve.spin(forward, 40, pct);
}

void CallSteve(){
  Controller1.ButtonA.pressed(SpinSteve);
  Controller1.ButtonB.pressed(ReverseSteve);
}

void CancelSpin(){
  Steve.stop();
}

void StopSteve(){
  Controller1.ButtonX.pressed(CancelSpin);
}