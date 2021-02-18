/**
 * DynReadIndicator
 * 
 * read the value from the bike dynamo and print on serial.
 * if the dynamo is giving charge, turn on LED at pin 2
 * 
 */


int dynPin = A0;
int ledPin = 2;
int dyn = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(dynPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Recieving...");  
}

void loop(){
  //loop this over and over
    dyn = analogRead(dynPin);//get dynamo output, send to board.
    //only print if there's data there
    if(dyn != 0){
      Serial.println(dyn, DEC);
      digitalWrite(ledPin, HIGH);//indicator LED on - generating
      delay(100);// on long enough to see
      digitalWrite(ledPin, LOW);//indicator off
    }
}//end loop
