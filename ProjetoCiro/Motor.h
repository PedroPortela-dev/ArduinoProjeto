class Motor{
  public:
    Motor(double v, int p1, int p2, bool forward = false, double pExtra = 0){
      this->p1=p1;
      this->p2=p2;
      this->pv=v;
      this->forward=forward;
      this->pExtra = 1-pExtra;
      pinMode(p1,OUTPUT);
      pinMode(p2,OUTPUT);
      pinMode(pv,OUTPUT);
      digitalWrite(p1,LOW);
      digitalWrite(p2,LOW);
      digitalWrite(pv,0);
    }
    void frente(int v){
      v*= pExtra;
      digitalWrite(p1,LOW);
      digitalWrite(p2,HIGH);
      analogWrite(pv,v);
    }
    void tras(int v){
      v*= pExtra;
      digitalWrite(p1,HIGH);
      digitalWrite(p2,LOW);
      analogWrite(pv,v);
    }
    void parar(){
      digitalWrite(p1,LOW);
      digitalWrite(p2,LOW);
      analogWrite(pv,0);
    }
    void freiar(){
      digitalWrite(p1,HIGH);
      digitalWrite(p2,HIGH);
      analogWrite(pv,255);
    }
    void mover(int vel){
      vel*= pExtra;
      if(vel >= 0){
        frente(vel);
      }
      else if(vel < 0){
        vel = -vel;
        tras(vel);
      }
    }
  private:
    int p1,p2;
    double pExtra, pv;
    bool forward;
};