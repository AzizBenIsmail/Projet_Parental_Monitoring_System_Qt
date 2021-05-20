int buzzer = 7;
int smokeA0 = A0;

// Your threshold value. You might need to change it.
int sensorThres = 450;
int ledg=12;
int ledr=13;
char data; // variable contenant le caractère lu
int x; // variable contenant l'intensité de la deuxième lampe

void setup() {
pinMode(buzzer, OUTPUT);
pinMode(smokeA0, INPUT);
pinMode(ledg,OUTPUT);
pinMode(ledr,OUTPUT);
digitalWrite(ledg,LOW);
digitalWrite(ledr,LOW);
Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 
  x=0; // Intialiser l'intensité de la deuxième lampe 

}
void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
   tone(buzzer, 450);
   delay(500);
   noTone(buzzer);
   delay(500);
   digitalWrite(ledr,LOW);
   digitalWrite(ledg,HIGH);
   Serial.write('1'); //envoyer le nouvel état de la lampe

  }
  else
  {
  noTone(buzzer);
  digitalWrite(ledg,LOW);
  digitalWrite(ledr,HIGH);
  //delay(800);
  //digitalWrite(ledr,LOW);
Serial.write('0'); //envoyer le nouvel état de la lampe

  }
  delay(100);
  if (Serial.available()){     
     data=Serial.read();  

     if(data=='1') //si le caractère lu est égale à 1
    {
    tone(buzzer, 1000); 
   
     }  
     else if(data=='0') //si le caractère lu est égale à 0

     {
      
    
   noTone(buzzer);
   digitalWrite(ledg,LOW);
   digitalWrite(ledr,HIGH);
   
     }   

  }
}
