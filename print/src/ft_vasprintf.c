/*******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 ******************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int		ret_value;
	va_list	ap_copy;

	va_copy(ap_copy, ap);
	*ret = NULL;
	ret_value = parse(format, &ap_copy, ret);
	va_end(ap_copy);
	return (ret_value);
}
