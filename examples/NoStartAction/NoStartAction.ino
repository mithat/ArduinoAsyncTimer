/* 
 * Shows the use of an AsyncTimer with only a time-out action (i.e., no start 
 * action.
 * 
 * This example code is in the public domain.
 */

#include <AsyncTimer.h>

const unsigned int LED_PIN = 13;

/** Action that is called when ledTimer times out. */
void ledOff() {
  digitalWrite(LED_PIN, LOW);
}

AsyncTimer ledTimer(4000, ledOff);	// milliseconds to delay ledOff execution.

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  	// Turn LED on.
  ledTimer.start(); 				// Start the timer.
}

void loop() {
  ledTimer.checkExpiration();   	// Check timer every loop iteration.
}

