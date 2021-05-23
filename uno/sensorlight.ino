#define TRIG 9 
#define ECHO 8
int LED = 12;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);   
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  float duration = pulseIn (ECHO, HIGH);
  float distance = ((float)(340*duration)/10000)/2;

  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print("\nDistance :");
  Serial.print(distance);
  Serial.println("cm\n");
  
  if (distance <= 5) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
  delay(100);
}
