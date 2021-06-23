#include "../../inc/core.h"

t_int32	test_rand(t_int32 seed)
{
	srand(seed);
	return (rand());
}
