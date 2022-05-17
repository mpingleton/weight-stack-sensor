#define echoPin 2
#define triggerPin 4

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);

  Serial.begin(115200);
  
}

void loop() {

}
