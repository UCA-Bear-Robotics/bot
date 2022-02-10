/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\colby                                            */
/*    Created:      Sun Feb 06 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    18, 17, 4, 5    
// GoalBumper           bumper        A               
// goalGrabber          motor         19              
// eyeMotor             motor         2               
// ringScoop            motor         11              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  while (true){
    //debug();
    drive();
    callGrabber();
    callBackTeeth();
    liftBackTeeth();
  }
}
