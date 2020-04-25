#include "led.h"

void setRed()
{
  *(char*)0x22 |= 0x40;
  *(char*)0x21 |= 0x40;
}

void setRed1()
{
  *(char*)0x22 |= 0x40;
  *(char*)0x21 |= 0x40;
  dim_leds();
}

void setGreen()
{
  *(char*)0x22 |= 1;
  *(char*)0x21 |= 1;
}

void setGreen1()
{
  *(char*)0x22 |= 1;
  *(char*)0x21 |= 1;
  dim_leds();
}

void dim_leds()
{
  *(char*)0x22 &= 0xBF;
  *(char*)0x21 &= 0xBF;
  *(char*)0x22 &= ~1;
  *(char*)0x21 &= ~1;
  setRed1();
  setGreen1();
}
