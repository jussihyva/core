/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:49:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_rotate(t_arr *src, ssize_t steps)
{
	void	*tmp;
	ssize_t	i;

	if (arr_null(src))
		return (CR_FAIL);
	i = 0;
	if (src->count < 2 || steps == 0)
		return (0);
	if (steps > 0)
	{
		while (i < steps)
		{
			tmp = arr_get_first(src);
			arr_add_last(src, tmp);
			arr_del_first(src);
			i++;
		}
	}
	else if (steps < 0)
	{
		steps = steps * -1;
		while (i < steps)
		{
			tmp = arr_get_last(src);
			arr_add_first(src, tmp);
			arr_del_last(src);
			i++;
		}
	}
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	CR_ROTATE
**
**	Rotate array. If `steps` is positive positive
**
**  ----------------------------------------------------------------------------
*/

