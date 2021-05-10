/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 08:42:46 by skoskine          #+#    #+#             */
/*   Updated: 2021/05/11 00:29:46 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "ft_printf.h"

static double	get_sign(unsigned long long double_as_int)
{
	unsigned char	sign;

	sign = (unsigned char)(double_as_int >> 63);
	if (sign == 1)
		return (-1.0);
	else
		return (1.0);
}

double	ft_modf(double value, double *iptr)
{
	unsigned long long	double_as_int;
	int					exponent;
	unsigned long long	significand;
	double				sign;

	*iptr = value;
	if (value == 0.0 || value == -0.0 || ft_isnan(value))
		return (value);
	else if (ft_isposinf(value))
		return (0.0);
	else if (ft_isneginf(value))
		return (-0.0);
	mem_cpy_safe(&double_as_int, &value, sizeof(value));
	sign = get_sign(double_as_int);
	exponent = (short)(double_as_int >> 52 & 0x7FF) - 1023;
	significand = (double_as_int & 0x0000FFFFFFFFFFFFFULL) | (1ULL << 52);
	if (exponent < 0)
		*iptr = sign * 0.0;
	else if (exponent > 52)
		*iptr = value;
	else
		*iptr = (double)sign * (double)(significand >> (52 - exponent));
	return (value - *iptr);
}
