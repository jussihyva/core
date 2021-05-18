/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

static int	_index(char c)
{
	size_t	i;

	i = 0;
	while (types[i] && types[i] != c)
		i++;
	return (i);
}

static int	append_to_result(char **result, int len, int ret, const char *str)
{
	static size_t	arr_size = 100;

	if (*result == NULL)
	{
		*result = mem_alloc(arr_size + 1);
		if (*result == NULL)
			return (-1);
	}
	if ((size_t)(ret + len) > arr_size)
	{
		*result = _realloc(*result, arr_size, arr_size * 2 + (size_t)ret + 1);
		if (*result == NULL)
			return (-1);
		arr_size = arr_size * 2 + (size_t)ret;
	}
	mem_cpy_safe(&(*result)[len], str, (size_t)ret);
	return (ret);
}

static int	parse_next_item(
	const char *format,
	va_list *ap,
	char **result,
	int len)
{
	t_data	specs;
	char	*container;

	int		ret;

	container = NULL;
	if (*format == '%')
	{
		mem_set((void *)&specs, 0, sizeof(t_data));
		_get_conversion_specs(&specs, format + 1);
		specs.ap = ap;
		ret = conv[_index(specs.conversion)](&specs, &container);
		if (ret == -1)
			return (-1);
		ret = append_to_result(result, len, ret, container);
		s_del(&container);
	}
	else
		ret = append_to_result(result, len, 1, format);
	return (ret);
}

static int	format_item_length(const char *format)
{
	t_data	conversion_specs;
	int		i;

	i = 0;
	if (format[i] == '%')
		i = _get_conversion_specs(&conversion_specs, &format[i + 1]) + 1;
	else
		i = 1;
	return (i);
}

int	_parse(const char *format, va_list *ap, char **result)
{
	int		i;
	int		len;
	int		ret;

	i = 0;
	len = 0;
	ret = 0;
	while (format[i])
	{
		ret = parse_next_item(&format[i], ap, result, len);
		if (ret == -1)
			break ;
		len += ret;
		i += format_item_length(&format[i]);
	}
	if (ret == -1)
		return (-1);
	if (i == 0)
		*result = s_dup("");
	return (len);
}
