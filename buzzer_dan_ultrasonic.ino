#define triggerPin 12
#define echoPin 10

void setup() {

  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(6, OUTPUT);

}

void loop() {

  int duration, distance;
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;

  if(distance >=0 && distance <=15){
    
    Serial.print("Halangan dihadapan:   ");
    Serial.print(distance);
    Serial.println("  cm");
    tone(6,250);
    delay(100);
  }

    else {
    Serial.print(distance);
    Serial.println("  cm");
    noTone(6);
    delay(100);
    }
    
}
