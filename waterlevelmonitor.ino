const int trigPin = 2;
const int echoPin = 3;

int ledA = 13, ledB = 12, ledC = 11, ledD = 10;
const int levelA = 3, levelB = 4, levelC = 5, levelD = 6;  // Updated threshold distances

unsigned long emptyStartTime = 0, filledStartTime = 0;
unsigned long emptyDuration = 0, filledDuration = 0;
bool isFilled = false;
int emptyCount = 0;  // Count for empty instances in a day

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
}

void loop() {
  long duration, distanceInches;

  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure distance
  duration = pulseIn(echoPin, HIGH);
  distanceInches = (duration / 74) / 2;

  // Logic for LEDs based on water level
  if (distanceInches > 5.8) {
    // Tank is empty
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, HIGH);
    
    if (isFilled) {
      // Increment empty count only when transitioning to empty state
      emptyCount++;
      Serial.print("Empty Count for the Day: ");
      Serial.println(emptyCount);
      emptyStartTime = millis();
      isFilled = false;  // Update the state to empty
    }
  } 
  else if (distanceInches >= levelC && distanceInches <= 5.8) {
    // Low water level
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    isFilled = true;
  } 
  else if (distanceInches >= levelB && distanceInches < levelC) {
    // Medium water level
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    isFilled = true;
  } 
  else if (distanceInches < levelB) {
    // Highest water level
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    isFilled = true;
  }

  delay(1000);  // Adjust delay as needed
}