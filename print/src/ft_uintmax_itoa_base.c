/*******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 ******************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

char	*ft_uintmax_itoa_base(uintmax_t value, int base, int uppercase)
{
	char	*result;
	char	*digits;
	char	temp[64 + 1];
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	i = 64;
	temp[i--] = '\0';
	if (value == 0)
		temp[i--] = '0';
	while (value != 0)
	{
		temp[i--] = digits[value % base];
		value = value / base;
	}
	result = (char *)malloc(64 - i + 1);
	if (result == NULL)
		return (NULL);
	return (s_cpy(result, &temp[i + 1]));
}
