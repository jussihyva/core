/*******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 ******************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	char	*result;
	int		ret;

	result = NULL;
	va_start(ap, format);
	ret = ft_vasprintf(&result, format, ap);
	va_end(ap);
	if (ret != -1)
	{
		if (write(fd, result, ret) == -1)
			ret = -1;
	}
	free(result);
	return (ret);
}
