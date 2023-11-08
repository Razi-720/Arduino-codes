//Code for master module//

#define ledpinMaster 8
#define switchMaster 7
int dataFromSlave = 0;

void setup() {
  pinMode(ledpinMaster, OUTPUT);
  digitalWrite(ledpinMaster, LOW);
  pinMode(switchMaster, INPUT);
  digitalWrite(switchMaster,LOW);
  Serial.begin(9600); // Default baud rate of the Bluetooth module
}
void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
   dataFromSlave = Serial.read(); // Reads the data from the serial port and store it in dataFromSlave variable
 }
 // Controlling the Buzzer
 if (dataFromSlave == '1') {
  digitalWrite(ledpinMaster, HIGH); // led ON
 }
 else if (dataFromSlave == '0') {
  digitalWrite(ledpinMaster, LOW); // led OFF
 }
 
 // Reading the masterSwitchValue
 int masterSwitchValue = digitalRead(switchMaster);
 if (masterSwitchValue == HIGH) {
   Serial.write('1'); // Sends '1' to the master to turn on led
 }
 else {
   Serial.write('0');
 }  
 delay(10);
}
