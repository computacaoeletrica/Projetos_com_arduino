#include <LiquidCrystal.h> //Inserção da biblioteca pra trabalhar com LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos de interface

float gas; // Variável que irá fazer a leitura do gás

void setup() {
  Serial.begin(9600); // Inicia a Serial
  pinMode(A0 , INPUT); // Declara um pino analógico
  pinMode(6 , INPUT); // Declara uma entrada digital
  lcd.begin(16, 2); // Inicia LCD
}

void loop() {
  
  delay(10);
  gas = analogRead(A0) ; // Recebe a leitura do sensor
  if (gas < 70){ 
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Sistema ligado !");
  lcd.setCursor(0, 1);
  lcd.print("Monitorando gas ");
  }
  
  if (gas > 70){
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Fumaca detectada!");
  lcd.setCursor(0, 1);
  lcd.print("leitu gas: ");
  lcd.print(gas);
  digitalWrite(6,1); // Acende o Led
  }
    
}
