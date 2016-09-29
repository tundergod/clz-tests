#include <stdio.h>
#include <stdint.h>

uint8_t clz(uint32_t x)
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

int main()
{
        int a = clz(1);
        printf("ans = %d\n",a);
        return 0;
}
