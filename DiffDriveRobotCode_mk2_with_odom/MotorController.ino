#define kP 1
#define kD 1
#define kI 1
DualVNH5019MotorShield md;

extern float VLeft;
extern float VRight;

arc::PID<double> leftMotorPID(1.0, 0, 0);
arc::PID<double> rightMotorPID(1.0, 0, 0);

double errorLeft = 0, cumErrorLeft = 0, rateErrorLeft = 0;
float prevErrorLeft = 0;
float outLeft = 0;
unsigned long currTimeLeft = 0, prevTimeLeft = 0;
double speedLeftSet = 0;

double errorRight = 0, cumErrorRight = 0, rateErrorRight = 0;
float prevErrorRight = 0;
float outRight = 0;
unsigned long currTimeRight, prevTimeRight = 0;
double speedRightSet = 0;

void DriverInit() {
  md.init();
  Serial2.println("Motor Initialized");
  prevTimeLeft = millis()+500;
  prevTimeRight = millis()+500;
}



void SetSpeedLeft(float speedLeft) {
  currTimeLeft = millis();
  
  errorLeft = speedLeft - VLeft;
  Serial2.print("VLeft   "); Serial2.print(VLeft);
  cumErrorLeft += errorLeft * ((double)(currTimeLeft-prevTimeLeft));
  rateErrorLeft = (errorLeft - prevErrorLeft)/((double)(currTimeLeft-prevTimeLeft));
  
  outLeft = kP * errorLeft + kD * rateErrorLeft + kI * cumErrorLeft;
  
  prevErrorLeft = errorLeft;
  prevTimeLeft = currTimeLeft;

  speedLeftSet = (int)(min(400, abs(speedLeftSet + outLeft)));
  if(speedLeft < 0){
    speedLeftSet = (int)(min(400, abs(speedLeftSet + outLeft))) * -1;
  }
  
  
//  leftMotorPID.setTarget(speedLeft);
//  leftMotorPID.setInput(VLeft);
//  float PIDValLeft = leftMotorPID.getOutput();
//  speedLeftSet = min(400, max(0, abs(speedLeftSet + PIDValLeft)));
  Serial2.print("outLeft   "); Serial2.print(outLeft);
//  speedLeftSet = map(speedLeftSet, 0, 1, 0, 400) * (speedLeft / abs(speedLeft));
  Serial2.print("   speedLeftSet   "); Serial2.println(speedLeftSet);
  Serial2.println();
  md.setM2Speed(speedLeftSet);
  stopIfFault();
}


void SetSpeedRight(float speedRight) {
  currTimeRight = millis();
  
  errorRight = speedRight - VRight;
  cumErrorRight += errorRight * ((double)(currTimeRight-prevTimeRight));
  rateErrorRight = (errorRight - prevErrorRight)/((double)(currTimeRight-prevTimeRight));
  
  outRight = kP * errorRight + kD * rateErrorRight + kI * cumErrorRight;
  
  prevErrorRight = errorRight;
  prevTimeRight = currTimeRight;
  speedRightSet = (int)(min(400, abs(speedRightSet + outRight)));
  if(speedRight < 0){
    speedRightSet = (int)(min(400, abs(speedRightSet + outRight))) * -1;
  }
  

//  
//  rightMotorPID.setTarget(speedRight);
//  rightMotorPID.setInput(VRight);
//  float PIDValRight = rightMotorPID.getOutput();
//  speedRightSet = min(1, max(0, abs(speedRightSet + PIDValRight)));
  Serial2.print("outRight   "); Serial2.print(outRight);
//  speedRightSet = map(speedRightSet, 0, 1, 0, 400) * (speedRight / abs(speedRight));
  Serial2.print("   speedRightSet   "); Serial2.println(speedRightSet);
  Serial2.println();
  md.setM1Speed(speedRightSet);
  stopIfFault();
}

void stopIfFault() {
  if (md.getM1Fault()) {
    Serial.println("M1 fault");
    while (1);
  }
  if (md.getM2Fault()) {
    Serial.println("M2 fault");
    while (1);
  }
}
