int trig = 2;
int echo = 3;
int lampada = 4;
float distancia;  

void setup()  
{
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
  pinMode(lampada,OUTPUT);
  Serial.begin (9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delay(0005);
  digitalWrite(trig, HIGH);
  delay(0010);
  digitalWrite(trig, LOW);
  
  distancia = pulseIn (echo, HIGH);
  distancia = distancia/58;
  Serial.println (distancia);
  
  if(distancia <=20 ){
    digitalWrite(4,HIGH);
    tone(lampada, 1000);
    delay(500);
  }
  else{
    noTone(4);
  }
}
