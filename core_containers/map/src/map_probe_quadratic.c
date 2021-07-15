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

#include "../../../inc/core.h"

static inline t_int64	m_ipow(t_int64 base, t_int64 exp)
{
	t_int64			tmp;
	t_int64			i;

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

t_uint64	map_probe_quadratic(t_uint64 x)
{
	return ((m_ipow(x, 2) + x) / 2);
}
