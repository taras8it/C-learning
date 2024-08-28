/******************************************
 * Author: Oleksandr Kuprii 510190
 * Description: Assignment 7.2 – Wider scanner light (KITT)
 * Date: 14-10-2021
 *****************************************/
#define DELAY 300
#define LED_NUMBER 7


const int LED[LED_NUMBER] = {2, 3, 4, 5, 6, 7, 8};

void setup() {  
  for (int i = 0; i < LED_NUMBER; i++) {
     pinMode(LED[i], OUTPUT);
  }

  digitalWrite(LED[0], HIGH);
  digitalWrite(LED[1], HIGH);
}



void loop() {
  for (int i = 2; i < LED_NUMBER; i++) {
     digitalWrite(LED[i], HIGH);
     digitalWrite(LED[i-2], LOW);
     delay(DELAY);
  }

  for (int i = LED_NUMBER - 3; i >= 0; i--) {
     digitalWrite(LED[i], HIGH);
     digitalWrite(LED[i+2], LOW);
     delay(DELAY);
  }
}
