using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
void autonomousPortion();
void startUp();
void drive();
int armUp();
int armDown();
void moveArm();
void SpinSteve();
void ReverseSteve();
void CallSteve();
void CancelSpin();
void StopSteve();