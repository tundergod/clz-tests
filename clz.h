#include <stdio.h>
#include <stdint.h>
uint8_t clz_recursive(uint32_t x,int half);
uint8_t clz_iteration(uint32_t x);
uint8_t clz_binary(uint32_t x);
unsigned clz_byte(uint32_t x);
uint8_t clz_harley(uint32_t x);
