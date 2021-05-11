/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../inc/map.h"
#include "../../inc/core.h"

static inline uint64_t	shift(uint64_t x, uint64_t n)
{
	return ((x << n) >> n);
}

uint64_t	map_hash_1(const char *str)
{
	size_t		wrdlen;
	uint32_t	prime;
	uint64_t	hash64;
	size_t		cycles;
	size_t		ndhead;

	prime = 591798841;
	hash64 = 14695981039346656037LLU;
	wrdlen = s_len(str);
	if (wrdlen > 8)
	{
		cycles = ((wrdlen - 1) >> 4) + 1;
		ndhead = wrdlen - (cycles << 3);
		while(cycles--)
		{
			hash64 = (hash64 ^ (*(uint64_t *)(str))) * prime;
			hash64 = (hash64 ^ (*(uint64_t *)(str + ndhead))) * prime;
			str += 8;
		}
	}
	else
		hash64 = (hash64 ^ shift(*(uint64_t *)(str + 0),
		(8 - wrdlen) << 3)) * prime;
	return (hash64 ^ (hash64 >> 32));
}
