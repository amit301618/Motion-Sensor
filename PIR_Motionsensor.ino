int led = 13;
int pin = 8;

int value = 0;
int pirState = LOW;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pin, INPUT);
  Serial.begin(9600);
  Serial.print("LABEL, Date, Time, State");
}

void loop() {

  value = digitalRead(pin);

  if (value == HIGH) {
    digitalWrite(led, HIGH);

    if (pirState == LOW) {
      Serial.println("Motion Detected!");
      Serial.print("DATA, DATE, TIME,");
      pirState = HIGH;
    }
  } else {
    digitalWrite(led, LOW);

    if (pirState == HIGH) {
      Serial.println("Motion Ended!");
      Serial.print("DATA, DATE, TIME,");
      pirState = LOW;
    }
  }
}
