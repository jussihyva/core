/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnegative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 08:40:49 by skoskine          #+#    #+#             */
/*   Updated: 2021/05/11 08:07:17 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "ft_printf.h"

int	ft_isnegative(double nbr)
{
	unsigned long long	double_as_int;
	unsigned char		sign;

	mem_cpy_safe(&double_as_int, &nbr, sizeof(nbr));
	sign = (unsigned char)(double_as_int >> 63);
	if (sign == 0)
		return (0);
	else
		return (1);
}
