/*
 * Inspired from demo01.pde by Rob Tillaart (2011): prototype TSL235R monitoring
 *
 * Nicolas Brown (2016)
 */
 
// Declare pins
int digiPin_LED=8;
int digiPin_l2f=2;

volatile unsigned long cnt = 0;
unsigned long oldcnt = 0;
unsigned long t = 0;
unsigned long last;

void irq1()
{
  cnt++;
}

///////////////////////////////////////////////////////////////////
//
// SETUP
//
void setup() 
{
  Serial.begin(115200);
  Serial.println("START");
  pinMode(digiPin_LED,OUTPUT);
  pinMode(digiPin_l2f, INPUT);
  digitalWrite(digiPin_l2f, HIGH);
  attachInterrupt(0, irq1, RISING);
  
  //LED on
  LED_ON(digiPin_LED);
  delay(1000);

}

///////////////////////////////////////////////////////////////////
//
// MAIN LOOP
//
void loop() 
{  
  //Read l2f
  if (millis() - last >= 1000)
  {
    last = millis();
    t = cnt;
    unsigned long hz = t - oldcnt;
    Serial.print("FREQ: "); 
    Serial.print(hz);
    Serial.print("\t = "); 
    Serial.print((hz+50)/100);  // +50 == rounding last digit
    Serial.println(" mW/m2");
    oldcnt = t;
  }
}

// Functions


void LED_ON(int LEDPin) {
   digitalWrite(LEDPin,HIGH);
   Serial.println("LED is ON");
}

void LED_OFF(int LEDPin) {
   digitalWrite(LEDPin,LOW);
   Serial.println("LED is OFF");
}


