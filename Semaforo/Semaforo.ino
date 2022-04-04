// Um pequeno projeto que simula o comportamento de um semáforo
// São necessários 3 leds ( um vermelho , um verde e um amarelo ) , um protoboard , e um arduino 

void setup()
{
  Serial.begin(9600); // Inicia a Serial
  
  // Define os pinos 4 , 5 e 6 como saída
  
  pinMode(4, OUTPUT);  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
 
  // Inicia os leds desligados
  
  digitalWrite(4, LOW);  // Led verde
  digitalWrite(5, LOW); // Led amarelo
  digitalWrite(6, LOW); // Led vermelho
}
void loop()
{
    digitalWrite(6, LOW); // Apaga o vermelho
    digitalWrite(5, LOW); // Apaga o amarelo
    digitalWrite(4, HIGH);  // Ativa o verde
    delay(2000);   // Espera 2 segundos
    digitalWrite(5, HIGH); // Ativa o amarelo
    digitalWrite(4, LOW);  // Apaga o verde
    delay(2000); 
    digitalWrite(6, HIGH); // Ativa o vermelho
    digitalWrite(5, LOW); // Apaga o amarelo
    delay(2000);
    digitalWrite(5, HIGH); // Ativa o amarelo
    digitalWrite(6, LOW); // Apaga o vermelho
    delay(2000); 
}
