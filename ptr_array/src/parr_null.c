/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:48:38 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

ssize_t	parr_null(t_parray *arr)
{
	if (arr->data == NULL || arr->size == 0)
		return (CR_SUCCESS);
	return (CR_FAIL);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_NULL
**
**	Checks if the array is a NULL array.
**
**  ----------------------------------------------------------------------------
*/
