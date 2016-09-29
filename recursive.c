#include <stdio.h>
#include <stdint.h>

//half = 16
uint8_t clz(uint32_t x,int half)
{
	if(x == 0) return 32;
	if(half == 0) return 0;
	/* shift upper half down, rest is filled up with 0s */
	uint16_t upper = (x >> half); 
	// mask upper half away
	uint16_t lower = (x & (0x0000FFFF >> (16 - half)));
	return upper ? clz(upper,half>>1) : (half) + clz(lower,half>>1);
}

int main()
{
	int a = clz(1,16);
	printf("ans = %d\n",a);
	return 0;
}
