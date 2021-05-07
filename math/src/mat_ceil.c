/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ceil.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:53:22 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/07 20:57:56 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

double			math_ceil(double f)
{
	uint64_t	input;
	int			exponent;
	int			fractional_bits;
	uint64_t	integral_mask;
	uint64_t	output;

	v_cpy(&input, &f, 4);
	exponent = ((input >> 23) & 255) - 127;
	if (exponent < 0)
		return (f > 0);
	fractional_bits = 23 - exponent;
	if (fractional_bits <= 0)
		return (f);
	integral_mask = 0xffffffff << fractional_bits;
	output = input & integral_mask;
	v_cpy(&f, &output, 4);
	if (f > 0 && output != input)
		++f;
	return (f);
}

/*
**  ----------------------------------------------------------------------------
**
**	math_ceil
**
**	Ceiling function maps to the least integer greater than or equal to
**
**	Logic:
**
**	1. Small numbers get rounded to 0 or 1, depending on their sign
**	2. Numbers without fractional bits are mapped to themselves
**	3. Round the number down by masking out the fractional bits
**	4. Positive numbers need to be rounded up, not down
**
**  ----------------------------------------------------------------------------
*/
