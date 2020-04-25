#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state_changed;

int cur_state = 0;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

int determineState(char p2val)
{
  if (p2val & SW1 ? 0 : 1)
    return 1;
  if (p2val & SW2 ? 0 : 1)
    return 2;
  if (p2val & SW3 ? 0 : 1)
    return 3;
  if (p2val & SW4 ? 0 : 1)
    return 4;
  return 0;
}

void switch_interrupt_handler()
{
  switch_state_changed = 0;
  char p2val = switch_update_interrupt_sense();
  cur_state = determineState(p2val);

  switch(cur_state) {
  case 1:
    setGreen();
    break;
  case 2:
    setGreen();
    setRed();
    buzzer_set_period(1000);
    break;
  case 3:
    dim_leds();
    buzzer_set_period(2000);
    break;
  case 4:
    setRed();
    break;
  default:
    break;
  }
  if (cur_state < 5)
    switch_state_changed = 1;
}
