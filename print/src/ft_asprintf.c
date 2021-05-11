/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

int	ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	int		ret_value;

	va_start(ap, format);
	*ret = NULL;
	ret_value = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (ret_value);
}
