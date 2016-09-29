#include <stdio.h>
#include <stdint.h>

uint8_t clz(uint32_t x)
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

int main()
{
        int a = clz(1);
        printf("ans = %d\n",a);
        return 0;
}
