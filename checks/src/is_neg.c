/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief return 1 if `n` is negative.
 *
 *****************************************************************************/

#include "../../inc/core.h"

int	is_neg(intmax_t n)
{
	if (n < 0)
		return (1);
	return (0);
}
