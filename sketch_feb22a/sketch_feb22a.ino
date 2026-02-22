#define BUTTON_PIN 2
#define BUZZER_PIN 3
void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
}
void loop()
{
  
  if(digitalRead(BUTTON_PIN)){
    tone(BUZZER_PIN, 2500, 1); 
  }
  
}