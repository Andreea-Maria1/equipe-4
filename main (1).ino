#include "Motor.h"
#include "DigAndDump.h"
#include "TempHumiSensor.h"
#include "Display.h"

DigAndDump diganddump;
TempHumiSensor temphumisensor;
Display display;
Motor motor;

bool goodStats = true;
int etat = 0;

void setup() {
  Serial.begin(9600);
  diganddump.setUp();
  temphumisensor.setUp();
  display.setUp();
  motor.setUp();
}

void loop() {
  switch (etat) { 
    case 0:
      temphumisensor.run();
      display.run(temphumisensor.getTemperature(), temphumisensor.getHumidity());
      delay(500);
      if (temphumisensor.verifyHumidity() && temphumisensor.verifyTemperature()) {
        etat = 1;
      } else {
        etat = 2;
      }
      break;
    case 1:
      diganddump.run();
      etat = 0;
      delay(500);
      break;

    case 2:
      motor.run();
      delay(2000);
      etat = 0;
      break;
  }
}