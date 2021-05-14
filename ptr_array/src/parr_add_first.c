/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_add_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/14 18:43:58 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"
#include "../../inc/core.h"

ssize_t	parr_add_first(t_parray *arr, void *data)
{
	if (!(parr_add(arr, data, 0)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ADD_FIRST
**
**	Add a new member to the beginning of a dynamic string. If the string is not
**	sufficiently big a new memory area double the size of the previous one
**	is allocated. One extra member is added to the allocation for the case
**	that the string has size 0.
**
**  ----------------------------------------------------------------------------
*/
