#include "inc/core.h"

size_t	iters = 1000000000;

float fastsqrt(float val)  {
        union
        {
                int tmp;
                float val;
        } u;
        u.val = val;
        u.tmp -= 1<<23; /* Remove last bit so 1.0 gives 1.0 */
        /* tmp is now an approximation to logbase2(val) */
        u.tmp >>= 1; /* divide by 2 */
        u.tmp += 1<<29; /* add 64 to exponent: (e+127)/2 =(e/2)+63, */
        /* that represents (e/2)-64 but we want e/2 */
        return u.val;
}

int main(void)
{
	size_t	i;
	double	res;

	i = 0;
	res = 0;
	while (i < iters)
	{
		res += math_sqrt(123456789.123456789);
		i++;
	}
	print("%lf", res);
}
