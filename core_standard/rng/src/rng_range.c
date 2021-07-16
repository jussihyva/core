#include "../inc/rng.h"

t_int32	rng_range(t_int32 min, t_int32 max)
{
	min += 1;
	max += 1;
	return (rng() % (max - min) + min - 1);
}