/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:33:05 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

ssize_t	parr_rotate(t_parray *arr, ssize_t steps)
{
	void	*tmp;
	ssize_t	i;

	if (parr_null(arr))
		return (CR_FAIL);
	i = 0;
	if (arr->len < 2 || steps == 0)
		return (0);
	if (steps > 0)
	{
		while (i < steps)
		{
			tmp = parr_take_first(arr);
			parr_add_last(arr, tmp);
			i++;
		}
	}
	else if (steps < 0)
	{
		steps = steps * -1;
		while (i < steps)
		{
			tmp = parr_take_last(arr);
			parr_add_first(arr, tmp);
			i++;
		}
	}
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ROTATE
**
**	Rotate array. Last element becomes the first element.
**
**  ----------------------------------------------------------------------------
*/

