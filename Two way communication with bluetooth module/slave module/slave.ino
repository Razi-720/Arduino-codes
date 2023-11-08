//Code for Slave module//

#define ledPinSlave 8
#define switchSalve 7
int dataFromMaster = 0;

void setup() {
  pinMode(ledPinSlave, OUTPUT);
  digitalWrite(ledPinSlave, LOW);
  pinMode(switchSalve, INPUT);
  digitalWrite(switchSalve,LOW);
  Serial.begin(9600); // Default baud rate of the Bluetooth module.
}
void loop() {
 if(Serial.available() > 0){ // Checks whether data is coming from the serial port
   dataFromMaster = Serial.read(); // Reads the data from the serial port and store it in dataFromMaster variable
   Serial.println(dataFromMaster);
 }
 // Controlling the led
 if (dataFromMaster == '1') {
  digitalWrite(ledPinSlave, HIGH); // LED ON
 }
 else if (dataFromMaster == '0') {
  digitalWrite(ledPinSlave, LOW); // LED    OFF
 }
 
 // Reading the masterSwitchValue
 int slaveSwitchValue = digitalRead(switchSalve);
 if (slaveSwitchValue == HIGH) {
   Serial.write('1'); // Sends '1' to the master to turn on Led
 }
 else {
   Serial.write('0');
 }  

 delay(10);
}
