#include <LiquidCrystal.h> //Inserção da biblioteca pra trabalhar com LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos de interface

float gas;

void setup() {
  Serial.begin(9600);
  pinMode(A0 , INPUT);
  pinMode(6 , INPUT);
  lcd.begin(16, 2);
}

void loop() {
  
  delay(10);
  gas = analogRead(A0) ;
  if (gas < 70){
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Sistema ligado !");
  lcd.setCursor(0, 1);
  lcd.print("Monitorando gas ");
  digitalWrite(6,0);
  }
  if (gas > 70){
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Fumaca detectada!");
  lcd.setCursor(0, 1);
  lcd.print("leitu gas: ");
  lcd.print(gas);
  digitalWrite(6,1);
  }
    
}
