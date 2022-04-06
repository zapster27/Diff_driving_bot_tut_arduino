//20 holes per rotation

extern float VLeft;
extern float VRight;

unsigned int counterLeft = 0;   // Holds the count of pulses detected
unsigned int counterRight = 0;   // Holds the count of pulses detected

int leftEncoderPin = 19;
int rightEncoderPin = 18;

double timeInterval = 100000;

int wheelDiameter = 65;
float rotaryDistance = 2 * 3.14 * wheelDiameter / 2;

float RPSLeft = 0;
float RPSRight = 0;

void EncoderInit() 
{

  pinMode(leftEncoderPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(leftEncoderPin), DocountLeft, FALLING );  // Create interrupt handler to count pulses
  
  pinMode(rightEncoderPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(rightEncoderPin), DocountRight, FALLING );  // Create interrupt handler to count pulses
  
  Timer1.initialize(timeInterval);   
  Timer1.attachInterrupt( Timer_Isr );   
} 
void DocountLeft()  
{
  counterLeft++;  // increase +1 the counter value
} 
void DocountRight()  
{
  counterRight++;  // increase +1 the counter value
} 

void Timer_Isr()
{
  Timer1.detachInterrupt();           // Disable the timer
  RPSLeft = counterLeft * 1000000/(20*timeInterval);
  RPSRight= counterRight * 1000000/(20*timeInterval);
  VLeft = wheelDiameter * 0.5 * 2 * 3.14 * RPSLeft / 1000;
  VRight = wheelDiameter * 0.5 * 2 * 3.14 * RPSRight / 1000;
//  Serial.println(VRight);
  counterRight = 0;
  counterLeft = 0;
  Timer1.attachInterrupt( Timer_Isr ); // Re-enable the timer
}
