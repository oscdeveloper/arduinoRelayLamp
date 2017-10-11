unsigned int pinMicrophone = 10;

unsigned int pinRelay1 = 11;
unsigned int pinRelay2 = 12;

bool micStatus = false;
bool relay1 = false;
bool relay2 = false;

unsigned long time1;

unsigned int counter = 0;

void setup() 
{

  pinMode (pinMicrophone, INPUT);
  pinMode (pinRelay1, OUTPUT);
  pinMode (pinRelay2, OUTPUT);
  
  digitalWrite(pinRelay1, LOW);
  digitalWrite(pinRelay2, LOW);

  time1 = millis();
  
  //Serial.begin(9600);  
  
}

void loop() {
  
  micStatus = digitalRead(pinMicrophone);
  
  if ( micStatus == LOW ) {

    counter++;
    
    if ( counter == 1 ) {
      time1 = millis();      
    }
    
    delay(500);
    
  } // if ( micStatus == LOW ) {

//  Serial.print(counter);
//  Serial.print("\t");

  if ( counter == 1 && ( ( millis() - time1 ) > 1500 ) ) {      
    relay1 = !relay1;
    digitalWrite(pinRelay1, relay1);
    counter = 0;      
  } else if ( counter > 1 ) {
    relay2 = !relay2;
    digitalWrite(pinRelay2, relay2);
    counter = 0;        
  }

//  Serial.print(relay1);
//  Serial.print("\t");
//  Serial.println(relay2);

}
