#include <stdio.h>
#include <stdint.h>

#include "clz.h"
uint8_t clz_recursive(uint32_t x,int half)
{
        if(x == 0) return 32;
        if(half == 0) return 0;
        /* shift upper half down, rest is filled up with 0s */
        uint16_t upper = (x >> half);
        // mask upper half away
        uint16_t lower = (x & (0x0000FFFF >> (16 - half)));
        return upper ? clz_recursive(upper,half>>1) : (half) + clz_recursive(lower,half>>1);
}

uint8_t clz_iteration(uint32_t x)
{
        int n = 0;
        if (x == 0) return 32;
        for (n = 0; ((x & 0x80000000) == 0); n++, x <<= 1);
        return n;
}

uint8_t clz_binary(uint32_t x)
{
   int n = 0;
   if (x == 0) return(32);
   if (x & 0x0000FFFF) {n = n +16; x = x <<16;}
   if (x & 0x00FFFFFF) {n = n + 8; x = x << 8;}
   if (x & 0x0FFFFFFF) {n = n + 4; x = x << 4;}
   if (x & 0x3FFFFFFF) {n = n + 2; x = x << 2;}
   if (x & 0x7FFFFFFF) {n = n + 1;}
   return n;
}

unsigned clz_byte(uint32_t x) 
{
    if (x == 0) return 32;
    int n = 1;
    if ((x >> 16) == 0) { n += 16; x <<= 16; }
    if ((x >> 24) == 0) { n += 8; x <<= 8; }
    if ((x >> 28) == 0) { n += 4; x <<= 4; }
    if ((x >> 30) == 0) { n += 2; x <<= 2; }
    n = n - (x >> 31);
    return n;
}

uint8_t clz_harley(uint32_t x)
{
    static unsigned char table [48] = {
        32,  6,  5,  0,  4, 12,  0, 20,
        15,  3, 11,  0,  0, 18, 25, 31,
        8, 14,  2,  0, 10,  0,  0,  0,
        0,  0,  0, 21,  0,  0, 19, 26,
        7,  0, 13,  0, 16,  1, 22, 27,
        9,  0, 17, 23, 28, 24, 29, 30
    };

    x = x | (x >> 1);    // Propagate leftmost
    x = x | (x >> 2);    // 1-bit to the right.
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x & ~(x >> 16);
    x = x * 0x3EF5D037;
    return table[x >> 26];
}

