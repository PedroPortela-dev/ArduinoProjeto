#include "Driver.h"
#include <SoftwareSerial.h>

char serial;

Motor *md = new Motor(9, 7, 8);
Motor *me = new Motor(6, 4, 5, false, 0.12);
Driver *drive = new Driver(md, me);

SoftwareSerial mySerial(10, 11);

void setup() {
  mySerial.begin(9600);
}

void loop() {
  serial = mySerial.read();
  if(serial == 'U'){
    drive->frente(255);
  }else
  if(serial == 'D'){
    drive->tras(255);
  }else
  if(serial == 'R'){
    drive->direita(150);
  }else
  if(serial == 'L'){
    drive->esquerda(150);
  }else
  if(serial == 'H'){
    drive->freiar();
  }else
   if(serial == 'C'){
    drive->frente(255);
    delay(500);
    drive->freiar();
  }else
   if(serial == 'B'){
    drive->tras(255);
    delay(500);
    drive->freiar();
  }else
   if(serial == 'F'){
    drive->direita(150);
    delay(500);
    drive->freiar();
  }else
   if(serial == 'E'){
    drive->esquerda(150);
    delay(500);
    drive->freiar();
  }
  
}
