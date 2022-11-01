#define ladpin1 13
#define ladpin2 12

int valor, i;

void setup(){
  Serial.begin(9600);
  pinMode(ladpin1, OUTPUT);
  pinMode(ladpin2, OUTPUT);
}

void loop(){
  if(i ==0){
    Serial.print("Digite um numero: ");
    i++;
  }
  if(Serial.available()==1){
    valor = 100*(Serial.read()-48);
    Serial.println(valor);
    if(valor <0 || valor>900){
    	valor = 0;
      	Serial.println("\nInvalido");
    }
    i = 0;
  }
  while(Serial.available()){
    Serial.read();
    Serial.flush();
  }
  if(valor!=0){
    blink(valor);
  }
}

void blink(int time){
  digitalWrite(ladpin1, HIGH);
  digitalWrite(ladpin2, LOW);
  delay(time);
  digitalWrite(ladpin2, HIGH);
  digitalWrite(ladpin1, LOW);
  delay(time);
}
