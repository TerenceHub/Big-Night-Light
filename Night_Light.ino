/*
110V Night LIGHT (time extended for 30 seconds)

Author: Terence
Refer to http://blog.ddt.idv.tw/2014/10/arduino.html
*/


#define lightPin 0            // analog Photoresistor pin
#define relayPin 9            // set relay pin
int lightLevel = 0;           // light level red from analog Photoresistor pin, 
                              // black is about 1000, general light is about 400

int lightThreshold = 950;     // threshold value to turn on Light 
int darkThreshold = 850;      // threshold value to resume Light 
int duration = 30000;         // Light ON duration
boolean lightStatus = true;   // Light status, initial = ture, turned on then off = false


void setup()
{
  pinMode(relayPin, OUTPUT);     // set relay pin to ourput
  //Serial.begin(9600);
}

void lightOn() {
  digitalWrite(relayPin, HIGH);    // turn on Light
  delay(duration);                 // hold on for time duration
  digitalWrite(relayPin, LOW);     // turn off Light
}

void lightOff() {
  digitalWrite(relayPin, LOW);    // turn off the Light
}


void loop()
{
  lightLevel = analogRead(lightPin);    // read the light level
  delay(100);                            // wait for 100ms for analog pin reading 
  
  /*
  Serial.print("light level = ");
  Serial.println(lightLevel);
  Serial.print(" Light Status = ");
  Serial.println(lightStatus);
  delay(200);
  */
  
  if ( (lightStatus == true) && (lightLevel >= lightThreshold) )
  {
    lightOn();                        // turn on light
    lightStatus = false;              // change Light status to false
    delay(1000);                      // delay to make sure status changed to false
  }
  
  else if ((lightStatus == false) && (lightLevel >= lightThreshold) )
  {
    lightOff();                      // stay turnning Light off when Light Status = false
    lightStatus = false;             // keep Light status false
    delay(500);                      // delay to make sure light is off
  }
  
  else if ((lightStatus == false) && (lightLevel < darkThreshold) )                             
  {
    lightStatus = true;             // set light status = ture (initial status)
    delay(500);                     // delay to make sure light is off
  }
}
  
