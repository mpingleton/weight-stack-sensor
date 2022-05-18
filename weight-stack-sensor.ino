#define echoPin 2
#define triggerPin 4

char inputBuffer[2] = {0, 0};

bool pushBuffer(char c) {
  // Move the characters.
  inputBuffer[0] = inputBuffer[1];
  inputBuffer[1] = c;

  // Compare them.
  return (inputBuffer[0] == 'A' && inputBuffer[1] == 'D');
}

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
  if(Serial.available()) {
    char c = Serial.read();
    
    if(pushBuffer(c)) {
      Serial.println(ping());
    }
  }
  else {
    delay(2);
  }
}
