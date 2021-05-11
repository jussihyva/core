/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_fac.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:10:04 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:30:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

int64_t	math_fac(int64_t n)
{
	int64_t		i;
	int64_t		fac;

	i = 1;
	fac = 1;
	while (i <= n)
	{
		fac = fac * i;
		i++;
	}
	return (fac);
}

/*
**  ----------------------------------------------------------------------------
**
**	math_fac
**
**	Calculate the factorial of n.
**
**  ----------------------------------------------------------------------------
*/
