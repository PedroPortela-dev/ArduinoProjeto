#define ladpin 13

int valor, i;

void setup(){
  Serial.begin(9600);
  pinMode(ladpin, OUTPUT);
}

void loop(){
  if(i ==0){
    Serial.print("Digite um numero: ");
    i++;
  }
  if(Serial.available()){
    valor = 100*(Serial.read()-48);
    Serial.println(valor);
    if(valor <0 || valor>900){
    	valor = 0;
      	Serial.println("\nInvalido");
    }
 	Serial.flush();
    i = 0;
  }
  if(valor!=0){
    blink(valor);
  }
}

void blink(int time){
  digitalWrite(ladpin, HIGH);
  delay(time);
  digitalWrite(ladpin, LOW);
  delay(time);
}
