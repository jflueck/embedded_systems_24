#include "ecs.h"
#include "S32K144.h"
#include "gpio.h"
#include "qd.h"
#include "adc.h"
static uint8_t LED_state;

#define SECTION 2

int main(void) {

  initECS();
	init_ADC0_single();
	uint32_t iAnalog;

  #if SECTION == 1
    while (1) {
      iAnalog = read_ADC0_single(0b000000);
    }

  #elif SECTION == 2
    initGPDO(3, 0);

    while (1) {
      if(read_ADC0_single(0b000000) < 2500){ // middle of the shifted sine wave with offset = 2.5V
    	  writeGPIO(3, 0, 0b0);
      }
      else {
     	  writeGPIO(3, 0, 0b1);
    }
 }

  #endif

}
