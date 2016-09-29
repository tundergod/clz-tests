#include <stdio.h>
#include "clz.h"

int main(int argc, char const *argv[])
{
    //__attribute__((unused)) int N = 100000000;
    int ans;
    int x = 1;

#if defined(CLZ1)
    ans = clz_recursive(x,16);
#endif

#if defined(CLZ2)
    ans = clz_iteration(x);
#endif

#if defined(CLZ3)
    ans = clz_binary(x);
#endif

#if defined(CLZ4)
    ans = clz_byte(x);
#endif

#if defined(CLZ5)
    ans = clz_harley(x);
#endif

    printf("ans = %d\n",ans);

    return 0;
}

