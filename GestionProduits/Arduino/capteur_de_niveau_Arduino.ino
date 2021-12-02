#include "LiquidCrystal.h" // on inclut la librairie


#define Led_Red 11 //le numéro de la broche sur laquelle la lampe rouge  est branchée
#define Led_Green 10//le numéro de la broche sur laquelle la lampe vert  est branchée
#define Led_Orange 9 //le numéro de la broche sur laquelle la lampe orange  est branchée
const int buzzer = 8; //buzzer to arduino pin 8
LiquidCrystal lcd(2,3,4,5,6,7);




void setup() 
{
  pinMode(Led_Red,OUTPUT);
  digitalWrite(Led_Red,LOW);

    pinMode(Led_Green,OUTPUT);
  digitalWrite(Led_Green,LOW);

    pinMode(Led_Orange,OUTPUT);
  digitalWrite(Led_Orange,LOW);

   pinMode(buzzer, OUTPUT);

   lcd.begin(16,2);
 //Serial.print("Tension sur A0 : ");
   lcd.write("Tension sur A0 : ");
      
   Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds
}
 
void loop()
{      
 int valeurAnalog = analogRead(A0);
 float tension = (float) 5*valeurAnalog/1023;

//Serial.println(tension);
lcd.write(tension);
 

 delay(1000);
 // 0% => 1 
 // 25% => 2
 //50% => 3
 //75% => 4
 //100% => 5


 if(tension < 1){
  Serial.println("Niveau à 0%");
  digitalWrite(Led_Red,HIGH);
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(2000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  } 
 else if(tension < 2){
  Serial.println("Niveau entre 0% et 25%");
    digitalWrite(Led_Red,HIGH);

  } 
 else if(tension < 3){
  Serial.println("Niveau entre 25% et 50%");
    digitalWrite(Led_Orange,HIGH);

  } 
   else if(tension < 4){
  Serial.println("Niveau entre 50% et 75%");
    digitalWrite(Led_Orange,HIGH);

  } 
   else if(tension < 5){
  Serial.println("Niveau entre 75% et 100%");
    digitalWrite(Led_Green,HIGH);

  } 
   else {
  Serial.println("Niveau à 100%");
    digitalWrite(Led_Green,HIGH);

  } 


  
}
