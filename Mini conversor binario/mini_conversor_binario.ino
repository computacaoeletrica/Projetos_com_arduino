byte linhas[] = {11,10,9,8};
byte colunas[] = {7,6,5,4};
int i , j ;

char pega_tecla()
{
  char  teclas[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
  
  char k ='\0';
  
  for (i =0 ; i <4 ;i++)
  {
    digitalWrite (linhas[i] , 0);
    for (j =0 ;j <4 ;j++)
     {
      if (digitalRead(colunas[j]) == LOW){
        k = teclas[i][j];
        break;
        }
     }
     digitalWrite (linhas[i] , 1);
     if (k) {
     break;
     }  
  }
  return k ;
}

  char pega_primeiratecla(){
  static char ultimovalor = '\0';
  static unsigned long m = 0 ;
  
  char valor = pega_tecla();
  if (ultimovalor != valor && millis() > (m+100) ){
    ultimovalor = valor ;
    m = millis () ;
    return ultimovalor ;
  }
  return '\0';
}

void setup()
{
  
 Serial.begin(9600);
 pinMode(2,INPUT);
 pinMode(3,INPUT);
 pinMode(12,INPUT);
 pinMode(13,INPUT);
  
 for (int i=0; i<4 ;i++)
 {
  pinMode (linhas[i] , OUTPUT);
  pinMode (colunas[i] , INPUT_PULLUP);
  digitalWrite (linhas[i] , 1 ) ;
 }
}

void loop()
{
  char tecla = pega_primeiratecla() ;
  
  if (tecla){
    if(tecla=='0'){
     digitalWrite(2,0);
     digitalWrite(3,0);
     digitalWrite(12,0);
     digitalWrite(13,0);
    }
    
    if(tecla=='1'){
     digitalWrite(2,1);
     digitalWrite(3,0);
     digitalWrite(12,0);
     digitalWrite(13,0);
    }
    
    if(tecla=='2'){
     digitalWrite(2,0);
     digitalWrite(3,1);
     digitalWrite(12,0);
     digitalWrite(13,0);
    }
    
    if(tecla=='3'){
     digitalWrite(2,1);
     digitalWrite(3,1);
     digitalWrite(12,0);
     digitalWrite(13,0);
    }
    
    if(tecla=='4'){
     digitalWrite(2,0);
     digitalWrite(3,0);
     digitalWrite(12,1);
     digitalWrite(13,0);
    }
    
    if(tecla=='5'){
     digitalWrite(2,1);
     digitalWrite(3,0);
     digitalWrite(12,1);
     digitalWrite(13,0);
    }
    if(tecla=='6'){
     digitalWrite(2,0);
     digitalWrite(3,1);
     digitalWrite(12,1);
     digitalWrite(13,0);
    }
    
    if(tecla=='7'){
     digitalWrite(2,1);
     digitalWrite(3,1);
     digitalWrite(12,1);
     digitalWrite(13,0);
    }
    
    if(tecla=='8'){
     digitalWrite(2,0);
     digitalWrite(3,0);
     digitalWrite(12,0);
     digitalWrite(13,1);
    }
    
    if(tecla=='9'){
     digitalWrite(2,1);
     digitalWrite(3,0);
     digitalWrite(12,0);
     digitalWrite(13,1);
    }
  }
   delay(10) ;
}  
