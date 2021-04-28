// déclarer la bibliothéque LiquidCrystal
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int led=10;
int ledg=11;
int ledr=12;
int Buzzer = 13;
char data; // variable contenant le caractère lu
void setup() {
pinMode(led,OUTPUT);
pinMode(ledg,OUTPUT);
pinMode(ledr,OUTPUT);
pinMode(Buzzer,OUTPUT);
lcd.begin(16,2);
lcd.setCursor(1,0);
lcd.print("Temp= ");
lcd.setCursor(10,0);
lcd.print("C");
lcd.setCursor(1,1);
lcd.print("Salut");
Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 

}

void loop() {
  digitalWrite(led,HIGH);
  delay(150);
  digitalWrite(led,LOW);
  delay(150);
  int Valeur=analogRead(A0);
 int Vout=Valeur*5.0/1023*1000;
 int temp=Vout/10;
  Serial.println(temp);
 lcd.setCursor(7,0);
 lcd.print(temp);
 if(temp>30)
 {
  digitalWrite(ledg,LOW);
  digitalWrite(ledr,HIGH);
  delay(90);
  digitalWrite(ledr,LOW);
  delay(90);

  Serial.write('1');
 }else
 {  digitalWrite(ledr,LOW);
noTone(Buzzer);
  digitalWrite(ledg,HIGH);
  Serial.write('0');
 }
 if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='1') //si le caractère lu est égale à 1
    {
    
      tone(Buzzer,450);     
      // alumer la lampe 
     }  
     else if(data=='0') //si le caractère lu est égale à 0

     {
        noTone(Buzzer); //éteindre la lampe
     
     }   

     
     } 
  }
