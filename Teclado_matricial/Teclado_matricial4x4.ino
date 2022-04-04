// Os materiais utilizados foram apenas um Arduino Uno e um teclado matricial 4x4
// Execute o programa e acompanhe as saídas no monitor serial

byte linhas[] = {11,10,9,8};    // Os pinos que representam as linhas do teclado foram colocados nos pinos digitais : 11 , 10 , 9 e 8  
byte colunas[] = {7,6,5,4};     // Os pinos que representam as colunas do teclado foram colocados nos pinos digitais : 7 , 6 , 5 e 4  
int i , j  ;

char pega_tecla()
{
  char  teclas[4][4] = {    // Cria uma matriz similar ao teclado
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
  
  char k ='\0';   // cria uma variável com o caractere de quebra de linha (vazio)
  
  for (i =0 ; i <4 ;i++)
  {
    digitalWrite (linhas[i] , 0);  // Adere o nível baixo para as linhas
    for (j =0 ;j <4 ;j++)
     {
      if (digitalRead(colunas[j]) == LOW){   // Se algum botao for pressionado
        k = teclas[i][j]; // K recebe aquele posicao i e j da tecla pressionada
        break;
        }
     }
     digitalWrite (linhas[i] , 1); // Adere nível alto à linha
     if (k) {  
     break;
     }  
  }
  return k ; 
}

  char pega_primeiratecla(){   // Função que retira repetições na digitação de alguma tecla
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
 Serial.begin(9600); // Inicia a serial
  
 for (i=0; i<4 ;i++)
 {
  pinMode (linhas[i] , OUTPUT);   // Define as linhas como saída
  pinMode (colunas[i] , INPUT_PULLUP); // Define as colunas como entrada PULLUP ( para nao ocorrer erros de oscilação entre 0 e 1 )
  digitalWrite (linhas[i] , 1 ) ; // Inicia as linhas com o valor HIGH
 }
}

void loop()
{
  char tecla = pega_primeiratecla() ;
  
  if (tecla){   
    Serial.print(tecla);   // Mostra a tecla pressionada na Serial
  }
   delay(10) ; // O simulador precisa de um delay
}
