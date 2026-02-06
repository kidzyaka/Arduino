#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define VRX A0
#define VRY A1
#define SW  11

#define LEDGREEN 2
#define LEDRED 3


int workTime;
int breakTime;

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDRED, OUTPUT);

  lcd.begin(16,2);
  lcd.clear();
  workTime = timeSelectScreen("Work");

  lcd.clear();
  
  for(int i = 0; i < 5; i++){
    
    lcd.setCursor(0,0);
    lcd.print(workTime);
    lcd.print(" min selected");
    delay(400);
    lcd.setCursor(0, 0);
    lcd.print("                ");
    delay(200);
  }

  breakTime = timeSelectScreen("Break");

  lcd.clear();
  
  for(int i = 0; i < 5; i++){
    
    lcd.setCursor(0,0);
    lcd.print(breakTime);
    lcd.print(" min selected");
    delay(400);
    lcd.setCursor(0, 0);
    lcd.print("                ");
    delay(200);
  }

  lcd.clear();
  lcd.print("Starting in...");
  
  for(int i = 5; i > 0; i--){
    lcd.setCursor(0,1);
    lcd.print(i);
    lcd.print(" seconds");
    delay(1000);
  }

  lcd.clear();

  
}

void loop() {

  int timerMinutes = workTime;

  digitalWrite(LEDRED, HIGH);

  for(timerMinutes; timerMinutes > 0; timerMinutes--){
    lcd.print("Work time!");
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print(timerMinutes);
    lcd.print("min remain");
    delay(60000);
  }
  digitalWrite(LEDRED, LOW);
  digitalWrite(LEDGREEN, HIGH);

  lcd.clear();
  lcd.print("break time!");
  
  for(int i = 0; i < 10; i++){
    lcd.setCursor(0,1);
    lcd.print("   ");
    delay(150);
    lcd.setCursor(0,1);
    lcd.print("!!!");
    delay(250);
    
  }

  timerMinutes = breakTime;

  for(timerMinutes; timerMinutes > 0; timerMinutes--){
    lcd.print("Break time!");
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print(timerMinutes);
    lcd.print("min remain");
    delay(60000);
  }

  digitalWrite(LEDGREEN, LOW);


}

int timeSelectScreen(String type) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(type);
  lcd.print(" time");

  bool lastState = HIGH;

  int minutes;

  if(type == "Work"){
    minutes = 25;
  } else if (type == "Break") {
    minutes = 5;
  }
  
  while(true){
    lcd.setCursor(0,1);

    int y = analogRead(VRY);

    if(y > 900){
      if(minutes > 1){
        minutes--;
      }
  
    } else if (y < 100) {
      minutes++;
    }

    lcd.print("               ");
    lcd.setCursor(0,1);
    lcd.print(minutes);
    lcd.print(" min");
    delay(200);
    
    if(checkForClick()){
      return minutes;
    }
  }
}


bool checkForClick(){
   int lastState = HIGH;
   bool currentState = digitalRead(SW);

    if (lastState == HIGH && currentState == LOW) {
      delay(10);
      if (digitalRead(SW) == LOW) {
        return true;
      } else {
        return false;
      }
    }
}
