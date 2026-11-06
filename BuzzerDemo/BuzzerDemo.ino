#include <Arduino.h>

const byte buzzerPin = 13;
// Left to right in docs/circuit.png.
const byte ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const uint16_t testFrequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
const byte ledCount = sizeof(ledPins) / sizeof(ledPins[0]);
const byte noteCount = sizeof(testFrequencies) / sizeof(testFrequencies[0]);

static_assert(noteCount == ledCount, "Each test tone needs one LED.");

void setup() {
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  for (byte i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  for (byte i = 0; i < noteCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    tone(buzzerPin, testFrequencies[i]);
    delay(500);
    noTone(buzzerPin);
    digitalWrite(ledPins[i], LOW);
    delay(80);
  }
}

// Press RESET to play the test again.
void loop() {}
