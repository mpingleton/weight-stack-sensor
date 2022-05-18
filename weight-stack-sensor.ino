#define echoPin 2
#define triggerPin 4

unsigned long ping() {
  // Turn the pin 13 LED on.
  digitalWrite(13, HIGH);
  
  // Pulse the trigger pin.
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the pulse from the echo pin.
  unsigned long d = pulseIn(echoPin, HIGH);

  digitalWrite(13, LOW);
  return d;
}

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  delay(100);
  Serial.println(ping());
}
