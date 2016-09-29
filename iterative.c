#include <stdio.h>
#include <stdint.h>

uint8_t clz(uint32_t x)
{
    int n = 0;
    if (x == 0) return 32;
    for (n = 0; ((x & 0x80000000) == 0); n++, x <<= 1);
    return n;
}

int main()
{
    int a = clz(1);
    printf("ans = %d\n",a);
    return 0;
}
