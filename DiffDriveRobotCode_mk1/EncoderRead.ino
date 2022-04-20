//20 holes per rotation

float VLeft;
float VRight;

extern float X;
extern float Y;
extern float Theta;

extern float VX;
extern float VY;
extern float W;
extern double DT;

extern double RSTtime;

unsigned int counterLeft = 0;   // Holds the count of pulses detected
unsigned int counterRight = 0;   // Holds the count of pulses detected

int leftEncoderPin = 19;
int rightEncoderPin = 18;

double timeInterval = 100000;

int wheelDiameter = 65;
int wheelTrack = 33;
float rotaryDistance = 2 * 3.14 * wheelDiameter / 2;

float RPSLeft = 0;
float RPSRight = 0;
double deltaT = 0;

double dX = 0;
double dY = 0;
double dtheta = 0;

void EncoderInit() {
  pinMode(leftEncoderPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(leftEncoderPin), DocountLeft, FALLING );  // Create interrupt handler to count pulses

  pinMode(rightEncoderPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(rightEncoderPin), DocountRight, FALLING );  // Create interrupt handler to count pulses

  Timer1.initialize(timeInterval);
  Timer1.attachInterrupt( Timer_Isr );
}
void DocountLeft() {
  counterLeft++;  // increase +1 the counter value
}
void DocountRight() {
  counterRight++;  // increase +1 the counter value
}

void Timer_Isr() {
  Timer1.detachInterrupt();           // Disable the timer
  deltaT = millis() - RSTtime;


  float DLeft = 2 * PI * (wheelDiameter * 0.5) * counterLeft / (20 * 1000);
  float DRight = 2 * PI * (wheelDiameter * 0.5) * counterRight / (20 * 1000);
  float DCenter = (DRight + DLeft) / 2;

  VLeft = DLeft / deltaT;
  VRight = DRight / deltaT;

  dtheta = (DRight - DLeft) / wheelTrack;

  if (DLeft == DRight) {
    dX = DRight * cos(Theta);
    dY = DRight * sin(Theta);
  }
  else {
    double radius = DCenter / dtheta;

    double iccX = X - radius * sin(Theta);
    double iccY = Y + radius * cos(Theta);

    dX = radius * sin(dtheta + Theta) + iccX - X;
    dY = iccY - radius * cos(dtheta + Theta) - Y;
  }

  X += dX;
  Y += dY;
  Theta = (Theta + dtheta) ;
  while (Theta >= 2 * PI) {
    Theta -= 2 * PI;
  }
  VX = dX / deltaT;
  VY = dY / deltaT;
  W = dtheta / deltaT;

  DT = deltaT;
  //  Serial.println(VRight);
  counterRight = 0;
  counterLeft = 0;
  dtheta = 0;
  deltaT = millis();
  Timer1.attachInterrupt( Timer_Isr ); // Re-enable the timer
}
