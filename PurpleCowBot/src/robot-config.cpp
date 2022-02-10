#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT18, ratio18_1, true);
motor leftMotorB = motor(PORT17, ratio18_1, true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT4, ratio18_1, false);
motor rightMotorB = motor(PORT5, ratio18_1, false);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
bumper GoalBumper = bumper(Brain.ThreeWirePort.A);
motor goalGrabber = motor(PORT19, ratio18_1, false);
motor eyeMotor = motor(PORT2, ratio18_1, false);
motor ringScoop = motor(PORT11, ratio18_1, false);
motor_group RingScooper = motor_group(ringScoop, eyeMotor);
controller Controller1 = controller();




void drive(){
  LeftDriveSmart.spin(reverse, (Controller1.Axis3.value() + Controller1.Axis4.value())/2, pct);
  RightDriveSmart.spin(reverse, (Controller1.Axis3.value() - Controller1.Axis4.value())/2, pct);
}

void callGrabber(){
  if(Controller1.ButtonR1.pressing()){
    RingScooper.spin(forward, 50, velocityUnits::pct);
  }else{
    RingScooper.stop();
  }
  
}

void callBackTeeth(){
  if(GoalBumper.pressing()){
    goalGrabber.spin(forward, 50, velocityUnits::pct);
  }
}

void liftBackTeeth(){
  if(Controller1.ButtonB.pressing()){
    goalGrabber.spinFor(reverse, 123, rotationUnits::deg, 35, velocityUnits::pct);
  }
}

void debug(){
  if(Controller1.ButtonR1.pressing()){
    RingScooper.spin(forward);
  }
}


// VEXcode generated functions


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
  goalGrabber.rotateFor(forward, 500, timeUnits::msec, 25, velocityUnits::pct);
  goalGrabber.rotateFor(reverse, 500, timeUnits::msec, 35, velocityUnits::pct);



}