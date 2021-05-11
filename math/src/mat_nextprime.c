/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_nextprime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 03:54:56 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:30:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

uint64_t	math_nextprime(uint64_t n)
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
