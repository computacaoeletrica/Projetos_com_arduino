int leitura = 0 ;

void setup()
{
  Serial.begin(9600);
  pinMode(A0 , INPUT);
  pinMode (4 , OUTPUT );
}

void loop()
{
  leitura = analogRead (A0) ;
  leitura = map(leitura,0,1023,0,255); 
  analogWrite(4,leitura); 
  Serial.print("Leitura do potenciometro : ");
  Serial.println(leitura);
}
