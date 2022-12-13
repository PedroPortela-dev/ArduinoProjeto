#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

int motorPin[6] = {4,5,6,7,8,9};

int tempoPorCm = 40.31354981;
int noventaGraus = 40.0*7*3.141592/2;
int powerDireita = 150*0.8;
int powerEsquerda = 150;
float RaioDireita;
float RaioEsquerda; 
float PowerDireita2;
float umciclo;
int ladoQuadrado;
char leitura;

void setup()
{
  //Todos os pinos dos motores setados como OUTPUT
  for(int i = 0; i<6; i++){
    pinMode(motorPin[i], OUTPUT);
  }
  
  mySerial.begin(9600);
}
void loop(){
  mySerial.println("Circulo(c) ou Quadrado(q)?");
  while(!mySerial.available());
  leitura = mySerial.read();
  if(leitura == 'c'){
    circulo();
  }else if(leitura == 'q'){
    quadrado();
  }
}

void quadrado()
{
  mySerial.println("Digite o tamanho do lado do quadrado: ");
  while(!mySerial.available());
  ladoQuadrado = mySerial.parseInt();
  for(int i = 0; i < 4; i++){
    roboFrente();
    delay(ladoQuadrado*tempoPorCm);
    roboDireita();
    delay(noventaGraus);
  }
  roboParar();
}

void circulo(){
  mySerial.println("Digite o tamanho do diametro: ");
  while(!mySerial.available());
  RaioEsquerda = mySerial.parseInt();
  RaioDireita = RaioEsquerda - 14;
  powerDireita2 = RaioDireita/RaioEsquerda;
  frente(0, powerDireita*PowerDireita2);
  frente(1, powerEsquerda);
  delay(umciclo);
  roboParar();
}

void roboFrente(){
  frente(0, powerDireita);
  frente(1, powerEsquerda);
}
void roboDireita(){
  frente(0, powerDireita);
  tras(1, powerEsquerda);
}
void roboParar(){
  parar(0);
  parar(1);
}
void parar(int j){
  digitalWrite(motorPin[3*j+0], LOW);
  digitalWrite(motorPin[3*j+1], LOW);
  analogWrite(motorPin[3*j+2], 0);
}
void frente(int j, int power){
  digitalWrite(motorPin[3*j+0], HIGH);
  digitalWrite(motorPin[3*j+1], LOW);
  analogWrite(motorPin[3*j+2], power);
}
void tras(int j, int power){
  digitalWrite(motorPin[3*j+0], LOW);
  digitalWrite(motorPin[3*j+1], HIGH);
  analogWrite(motorPin[3*j+2], power);
}
