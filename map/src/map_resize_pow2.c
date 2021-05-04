/*******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 ******************************************************************************/

#include "../inc/map.h"

uint64_t	map_resize_pow2(uint64_t capacity)
{
	return (pow(2, ceil(log(capacity) / log(2))));
}
