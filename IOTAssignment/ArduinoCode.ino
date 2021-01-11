#include <BlynkSimpleStream.h>


 char auth[] = "W31w5bm8hS5NdwOUlTfa_In0DcHlW0jI";
float temp;
float acc;
int once = 0;
 void setup()
 {
   Serial.begin(9600);
   Blynk.begin(auth, Serial);
   pinMode(10, OUTPUT);
//   pinMode(11, OUTPUT);
//   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
   //pinMode(A0, INPUT);
 }

 BLYNK_WRITE(V1) //Button Widget is writing to pin V1
{
  Serial.println("yeah");
  int pinData = param.asInt(); 

}



void tempscan(){
  temp = analogRead(A0);
  acc = analogRead(A1);
  acc -= 512;
  acc /= (512/10);
  temp = (temp*500)/1024;
  if(once != 1 && acc<-5){
      Blynk.email("f20170118@pilani.bits-pilani.ac.in", "Car Crash Alert", "Please contact ambualnce.");
      once = 1;
  }
  if(temp>100){
    digitalWrite(10, HIGH);
    //analogWrite(A2,0);
    Blynk.notify("Hey, Car is overheating mad man!!!!!!");
  }else{
    digitalWrite(10, LOW);
    //analogWrite(A2,255);
  }
  Blynk.virtualWrite(V5, temp);
  Blynk.virtualWrite(V1, acc);
}

 void loop()
 {
   Blynk.run();
   tempscan();
 }
