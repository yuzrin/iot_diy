int SensorPin = 2;
int RelayPin = 13;


void setup() {
  pinMode(RelayPin,OUTPUT);
  pinMode(SensorPin,INPUT);
  Serial.begin(9600);

}

void loop() {

  if(digitalRead(SensorPin) == HIGH)
  Serial.println("Motion Detected !!");
  digitalWrite(RelayPin, HIGH);
  delay(3000);
}
  else {
  
  Serial.println("Clear");
  digitalWrite(RelayPin, LOW);
  delay(1000);
  }
}
