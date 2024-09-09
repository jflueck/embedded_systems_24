#include "eecs461.h"
#include <stdint.h>

#define SECTION 1
#if SECTION == 1
#include "lab1.h"

void main() {
    volatile uint32_t * const portD_PCR = 0x44; 
    volatile uint32_t * const portE_PCR = (uint32_t *)(BASE_PORT_E);
    GPIO_mem * const gpioD = (GPIO_mem *)(BASE_GPIO + GPIOD_OFFSET);
    GPIO_mem * const gpioE = (GPIO_mem *)(BASE_GPIO + GPIOE_OFFSET);

    uint16_t sum, value1, value2;
    uint32_t regReadVal;
    int index;

    /* Configure the LED pins */
    for (index = 0; index < 5; index++) {
        /* Configure pin mux to gpio */
        portD_PCR[index] = 0b001 << 8;
        /* Set the direction to output */
        gpioD->PDDR |= 0b1 << index;
    }

    /* Configure the DIP pins */
    for (index = 6; index < 14; index++) {
        /* Configure pin mux to gpio */
        portE_PCR[index] = 0b001 << 8;
        /* Set the direction to input */
        gpioE->PDDR &= ~(1 << index);
    }
}
