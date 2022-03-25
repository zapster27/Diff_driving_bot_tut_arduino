DualVNH5019MotorShield md;

extern float VLeft;
extern float VRight;

arc::PID<double> leftMotorPID(5.0,0.5,0.2);
arc::PID<double> rightMotorPID(5.0,0.5,0.2);

void stopIfFault()
{
  if (md.getM1Fault())
  {
    Serial.println("M1 fault");
    while (1);
  }
  if (md.getM2Fault())
  {
    Serial.println("M2 fault");
    while (1);
  }
}

void Driverinit()
{
  md.init();
}

unsigned char speedLeftSet = 0;

void SetSpeedLeft(float speedLeft) {
  leftMotorPID.setTarget(speedLeft);
  leftMotorPID.setInput(VLeft);
  speedLeftSet = min(255, max(0, speedLeftSet + leftMotorPID.getOutput()));
  md.setM1Speed(speedLeftSet);
}
unsigned char speedRightSet = 0;

void SetSpeedRight(float speedRight) {
  rightMotorPID.setTarget(speedRight);
  rightMotorPID.setInput(VRight);
  speedRightSet = min(255, max(0, speedRightSet + rightMotorPID.getOutput()));
  md.setM1Speed(speedRightSet);
}
