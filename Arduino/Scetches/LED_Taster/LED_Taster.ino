#include "SoftwareSerial.h"

SoftwareSerial BluetoothDing(2, 3); //RX | TX
int flag = 0;

int LEDblau=6; 
int taster=7; 
bool tasterstatus;
bool tasterstatusBefore = 0;
bool tarrFunctionTriggered = 0; 
unsigned long startTime;

void setup() 
{
  Serial.begin(9600);
  BluetoothDing.begin(9600);
  pinMode(LEDblau, OUTPUT);
  Serial.println("Ready to connect\nDefualt password is 1234 or 000");
}

void loop()
{ 
  if(BluetoothDing.available()){
    flag = BluetoothDing.read();
    Serial.println(flag);
  }

  if (flag != 48 && flag != 0){
    digitalWrite(LEDblau, HIGH); 
    Serial.println("LED on");    
  }
  else if (flag == 48){ //48 == "0"
    digitalWrite(LEDblau, LOW);
    Serial.println("LED off");

  }

  // BluetoothDing.println("Test"); //writing works





 //Code for 2 Modes, pressing button short and long 
/*
  tasterstatus = digitalRead(taster); //need at least 2 states: next step, 
  if (tasterstatus == HIGH )
  { 
    if (tasterstatusBefore == LOW)
    {
      startTime = millis();
      Serial.println(startTime);
    }
    
    if ( millis() - startTime > 1000)
    {  
      tasterstatus = LOW; //call funktion not multiple times after target time is reached
      Tarr();
    }
  }

  if(tasterstatus == LOW && tasterstatusBefore == HIGH && !tarrFunctionTriggered){
    NextStep();
  }
  else{
    tarrFunctionTriggered = 0;
  }

  
    //update states, always last action in loop!!!
    tasterstatusBefore = tasterstatus;
*/
} 

void Tarr(){

  Serial.println("länger als 1 Sekunden gedrückt");
  tarrFunctionTriggered = 1;
  
  //lamp on means tarr function or so
  digitalWrite(LEDblau, HIGH); 
  delay (250); 
  digitalWrite(LEDblau, LOW);
  delay(250);
  digitalWrite(LEDblau, HIGH); 
  delay (250); 
  digitalWrite(LEDblau, LOW);
  delay(250);
  digitalWrite(LEDblau, HIGH); 
  delay (250); 
  digitalWrite(LEDblau, LOW);
}

void NextStep(){
  Serial.println("kurz gedrückt");
  digitalWrite(LEDblau, HIGH); 
  delay (1250); 
  digitalWrite(LEDblau, LOW);
}
