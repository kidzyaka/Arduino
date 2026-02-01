const int digitalPin = 2;
const int analogPin = A0;

void setup() {
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int digitalValue = digitalRead(digitalPin);
  int analogValue = analogRead(analogPin);

  Serial.println(analogValue);

  delay(100);
}
