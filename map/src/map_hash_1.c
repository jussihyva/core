/*******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 ******************************************************************************/

#include "../inc/map.h"
#include "../../inc/core.h"

uint64_t	map_hash_1(const char *key)
{
	uint64_t	hash;
	uint64_t	i;
	uint64_t	len;

	len = s_len(key);
	hash = 0;
	i = 0;
	while (i < len)
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
		i++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}
