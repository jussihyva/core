/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_cos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:01:22 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:30:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

double	math_cos(double x, int64_t p)
{
	return (math_sin(CR_PI / 2 - x, p));
}

/*
**  ----------------------------------------------------------------------------
**
**	math_cos
**	Calculate cosine of `x` with precision `p`.
**
**	Idea for optimization; save both sine and cosine when each is invoked.
**
**  ----------------------------------------------------------------------------
*/
