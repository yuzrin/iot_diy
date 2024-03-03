/*
  on Sep 23, 2020
  by MohammedDamirchi
  https://electropeak.com/learn/
*/

const byte interruptPin = 2;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(interruptPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}


// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(interruptPin) == HIGH) {
    Serial.println("motion detected");
    digitalWrite(LED_BUILTIN, HIGH);
  } 
  else {
    Serial.println("No movement");
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(2000);
  } 
