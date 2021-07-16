#include "../inc/rng.h"
#include "../inc/rng_seed.h"

t_uint32	rng()
{
	g_rand_next = g_rand_next * 1103515245 + 12345;
	return ((t_uint32)(g_rand_next / 65536) % 32768);
}
