#include <Servo.h> 
 
Servo servogaiola,servoferomonio,servolixeira;

// constants won't change. They're used here to
// set pin numbers:
const int buttondisparo = 2;     // the number of the pushbutton pin


int gaiolafechado = 10;
int gaiolaaberto = 180;

int feromonioaberto =80;
int feromoniofechado = 50;

int lixeiraaberto = 250;
int lixeirafechado = 100;

// variables will change:
int gaiolaState = 0;         // variable for reading the pushbutton status
int feromonioState = 0;
int lixeiraState = 0;

void setup() {
  Serial.begin(9600); 
  servolixeira.attach(4);   //amarelo
  servogaiola.attach(6);   //marron
  servoferomonio.attach(7);   //roxo
  
  // initialize the pushbutton pin as an input:
  pinMode(buttondisparo, INPUT);
}

void loop() {
        gaiolaState=0;
        feromonioState=0;
        lixeiraState=0;
  
    //leitura do teclado
  if (Serial.available()) { // Verificar se há caracteres disponíveis
      char caractere = Serial.read(); // Armazena caractere lido
      if ( caractere=='1' ) { 
                Serial.println("1");

        gaiolaState = 1;
      }
      else if( caractere=='2')
      {
                Serial.println("2");

        feromonioState=1;
      }
      else if( caractere=='3')
      {
        Serial.println("3");
        lixeiraState=1;
      }
      else
      {
        gaiolaState=0;
        feromonioState=0;
        lixeiraState=0;
      }
   }

  //gaiola
     if(gaiolaState == 1) 
    {
       servogaiola.write(gaiolaaberto);  
       delay(2000);          //Delay para o servo atingir a posiçao
       servogaiola.write(gaiolafechado);  
       delay(100);
       Serial.print("Gaiola: ");
       Serial.print(gaiolaState);
       gaiolaState = 0;
       Serial.println(gaiolaState);
    }
    else
    {
       servogaiola.write(gaiolafechado);  
       delay(100);
    }

    //feromonio
    if(feromonioState == 1) 
    {
      for(int i=0; i<10;i++)
      {
       servoferomonio.write(feromonioaberto);  //Move o servo para o angulo de 60 graus
       delay(300);          //Delay para o servo atingir a posiçao
       servoferomonio.write(feromoniofechado);  //Move o servo para o angulo de 60 graus
       delay(150);          //Delay para o servo atingir a posiçao
       Serial.print("Feromonio ");
       Serial.print(feromonioState);
       feromonioState = 0;
       Serial.println(feromonioState);
      }

    }
    else
    {
      servoferomonio.write(feromoniofechado);  //Move o servo para o angulo de 60 graus
      delay(200);          //Delay para o servo atingir a posiçao
    }

    //lixeira
    if(lixeiraState == 1) 
    {
       servolixeira.write(lixeiraaberto);  //Move o servo para o angulo de 60 graus
       delay(3000);          //Delay para o servo atingir a posiçao
       servolixeira.write(lixeirafechado);  //Move o servo para o angulo de 60 graus
       delay(150);          //Delay para o servo atingir a posiçao
       Serial.print("Lixeira ");
       Serial.print(lixeiraState);
       lixeiraState = 0;
       Serial.println(lixeiraState);
    }
    else
    {
      servolixeira.write(lixeirafechado);  //Move o servo para o angulo de 60 graus
      delay(200);          //Delay para o servo atingir a posiçao
    }
    
}