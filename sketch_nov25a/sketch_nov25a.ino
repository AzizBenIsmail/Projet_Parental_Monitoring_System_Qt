#define PIN_LED1 12 //le numéro de la broche sur laquelle la lampe 2  est branchée
#define Buzzer 13 // Le numéro de la broche sur laquelle la lampe 1 
//(par défaut intégrée dans la carte) est branchée 
#define pas  20 // incrément de l'intensité
char data; // variable contenant le caractère lu
int x; // variable contenant l'intensité de la deuxième lampe

void setup() {
  // Configure la broche 11 sur laquelle est reliée notre LED  en sortie
  pinMode(PIN_LED1,OUTPUT);
//La LED reliée à la broche 11 est intialisé à l'état LOW

//La LED reliée à la broche 13 est intialisé à l'état LOW
pinMode(PIN_LED1,OUTPUT);
  analogWrite(PIN_LED1, 0);
  Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 
  x=0; // Intialiser l'intensité de la deuxième lampe 

}



void loop() {
  if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='1') //si le caractère lu est égale à 1
    {
    
      tone(Buzzer,450);

     
      // alumer la lampe 
      Serial.write('1'); //envoyer le nouvel état de la lampe  
     }  
     else if(data=='0') //si le caractère lu est égale à 0

     {
        noTone(Buzzer); //éteindre la lampe
        Serial.write('0'); //envoyer le nouvel état de la lampe
     
     }   
     // Régler l'intensité de la luminosité de la deuxième lampe branchée sur la broche 11
     else if(data=='2') //si le caractère reçu est égale à 2
     {
        if(x+pas<=255) // si l'intesité est encore inférieur à l'intensité max=255 
        x=x+pas; // incrémenter l'intesité de la lumière   
        analogWrite(PIN_LED1,x); 
        
     }  
     else if(data=='3')
     {
        if((x>pas)) // si l'intesité est encore supérieur au pas 
         x=x-pas; // décreménter l'intensité 
        else 
         x=0;
         
        analogWrite(PIN_LED1,x);
     
     } 
  }
}
