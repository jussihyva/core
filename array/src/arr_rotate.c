/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 23:41:17 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

static ssize_t	rot(t_arr *src, ssize_t steps)
{
	void	*tmp;
	ssize_t	i;

	i = 0;
	while (i < steps)
	{
		tmp = arr_get_first(src);
		arr_add_last(src, tmp);
		arr_del_first(src);
		i++;
	}
	return (i);
}

static ssize_t	rrot(t_arr *src, ssize_t steps)
{
	void	*tmp;
	ssize_t	i;

	i = 0;
	steps = steps * -1LL;
	while (i < steps)
	{
		tmp = arr_get_last(src);
		arr_add_first(src, tmp);
		arr_del_last(src);
		i++;
	}
	return (i);
}

ssize_t	arr_rotate(t_arr *src, ssize_t steps)
{
	if (src->len < 2 || steps == 0)
		return (0);
	if (steps > 0)
		rot(src, steps);
	else if (steps < 0)
		rrot(src, steps);
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ROTATE
**
**	Rotate array. If `steps` is positive positive
**
**  ----------------------------------------------------------------------------
*/

