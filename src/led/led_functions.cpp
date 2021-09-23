#include "led_functions.h"

void powerOnLed(byte pin)
{
  digitalWrite(pin, HIGH);
}

void powerOffLed(byte pin)
{
  digitalWrite(pin, LOW);
}

void setupLed(byte pin)
{
  pinMode(pin, OUTPUT);
}