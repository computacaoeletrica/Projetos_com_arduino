// Projeto que conta de 0 até 5 em um display de 7 segmentos

void setup()
{
  pinMode(2, OUTPUT); // A
  pinMode(3, OUTPUT); // B
  pinMode(4, OUTPUT); // F
  pinMode(5, OUTPUT); // G
  pinMode(6, OUTPUT); // E
  pinMode(7, OUTPUT); // D
  pinMode(8, OUTPUT); // C
}

void loop()
{
  // Desenhar o 0
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  
  delay(1000);
  
  // Desenhar o 1
  
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(5, LOW);
  
  
  delay(1000);
  
  // Desenhar o 2
  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  
  delay(1000);
  
  // Desenhar o 3
  
  digitalWrite(8, HIGH);
  digitalWrite(6, LOW);
 
  delay(1000);
  
  // Desenhar o 4
  
  digitalWrite(7, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
 
  delay(1000);
  
  // Desenhar o 5
  
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(7, HIGH);
 
  delay(3000);
  
  
  
  
  
}
