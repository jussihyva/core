/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_nextprime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 03:54:56 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:38:35 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

t_uint64	math_nextprime(t_uint64 n)
{
	if (math_prime(n))
		n++;
	while (math_prime(n) == 0)
		n++;
	return (n);
}

/*
**  ----------------------------------------------------------------------------
**
**	math_nextprime
**
**	Calculate the next prime number from `n` (even if `n` is prime).
**
**  ----------------------------------------------------------------------------
*/
