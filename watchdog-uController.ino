/*USB hardware watchdog, relay have to connect the reset ATX header 2 pins
only start wathing after the software in PC start sending data
the software into PC have to send data each second on serial port via USB at 115200 */
const int relayPin = 2;//ESP32 have LED on pin 2, then more visual

void setup() {
  Serial.begin(115200);	// opens serial port, sets data rate to 9600 bps
  pinMode(relayPin, OUTPUT); //Set relay pin
  digitalWrite(relayPin, HIGH);
}

void loop()
{
  while(Serial.available()<=0)
  {}
  //Serial.println("Start watching...");
  int count=0;
  while(count<10)
  {
    if(Serial.available()>0)
    {
      int incomingByte=Serial.read();
      while(Serial.available()>0)
        incomingByte=Serial.read();
      count=0;
    }
    else
    {
      count++;
      if(count<10)
        delay(1000);
    }
  }
  //Serial.println("timeout, rebooting");
  digitalWrite(relayPin, LOW); //Hit reset button
  delay(1000);
  digitalWrite(relayPin, HIGH);
}
