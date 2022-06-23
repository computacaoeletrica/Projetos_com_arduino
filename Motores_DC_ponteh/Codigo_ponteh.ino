void setup()
{
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
}

void loop()
{
 
  digitalWrite(5,1); // Sentido positivo
  digitalWrite(10,1); // Sentido positivo
  delay(3000);
  digitalWrite(5,0); // Sentido positivo
  digitalWrite(10,0); // Sentido positivo
  digitalWrite(6,1); // Sentido negativo
  digitalWrite(9,1); // Sentido negativo
  delay(3000);
  digitalWrite(6,0); // Sentido negativo
  digitalWrite(9,0); // Sentido negativo
  
  
}
