/*******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 ******************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

int	get_length_modifier(t_data *specs, const char *format)
{
	int		i;
	char	modifier;

	i = 0;
	modifier = format[i];
	if (modifier == 'h' || modifier == 'l')
	{
		specs->length_modifier[i] = modifier;
		if (format[i + 1] == modifier)
			specs->length_modifier[++i] = modifier;
	}
	else
		specs->length_modifier[i] = modifier;
	i++;
	return (i);
}

int	get_precision(t_data *specs, const char *format)
{
	int	i;

	i = 1;
	specs->has_precision = 1;
	specs->precision = (size_t)ft_atoi(&format[i]);
	if (specs->precision == 0)
		specs->zero_precision = 1;
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

int	get_min_field_width(t_data *specs, const char *format)
{
	int	i;

	i = 0;
	specs->min_field_width = (size_t)ft_atoi(&format[i]);
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

int	get_flags(t_data *specs, const char *format)
{
	int	i;

	i = 0;
	while (format[i] == '#' || format[i] == '0' || format[i] == ' '
		|| format[i] == '-' || format[i] == '+')
	{
		if (format[i] == '#')
			specs->alt_form = 1;
		else if (format[i] == '0')
			specs->zero_padding = 1;
		else if (format[i] == ' ')
			specs->blank_signed = 1;
		else if (format[i] == '-')
			specs->neg_field_width = 1;
		else if (format[i] == '+')
			specs->plus_signed = 1;
		i++;
	}
	return (i);
}

int	get_conversion_specs(t_data *specs, const char *format)
{
	int	i;

	i = 0;
	i += get_flags(specs, format);
	if (ft_isdigit(format[i]))
		i += get_min_field_width(specs, &format[i]);
	if (format[i] == '.')
		i += get_precision(specs, &format[i]);
	if (format[i] == 'h' || format[i] == 'l' || format[i] == 'L')
		i += get_length_modifier(specs, &format[i]);
	specs->conversion = format[i];
	return (i + 1);
}