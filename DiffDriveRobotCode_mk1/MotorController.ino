#define kPL 0.11
#define kDL 0
#define kIL 0.0001

#define kPR 0.11
#define kDR 0
#define kIR 0.00011

#define MINSPEED 30
#define MAXSPEED 400

DualVNH5019MotorShield md;

extern double VLeft;
extern double VRight;

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
  prevTimeLeft = millis() + 500;
  prevTimeRight = millis() + 500;
}



void SetSpeedLeft(float speedLeft) {
  currTimeLeft = millis();
  if (speedLeft == 0) {
    md.setM2Speed(0);
    speedLeftSet = 0;
    errorLeft = 0;
    cumErrorLeft = 0;
    rateErrorLeft = 0;
    outLeft = 0;
    
  } else {
    Serial2.print("speedLeft    "); Serial2.print(speedLeft);

    errorLeft = speedLeft - VLeft;
    Serial2.print("    VLeft    "); Serial2.print(VLeft);
    cumErrorLeft += errorLeft * ((double)(currTimeLeft - prevTimeLeft)/1000);
    rateErrorLeft = (errorLeft - prevErrorLeft) / ((double)(currTimeLeft - prevTimeLeft)/1000);

    outLeft = kPL * errorLeft + kDL * rateErrorLeft + kIL * cumErrorLeft;

    prevErrorLeft = errorLeft;
    prevTimeLeft = currTimeLeft;
    Serial2.print("    outLeft    "); Serial2.print(speedLeftSet + outLeft);

    if (outLeft < 0) {
      speedLeftSet = (max(-MAXSPEED, speedLeftSet + outLeft));//min(-MINSPEED, speedLeftSet + outLeft )));
    }
    else {
      speedLeftSet = (min(MAXSPEED, speedLeftSet + outLeft));//max(MINSPEED, speedLeftSet + outLeft)));
    }

    Serial2.print("    speedLeftSet    "); Serial2.print(speedLeftSet);
    Serial2.println();
    md.setM2Speed(speedLeftSet);
  }
  stopIfFault();
}


void SetSpeedRight(float speedRight) {
  currTimeRight = millis();
  if (speedRight == 0) {
    md.setM1Speed(0);
    speedRightSet = 0;
    errorRight = 0;
    cumErrorRight = 0;
    rateErrorRight = 0;
    outRight = 0;
    
  } else {
    errorRight = speedRight - VRight;
    Serial2.print("speedRight    "); Serial2.print(speedRight);
    Serial2.print("    VRight    "); Serial2.print(VRight);
    cumErrorRight += errorRight * ((double)(currTimeRight - prevTimeRight)/1000);
    rateErrorRight = (errorRight - prevErrorRight) / ((double)(currTimeRight - prevTimeRight)/1000);

    outRight = kPR * errorRight + kDR * rateErrorRight + kIR * cumErrorRight;

    prevErrorRight = errorRight;
    prevTimeRight = currTimeRight;
    Serial2.print("    outRight    "); Serial2.print(kPR * errorRight + kDR * rateErrorRight + kIR * cumErrorRight);
    
    if (outLeft < 0) {
      speedRightSet = (max(-MAXSPEED, speedRightSet + outRight));// min(-MINSPEED, speedRightSet + outRight )));
    }
    else {
      speedRightSet = (min(MAXSPEED, speedRightSet + outRight));// max(MINSPEED, speedRightSet + outRight)));
    }
    
    Serial2.print("    speedRightSet    "); Serial2.print(speedRightSet);
    Serial2.println();
    md.setM1Speed(speedRightSet);
  }
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
