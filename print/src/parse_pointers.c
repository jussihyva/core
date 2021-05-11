/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

int	parse_pointer(t_data *specs, void *ptr, char **result)
{
	uintmax_t	value;
	char		*value_str;
	size_t		result_len;

	value = (uintmax_t)ptr;
	value_str = ft_uintmax_itoa_base(value, 16, 0);
	if (value_str == NULL)
		return (-1);
	result_len = s_len(value_str) + 2;
	specs->conversion = 'x';
	specs->alt_form = 1;
	specs->has_precision = 0;
	specs->precision = 0;
	if (specs->min_field_width > result_len)
		specs->min_field_width = specs->min_field_width - result_len;
	else
		specs->min_field_width = 0;
	result_len += specs->min_field_width;
	*result = parse_int_result(specs, value_str, result_len);
	free(value_str);
	if (*result == NULL)
		return (-1);
	return (result_len);
}
