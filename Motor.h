class Motor {
  public:
    void setUp() {
    Serial.begin(9600);
    pinMode(10, OUTPUT);
    pinMode(6, OUTPUT);
    }

    void run() {
      Serial.print("Problem");
      digitalWrite(10, HIGH);
      analogWrite(6, 200);
    }
};