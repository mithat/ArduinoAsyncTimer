// Shows the use of an AsyncTimer with both time-out and start actions.
// This example code is in the public domain.

#include <AsyncTimer.h>

const unsigned int LED_PIN = 13;

AsyncTimer ledTimer(4000, ledOff, ledOn); // time, timeout and start actions.

void setup() {
  pinMode(LED_PIN, OUTPUT);
  ledTimer.start(); // Start the timer.
}

void loop() {
  ledTimer.checkExpiration();   // Check it every loop iteration.
}

/** Action that is called when ledTimer starts. */
void ledOn() {
  digitalWrite(LED_PIN, HIGH);
}

/** Action that is called when ledTimer times out. */
void ledOff() {
  digitalWrite(LED_PIN, LOW);
}
