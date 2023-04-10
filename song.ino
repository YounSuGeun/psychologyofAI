// Define the speaker pin
#define SPEAKER_PIN 9

// Define the melody notes and durations
int melody[] = {262, 294, 330, 262, 392, 330, 262, 294, 262, 0, 262, 294, 330, 262, 392, 330, 262, 294, 262, 0, 262, 523, 523, 392, 330, 262, 294, 330, 349, 294, 262, 262, 294, 330, 262, 392, 330, 262, 294, 262};
int noteDurations[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2};

void setup() {
  // Initialize the speaker pin
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  // Loop through the melody notes and play them
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(SPEAKER_PIN, melody[i], noteDuration);
    delay(noteDuration * 1.3);
    noTone(SPEAKER_PIN);
  }
}
