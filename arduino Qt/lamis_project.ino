const int notionPin = 4;
const int ledPin =12 ;
int sens1 = 7;                    // crée une variable de type "int", nommée "sens1" et attachée à la Broche 9, qui permet de gérer le sens de rotation.
int sens2 = 8;                    // crée une variable de type "int", nommée "in2" et attachée à la Broche 8, qui permet de gérer l'autre sens de rotation.
int enA = 5;                   // crée une variable de type "int", nommée "enA" et attachée à la Broche 10, qui permet de gérer la vitesse du moteur.


void setup() {
pinMode (ledPin,OUTPUT);
pinMode(sens1, OUTPUT);         // indique que la broche de la variable "sens1" donc ici la PIN 9, est une sortie.
 pinMode(sens2, OUTPUT);         // indique que la broche de la variable "sens2" donc ici la PIN 8, est une sortie
 pinMode( enA, OUTPUT);         // indique que la broche de la variable "sens2" donc ici la PIN 8, est une sortie
pinMode (notionPin, INPUT);      // indique que la broche de la variable "notionpin" donc ici la PIN 11, est une entrée
char data;
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalRead(notionPin);
if (digitalRead(notionPin)==HIGH)
{
  digitalWrite (ledPin,HIGH);
Serial.println("Motion detected");
digitalWrite(sens1,HIGH);      // envoie l'électricité dans la broche in1 (donc la PIN 9)ce qui fait donc tourner le moteur dans le sens de rotation de in1.
digitalWrite(sens2,LOW); // en mettant la broche sens2 à l'état bas, la carte n'injecte pas d'électricité, le moteur peut donc continuer à tourner dans le sens de sens1.
  
  delay(5000);  // créer un delais de 5 secondes, donc le moteur tourne pendant 5 secondes.

digitalWrite(sens1,LOW);       // en mettant la broche sens1 à l'état bas, la carte n'injecte pas d'électricité, le moteur est donc à l'arrêt.
digitalWrite(sens2,LOW);       // en mettant la broche sens2 à l'ét
  delay(7000);  // créer un delais de 5 secondes, donc le moteur tourne pendant 5 secondes.

  digitalWrite(sens1,LOW);       // met la broche sens1 à l'état bas, la carte n'injecte pas d'électricité, le moteur ne tourne pas dans le sens de in1.
digitalWrite(sens2,HIGH);      // envoie l'électricité dans la broche in2 (donc la PIN 8)ce qui fait donc tourner le moteur dans le sens de rotation de in2.
delay(5000);

digitalWrite(sens1,LOW);       // en mettant la broche sens1 à l'état bas, la carte n'injecte pas d'électricité, le moteur est donc à l'arrêt.
digitalWrite(sens2,LOW);       // en mettant la broche sens2 à l'ét
}

else {digitalWrite(ledPin, LOW);
Serial.println("motion ended");
digitalWrite(sens1,LOW);       // en mettant la broche sens1 à l'état bas, la carte n'injecte pas d'électricité, le moteur est donc à l'arrêt.
 digitalWrite(sens2,LOW);       // en mettant la broche sens2 à l'état bas, la carte n'injecte pas d'électricité, le moteur est donc à l'arrêt.

}
}
