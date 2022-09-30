#include <Adafruit_LiquidCrystal.h>

float nivel = 0;

Adafruit_LiquidCrystal lcd(0);

void setup()
{
  pinMode(A1, INPUT);
  pinMode(8, OUTPUT); // Led de nao OK
  pinMode(10, OUTPUT); // Led de OK
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  nivel = analogRead(A1);
  Serial.println(nivel);
  
  if (nivel > 700){
   digitalWrite(8,0);
   lcd.setCursor(0, 0);
   lcd.print("SISTEMA CHEIO");
   digitalWrite(10,1);
   delay(500);
   digitalWrite(10,0);
   delay(500);
   digitalWrite(10,1);
   delay(500);
   digitalWrite(10,0);
   delay(500);
  }
  
  else{
     lcd.setCursor(0,0);
     lcd.print("SISTEMA OK     ");
     digitalWrite(8,1);
  }
  
}
