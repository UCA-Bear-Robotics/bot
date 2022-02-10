using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern bumper GoalBumper;
extern motor goalGrabber;
extern motor eyeMotor;
extern motor ringScoop;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
void drive();
void callGrabber();
void callBackTeeth();
void liftBackTeeth();
void debug();