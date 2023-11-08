#define greenled 3
#define redled 2
float pH_Value; 
float Voltage;
void setup() 
{ 
  Serial.begin(9600);
  pinMode(pH_Value, INPUT);
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT); 
} 
 
void loop() 
{ 
  pH_Value = analogRead(A0); 
  Voltage = pH_Value * (5.0 / 1023.0); 
  Serial.println(Voltage);
  if(pH_Value>=7.5)
  {
    digitalWrite(greenled, HIGH);
  }
  else 
  {
    digitalWrite(greenled, LOW);
  }
  if(pH_Value<=6.5)
  {
    digitalWrite(redled, HIGH);
  }
  else
  {
    digitalWrite(redled, LOW);
  }
  delay(100); 
}
