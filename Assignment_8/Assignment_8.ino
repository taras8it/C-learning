/******************************************
 * Author: Oleksandr Kuprii 510190
 * Description: Assignment 8.2 – Cross-fading three LEDs
 * Date: 28-10-2021
 *****************************************/
#define POT A0
#define LED1 3
#define LED2 5
#define LED3 6


void setup() {
  pinMode(POT, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}


void loop() {
  int pot;
  pot = analogRead(POT);
  
  pot = map(pot, 0, 1023, 0, 255);
  
  // LED1
  if (pot <= 127) {
    analogWrite(LED1, 255 - 2 * pot);
  } else {
    analogWrite(LED1, 0);
  }

  // LED2
  if (pot <= 127) {
    analogWrite(LED2, 2 * pot);
  } else {
    analogWrite(LED2, 255 - 2 * pot);
  }

  // LED3
  if (pot >= 128) {
    analogWrite(LED3, 2 * (pot - 128));
  } else {
    analogWrite(LED3, 0);
  }
}
