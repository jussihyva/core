/*******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief Return 1 if `n` is negative.
 *
 ******************************************************************************/

#include "../../inc/core.h"

int	is_negf(double n)
{
	uint64_t	double_as_int;
	uint8_t		sign;

	mem_cpy_safe(&double_as_int, &n, sizeof(n));
	sign = (uint8_t)(double_as_int >> 63);
	if (sign == 0)
		return (CR_FALSE);
	return (CR_TRUE);
}
