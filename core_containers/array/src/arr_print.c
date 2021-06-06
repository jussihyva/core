///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Formatted printing of array elements
///
/// Print array elements with printf formatting. Format datatype must match
/// data in array element.
///
/// \param src Source array.
/// \param format Printf format string.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

char	*interpert_format(char *format)
{
	char types [] = "cdiouxXfFsS";
	char *type;
	t_size	len;
	t_size	i;

	len = s_len(format);
	type = NULL;
	i = 0;
	while (format[i] && !s_chr("%", format[i]))
		i++;
	while (i < len)
	{
		if (s_chr(types, format[i]))
		{
			type = s_chr(types, format[i]);
			break ;
		}
		i++;
	}
	while (i < len)
	{
		if (format[i] == '%')
			return (type);
		i++;
	}
	return (type);
}

void	arr_print(t_array *src, char *format)
{
	char	*types [] = {"c", "di", "ouxX", "fF"};
	char	*type_ptr;
	int		type;
	void	*ret;
	t_size	i;

	type_ptr = interpert_format(format);
	type = *type_ptr;
	if (!type)
		return ;
	i = 0;
	while (i < src->len)
	{
		ret = arr_get(src, i);
		if (s_chr(types[0], type))
			print(format, *(char *)ret);
		else if (s_chr(types[1], type))
			print(format, *(t_int64 *)ret);
		else if (s_chr(types[2], type))
			print(format, *(t_uint64 *)ret);
		else if (s_chr(types[3], type))
			print(format, *(double *)ret);
		i++;
	}
}
