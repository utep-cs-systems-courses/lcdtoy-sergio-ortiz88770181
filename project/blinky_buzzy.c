#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "shape.h"
#include "lcdutils.h"

int main(void)
{
  configureClocks();
  buzzer_init();
  switch_init();
  lcd_init();
  shapeInit();
  or_sr(0x18);
}
