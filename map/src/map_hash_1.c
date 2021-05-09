/*******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 ******************************************************************************/

#include "../inc/map.h"
#include "../../inc/core.h"

/*uint64_t	map_hash_1(const char *key)*/
/*{*/
	/*uint64_t	hash;*/
	/*uint64_t	i;*/
	/*uint64_t	len;*/

	/*len = s_len(key);*/
	/*hash = 0;*/
	/*i = 0;*/
	/*while (i < len)*/
	/*{*/
		/*hash += key[i];*/
		/*hash += (hash << 10);*/
		/*hash ^= (hash >> 6);*/
		/*i++;*/
	/*}*/
	/*hash += (hash << 3);*/
	/*hash ^= (hash >> 11);*/
	/*hash += (hash << 15);*/
	/*return (hash);*/
/*}*/

#define _PADr_KAZE(x, n) ( ((x) << (n))>>(n) )
uint64_t map_hash_1(const char *str)
{
	size_t wrdlen = s_len(str);
	const uint32_t PRIME = 591798841; uint32_t hash32; uint64_t hash64 = 14695981039346656037LLU;
	size_t Cycles, NDhead;
if (wrdlen > 8) {
	Cycles = ((wrdlen - 1)>>4) + 1; NDhead = wrdlen - (Cycles<<3);
#pragma nounroll
        for(; Cycles--; str += 8) {
		hash64 = ( hash64 ^ (*(uint64_t *)(str)) ) * PRIME;        
		hash64 = ( hash64 ^ (*(uint64_t *)(str+NDhead)) ) * PRIME;        
	}
} else
	hash64 = ( hash64 ^ _PADr_KAZE(*(uint64_t *)(str+0), (8-wrdlen)<<3) ) * PRIME;        
hash32 = (uint32_t)(hash64 ^ (hash64>>32)); return hash32 ^ (hash32 >> 16);
} // Last update: 2019-Oct-30, 14 C lines strong, Kaze.
