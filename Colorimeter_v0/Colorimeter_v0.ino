// Declare pins
int digPin_mainLED=8;
int anaPin_photosensor1=4;
// Declare other variables
double photosensor1_reading;

void setup() {
  
  pinMode(digPin_mainLED,OUTPUT);  
  Serial.begin(9600);

  mainLED_ON(digPin_mainLED);
  delay(1000);

}



void loop() {


  
  photosensor1_reading = analogRead(anaPin_photosensor1);
  Serial.print("Photosensor1 reading = ");
  Serial.println(photosensor1_reading);
  delay(500);
  
}



// Functions

  void mainLED_ON(int mainLEDPin) {
     digitalWrite(mainLEDPin,HIGH);
     Serial.println("Main LED is ON");
  }

  void mainLED_OFF(int mainLEDPin) {
     digitalWrite(mainLEDPin,LOW);
     Serial.println("Main LED is OFF");
  }

