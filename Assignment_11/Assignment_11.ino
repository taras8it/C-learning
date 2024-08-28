/******************************************
 * Author: Oleksandr Kuprii 510190
 * Description: Assignment 11.2 – - Snake Byte (Arduino)
 * Date: 18-11-2021
 *****************************************/
#define initial_state B00000100


void setup()
{
  DDRD = B11111100;
  PORTD = initial_state;
}

void loop()
{
  if (PORTD == B10000000) {
  	PORTD = initial_state;
  } else {
	PORTD = PORTD << 1;
  }
  delay(1000);
}
