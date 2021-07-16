#include "../inc/rng.h"
#include "../inc/rng_seed.h"

void	rng_seed(unsigned int seed)
{
	g_rand_next = seed;
}
