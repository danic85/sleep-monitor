int sensePin = 0; // Analog 0
int ledPin = 9; // Digital 9
int minRead = 99999;
int maxRead = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read from sensor
  int thisRead = analogRead(sensePin);

  // Set max and min range (if appropriate)
  if (thisRead < minRead) minRead = thisRead;
  if (thisRead > maxRead) maxRead = thisRead;

  // Set LED output
  int ledLevel = map(thisRead, minRead, maxRead, 255, 0);
  analogWrite(ledPin, ledLevel);
}
