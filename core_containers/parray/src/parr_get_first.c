/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_get_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

void	*parr_get_first(t_parray *arr)
{
	return (parr_get(arr, 0));
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_GET_FIRST
**
**	Pull the first member from a dynamic array.
**
**  ----------------------------------------------------------------------------
*/