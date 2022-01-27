/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Dakota Leslie                                             */
/*    Created:      Sat Jan 30 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //Begings the autonomous movement of the bot and afterwards makes it sleep for 15 seconds
  autonomousPortion();
  task::sleep(5000);

  startUp();

    //int armMotorPos = 0;
    //int spinUnits = 0;
  
 while(true){
    drive();
    
    moveArm();
    CallSteve();

    StopSteve();

    task::sleep(20);
  }

  return 0;
}
