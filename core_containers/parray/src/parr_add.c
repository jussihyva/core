/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 15:49:57 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_add(
		t_parray *arr,
		void *data,
		t_size index)
{
	t_parray	new_parray;
	void		*tmp;
	t_ret		ret;
	t_size		i;

	if (parr_null(arr) == TRUE || !data)
		return (CR_ERROR_INPUT);
	if (index > arr->len)
		return (CR_ERROR_BOUNDS);
	ret = parr_new(&new_parray, arr->size);
	if (ret < 0)
		return (ret);
	i = 0;
	while (i < index)
	{
		tmp = parr_take_first(arr);
		ret = parr_add_last(&new_parray, tmp);
		if (ret < 0)
			return (ret);
		i++;
	}
	ret = parr_add_last(&new_parray, data);
	if (ret < 0)
		return (ret);
	ret = parr_join(&new_parray, 1, arr);
	if (ret < 0)
		return (ret);
	parr_free(arr);
	*arr = new_parray;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ADD
**
**	Add a new element to any index in an array. If index exceeds element
**	len, new element is added to the end of the array.
**
**  ----------------------------------------------------------------------------
*/
