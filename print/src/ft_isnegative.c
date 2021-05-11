/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

int	ft_isnegative(double nbr)
{
	unsigned long long	double_as_int;
	unsigned char		sign;

	mem_cpy(&double_as_int, &nbr, sizeof(nbr));
	sign = (unsigned char)(double_as_int >> 63);
	if (sign == 0)
		return (0);
	else
		return (1);
}
