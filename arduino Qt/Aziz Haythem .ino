#define Buzzer 13 // Le numéro de la broche sur laquelle la lampe 1 
int led=10;
int ledg=11;
int ledr=12;
//(par défaut intégrée dans la carte) est branchée 
#define pas  20 // incrément de l'intensité
char data="0"; // variable contenant le caractère lu
int x; // variable contenant l'intensité de la deuxième lampe

void setup() {
  pinMode(led,OUTPUT);
pinMode(ledg,OUTPUT);
pinMode(ledr,OUTPUT);
pinMode(Buzzer,OUTPUT);
  // Configure la broche 11 sur laquelle est reliée notre LED  en sortie
//La LED reliée à la broche 11 est intialisé à l'état LOW

//La LED reliée à la broche 13 est intialisé à l'état LOW

  Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 
  x=0; // Intialiser l'intensité de la deuxième lampe 

}



void loop() {
    digitalWrite(led,HIGH);
  delay(150);
  digitalWrite(led,LOW);
  delay(150);
  int Valeur=analogRead(A0);
 int Vout=Valeur*5.0/1023*1000;
 int temp=Vout/10;
  //Serial.println(temp);
  if(temp>40)
 {
  digitalWrite(ledg,LOW);
  digitalWrite(ledr,HIGH);

  Serial.write('1');
  
 }else
 {  digitalWrite(ledr,LOW);
  digitalWrite(ledg,HIGH);
  Serial.write('0');
  noTone(Buzzer);
 }
 //noTone(Buzzer);
      //tone(Buzzer,450)
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
     else //si le caractère lu est égale à 0

     {
        noTone(Buzzer); //éteindre la lampe
     
     }   
  }
}
