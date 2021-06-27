#include "../../inc/core.h"

t_int32	test_rng(t_int32 min, t_int32 max, t_int32 seed)
{
	srand(seed);
	return (min + rand() / (RAND_MAX / (max - min + 1) + 1));
}
