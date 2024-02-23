#include <Arduino.h>

// Set up I/O Pins
const int waterPump = 53;
const int waterLevelSensor = 40;
const int magnesiaLevelSensor = 44;
const int sensorSignalMode = 36;
const int solenoidPrimary = 4;
//const int electrodialsysZapPin = 10;
const int solenoidMagnesium = 7;
const int magnesiumPump = 13;

// Setup
void setup()
{
  // Set Pinout
  Serial.begin(9600);
  pinMode(waterPump, OUTPUT);
  pinMode(waterLevelSensor, INPUT);
  pinMode(magnesiaLevelSensor, INPUT);
  pinMode(sensorSignalMode, OUTPUT);
  pinMode(solenoidPrimary, OUTPUT);
  //pinMode(electrodialsysZapPin, OUTPUT);
  pinMode(solenoidMagnesium, OUTPUT);
  pinMode(magnesiumPump, OUTPUT);

  digitalWrite(sensorSignalMode, HIGH);
}

void loop()
{
  // turn on pump
  digitalWrite(waterPump, HIGH);

  while (digitalRead(waterLevelSensor) != HIGH)
  {
    delay(100);
  }

  digitalWrite(waterPump, LOW);

  delay(1000);




  // Add Milk of Magnesia

  digitalWrite(magnesiumPump, HIGH);

  while (digitalRead(magnesiaLevelSensor) != HIGH)
  {
    delay(100);
  }

  digitalWrite(magnesiumPump, LOW);


  // Close Everything

  digitalWrite(solenoidPrimary, LOW);

  /* Electro Dialysis

  digitalWrite(electrodialsysZapPin, HIGH);
  delay(50400000); // correct number i hope
  digitalWrite(electrodialsysZapPin, LOW);

  */
  

  // Drain 

  digitalWrite(solenoidPrimary, HIGH);

  delay(10000); // random number - not accurate

  // close solenoidPrimary

  digitalWrite(solenoidPrimary, LOW);


  // End one cycle
}
