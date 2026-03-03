const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 7;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  int distance = duration * 0.0343 / 2;

  Serial.println(distance);
  
  for(int i = 0; i < 3; i++) { // Теперь i начинается с 0
      tone(buzzer, 1130);
      delay(25);         // Ждем, пока звук длится
      noTone(buzzer);    // Выключаем, чтобы создать прерывистый звук
      delay(25);         // Короткая пауза между писками
    }

  delay(distance*2);

}