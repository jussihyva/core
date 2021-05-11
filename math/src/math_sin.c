/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_sin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:01:22 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:30:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

double	math_sin(double x, int64_t p)
{
	double		sum;
	int64_t		i;
	int64_t		j;

	sum = 0;
	x = x * (CR_PI / 180);
	i = 1;
	j = 1;
	while (i <= p)
	{
		if (i % 2 != 0)
			sum = sum + math_pow(x, j) / math_fac(j);
		else
			sum = sum - math_pow(x, j) / math_fac(j);
		i++;
		j = j + 2;
	}
	return (sum);
}

/*
**  ----------------------------------------------------------------------------
**
**	math_sin
**
**	Calculate sine of `x` with precision `p`.
**
**  ----------------------------------------------------------------------------
*/
