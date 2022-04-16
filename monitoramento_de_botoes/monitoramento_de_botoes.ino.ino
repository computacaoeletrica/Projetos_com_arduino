// Projeto que mostra em um display de 7 segmentos o número de botoes que forsm pressionados

int cont = 0 , i ; // Declara uma variável contadora e uma incrementadora 

int pressionados[4] ; // Cria um vetor que guarda os estados dos botoes (ligado/desligado)

void setup()
{
  Serial.begin(9600); //Inicia a Serial
  
  for (i=0;i<4;i++){
    pressionados[i]=0; // Adere nível deskigad
  }
  
  pinMode(2, OUTPUT); // A
  pinMode(3, OUTPUT); // B
  pinMode(4, OUTPUT); // F
  pinMode(5, OUTPUT); // G
  pinMode(6, OUTPUT); // E
  pinMode(7, OUTPUT); // D
  pinMode(8, OUTPUT); // C
  pinMode(9, INPUT); // Botao 1
  pinMode(10, INPUT); // Botao 2
  pinMode(11, INPUT); // Botao 3
  pinMode(12, INPUT); // Botao 4
  pinMode(13, OUTPUT); // Botao 4

}

void loop()
{ 
 
  if (digitalRead(9))
  {
    pressionados[0]=1;
  }
  
  if (digitalRead(10))
  {
   pressionados[1]=1;
  }
  
  if (digitalRead(11))
  {
    pressionados[2]=1;
  }
  
  if (digitalRead(12))
  {
    pressionados[3]=1;
  }
  
  for (i=0;i<4;i++){
  cont = cont + pressionados[i];
  }
  
  Serial.print("Esse e o numero de botoes pressionados nesse momento : " );
  Serial.print(cont);
  Serial.print("\n");
  
  if (cont==0){
    
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(5, LOW);
  
  }
  
  
  if (cont==1){
    
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(5, LOW);
  
  }
  
  if (cont==2){
    
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  
  }
  
  if (cont==3){
    
  digitalWrite(8, HIGH);
  digitalWrite(6, LOW);
    
  }
  
  
  if (cont==4){
    
  digitalWrite(7, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(13,HIGH);
  Serial.print("O alarme foi ativado,em instantes o contador ira zerar");
  delay(2000);
  digitalWrite(13,LOW);
  setup();  
  }
  
  cont = 0 ;
  
}
