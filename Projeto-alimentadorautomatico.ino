#include <Servo.h>


const int pushbutton1 = 0;
const int pushbutton2 = 1;
const int botao = 2;
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int ledb1 = 6;
const int ledb2 = 7;
const int ledb3 = 8;
const int ledracao = 9;
int contador1 = 0;
int contador2 = 0;
Servo servo_9;
unsigned long tempoant = 0;
int temp = 0;
int d = 0;

void setup(){
  pinMode(pushbutton1, INPUT_PULLUP); 
  pinMode(pushbutton2, INPUT_PULLUP); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ledb1, OUTPUT);
  pinMode(ledb2, OUTPUT);
  pinMode(ledb3, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  servo_9.attach(10, 500, 2500);
}

void loop(){

  if (digitalRead(pushbutton1) == LOW){ // Se o botão for pressionado
    contador1++;
    delay(100);
  }

  if (digitalRead(pushbutton2) == LOW){ // Se o botão for pressionado
   
    contador2++;
    delay(100);
  }

  //verificando botao 1
  if(contador1 == 0){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    temp = 5000;//definindo tempo de acionamento do motor em 5000
  }else if(contador1 == 1){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    temp = 8000;//definindo tempo de acionamento do motor em 8000
  }else if(contador1 == 2){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    temp = 10000;//definindo tempo de acionamento do motor em 10000
  }else if(contador1 > 2){
    contador1 = 0;
  }

  
  //verificando botao 2
  if(contador2 == 0){
    digitalWrite(ledb1, HIGH);
    digitalWrite(ledb2, LOW);
    digitalWrite(ledb3, LOW);
    d = 500;//atribui um delay de 500 no acionamento do motor
  }else if(contador2 == 1){
    digitalWrite(ledb1, LOW);
    digitalWrite(ledb2, HIGH);
    digitalWrite(ledb3, LOW);
    d = 1000;//atribui um delay de 1000 no acionamento do motor
  }else if(contador2 == 2){
    digitalWrite(ledb1, LOW);
    digitalWrite(ledb2, LOW);
    digitalWrite(ledb3, HIGH);
    d = 1500;//atribui um delay de 1500 no acionamento do motor
  }else if(contador2 > 2){
    contador2 = 0;
  }
  
  while(digitalRead(botao) == LOW){
    	delay(100);
    	servo_9.write(90);
    	digitalWrite(ledracao, HIGH);
  }
  digitalWrite(ledracao, LOW);

  if(millis() < 4294950000){
    if(millis() - tempoant >= temp){//verifica se o tempo correto ja passou
      tempoant = millis();
      delay(100);
      servo_9.write(90);//aciona o motor
       delay (d);//aguarda o delay previamente selecionado pelo botao
    }
  }
  
  if(millis() > 4294950000){
  	tempoant = 0;
  }
  	servo_9.write(0);
    delay(100);
}
