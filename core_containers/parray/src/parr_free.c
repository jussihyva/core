/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 15:27:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

void	parr_free(t_parray *arr)
{
	free(arr->data);
	*arr = (t_parray){NULL, 0, 0};
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_FREE
**
**	Deallocate a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
