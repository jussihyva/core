/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_pow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 10:37:09 by skoskine          #+#    #+#             */
/*   Updated: 2021/05/10 20:24:23 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uintmax_t	ft_uintmax_pow(int base, int power)
{
	uintmax_t	result;

	result = 1;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}
