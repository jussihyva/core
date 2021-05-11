/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_roundl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:35:26 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:30:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

typedef struct s_uint80
{
	uint64_t		u64;
	uint16_t		u16;
}					t_uint80;

typedef union u_ldbits
{
	long double		ldbl;
	t_uint80		u80;
}					t_ldbits;

long double	math_roundl(long double x)
{
	long double		toint;
	t_ldbits		u;
	int				e;
	long double		y;

	u.ldbl = x;
	e = u.u80.u16 & 0x7fff;
	toint = 1 / LDBL_EPSILON;
	if (e >= 0x3fff + LDBL_MANT_DIG - 1)
		return (x);
	if (u.u80.u16 >> 15)
		x = -x;
	if (e < 0x3fff - 1)
		return (0 * u.ldbl);
	y = x + toint - toint - x;
	if (y > 0.5)
		y = y + x - 1;
	else if (y <= -0.5)
		y = y + x + 1;
	else
		y = y + x;
	if (u.u80.u16 >> 15)
		y = -y;
	return (y);
}
