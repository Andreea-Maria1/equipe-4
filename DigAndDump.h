#include <Servo.h>

class DigAndDump {
  public:
    Servo servo;
    int state = 0;

    void setUp() {
      servo.attach(9);
    }

    void run() {
      for (int i=0; i < 5; i++) {
          delay(500);
          servo.write(360);
          delay(500);
          servo.write(360);
      }
    }
};