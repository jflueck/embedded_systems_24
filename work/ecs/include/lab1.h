#include <cstdint>

#define BASE_PORT_D 0x4004C000
#define BASE_PORT_E 0x4004D000

#define BASE_GPIO 0x400FF000
#define GPIOD_OFFSET 0x0C0
#define GPIOE_OFFSET 0x100

typedef struct {
    volatile uint32_t PDOR;
    volatile uint32_t PSOR;
    volatile uint32_t PCOR;
    volatile uint32_t PTOR;
    volatile const uint32_t PDIR;
    volatile uint32_t PDDR;
    volatile uint32_t PIDR;
} GPIO_mem;
