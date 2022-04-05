#include <LiquidCrystal.h> //Inserção da biblioteca pra trabalhar com LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos de interface

int leitura = 0 , pressionado = 0 ; // Declaracao das variaveis pra monitorar o botao e a leitura analogica

void setup() {
  Serial.begin(9600); // Inicia a Serial
  pinMode(A0 , INPUT); // Potenciometro
  pinMode(13 , INPUT); // Botao
  lcd.begin(16, 2); // Determinar que todas as linhas e colunas vao ser usadas
  lcd.print("Lcd Arduino 16x2"); // Escreve a mensagem inicial
}

void loop() {
  if (pressionado == 0 ){
  lcd.setCursor(0, 1); // Inicia a escrita na coluna 0 e na linha 1
  leitura = analogRead(A0) ; // Leitura do potenciometro
  leitura = map(leitura,0,1023,0,255); // Converte os valores
  lcd.print("Leitura Pot :");
  lcd.print(leitura);
  delay(50); // Aguarda 50ms
  }
  if(digitalRead(13)== 1){ // Se o botao for pressionado
     pressionado=1; // muda o status do botao
     lcd.clear(); // Metodo que limpa o lcd
  }
  if(pressionado== 1){
     lcd.setCursor(0, 0);
     lcd.print("Ligado Press"); // Escreve a mensagem
}
}
