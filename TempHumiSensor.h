#include "dht.h"
#define dht_apin A0

class TempHumiSensor {
  public:
    dht DHT;

    void setUp() {
      delay(500);
      Serial.println("DHT HUMIDITY SENSOR  ");
      delay(1000);
    }

    void run() {
      DHT.read11(7); 

      Serial.print("Current humidity: ");
      Serial.print(DHT.humidity); 
      Serial.print("% ");

      Serial.print("Temperature: ");
      Serial.print(DHT.temperature);
      Serial.println(" C");

      delay(500);
    }

    int getHumidity() {
      return DHT.humidity;
    }

    int getTemperature() {
      return DHT.temperature;
    }

    bool verifyHumidity() {
      if (DHT.humidity > 25 && DHT.humidity < 60) {
        return true;
      } else {
        return false;
      }
    }

    bool verifyTemperature() {
      if (DHT.temperature > 15 && DHT.temperature < 25 ) {
        return true;
      } else {
        return false;
      }
    }
};