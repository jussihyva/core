/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief  Gives next power of two resize for a hash map.
 *
 * \param capacity Current capacity of the hash map.
 *
 * \return Value that can be used to grow the hash map.
 *
 ******************************************************************************/

#include "../inc/map.h"

uint64_t	map_resize_pow2(uint64_t capacity)
{
	return (pow(2, ceil(log(capacity) / log(2))));
}
