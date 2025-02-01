#include <LiquidCrystal.h>

class Display {
  public:
    LiquidCrystal lcd = LiquidCrystal(12, 11, 5, 4, 3, 2);

    void setUp() {
      lcd.begin(16,2);
    }

    void run(int temp, int humi) {
      Serial.print("Current humidity: ");
      Serial.print(humi); 
      Serial.print("% ");

      Serial.print("Temperature: ");
      Serial.print(temp); 
      Serial.println(" C");

      lcd.setCursor(0, 1);           
      lcd.print("Humidity: ");
      lcd.print(humi);
      lcd.print("%");
      _delay_ms(250);

      lcd.setCursor(0, 0);          
      lcd.print("Temp: ");
      lcd.print(temp);
      lcd.print(" C");

      delay(5000); // Wait 5 seconds before the next reading
    }
};