/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 16:15:21 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_rotate(
		t_parray *arr,
		t_ssize steps)
{
	void	*tmp;
	t_ssize	i;

	if (parr_null(arr) || arr->len < 2 || steps == 0)
		return (0);
	i = 0;
	if (steps > 0)
	{
		while (i++ < steps)
		{
			tmp = parr_take_first(arr);
			parr_add_last(arr, tmp);
		}
	}
	else if (steps < 0)
	{
		steps = steps * -1;
		while (i++ < steps)
		{
			tmp = parr_take_last(arr);
			parr_add_first(arr, tmp);
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
