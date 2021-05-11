/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief  Gives next power of two resize for a hash map.
 *
 * \param capacity Current capacity of the hash map.
 *
 * \return Value that can be used to grow the hash map.
 *
 *****************************************************************************/

#include "../inc/map.h"
#include "../../inc/core.h"

static inline int64_t	m_ipow(int64_t base, int64_t exp)
{
	int64_t			tmp;
	int64_t			i;

	i = 0;
	tmp = base;
	if (base == 0 && exp == 0)
		return (1);
	else if (base == 0)
		return (0);
	else if (exp == 0)
		return (1);
	while (i < exp - 1)
	{
		tmp *= base;
		i++;
	}
	return (tmp);
}

uint64_t	map_resize_pow2(uint64_t capacity)
{
	return (m_ipow(2, ceil(log(capacity) / log(2))));
}
