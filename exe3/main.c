#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_RED = 28;
const int BTN_PIN_GREEN = 26;
const int LED_RED = 4;
const int LED_GREEN = 6;

int main() {
  bool green_on=false;
  bool red_on=false;
  stdio_init_all();

  gpio_init(BTN_PIN_RED);
  gpio_set_dir(BTN_PIN_RED, GPIO_IN);
  gpio_pull_up(BTN_PIN_RED);

  gpio_init(BTN_PIN_GREEN);
  gpio_set_dir(BTN_PIN_GREEN, GPIO_IN);
  gpio_pull_up(BTN_PIN_GREEN);

  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);

  gpio_init(LED_GREEN);
  gpio_set_dir(LED_GREEN, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN_PIN_RED)) {
      if(!red_on){
        gpio_put(LED_RED,1);
        red_on=true;
      }
      else{
        gpio_put(LED_RED,0);
        red_on=false;
      }
    }
    if (!gpio_get(BTN_PIN_GREEN)) {
      if(!green_on){
        gpio_put(LED_GREEN,1);
        green_on=true;
      }
      else{
        gpio_put(LED_GREEN,0);
        green_on=false;
      }
    }

  }
}
