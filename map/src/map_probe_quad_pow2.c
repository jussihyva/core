/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief  Probing function P(x) = (x^2 + x) / 2
 *
 * \param x Probing increment
 *
 * \return Value to be added to hash value to move to the next index
 *
 *****************************************************************************/

#include "../inc/map.h"
#include "../../inc/core.h"

uint64_t	map_probe_quad_pow2(uint64_t x)
{
	return ((pow(x, 2) + x) / 2);
}
