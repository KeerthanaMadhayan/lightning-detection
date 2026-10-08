int potPin = A0;

int greenLED = 8;
int blueLED = 9;
int orangeLED = 10;
int redLED = 11;

int buzzer = 12;

void setup() {
  Serial.begin(9600);

  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(orangeLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {

  int potValue = analogRead(potPin);

  // Convert potentiometer value (0-1023) to risk percentage (0-100)
  int risk = map(potValue, 0, 1023, 0, 100);

  // Turn OFF all LEDs and buzzer
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(orangeLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);

  // Risk level indication
  if (risk < 25) {

    // Normal
    digitalWrite(greenLED, HIGH);
  }

  else if (risk < 50) {

    // Moderate
    digitalWrite(blueLED, HIGH);
  }

  else if (risk < 75) {

    // High
    digitalWrite(orangeLED, HIGH);
  }

  else {

    // Very High
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  // Serial Monitor
  Serial.print("Pot Value: ");
  Serial.print(potValue);

  Serial.print(" | Risk Level: ");
  Serial.print(risk);
  Serial.println("%");

  delay(200);
}