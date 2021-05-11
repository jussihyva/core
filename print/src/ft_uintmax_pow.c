/*******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 ******************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

uintmax_t	ft_uintmax_pow(int base, int power)
{
	uintmax_t	result;

	result = 1;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}
