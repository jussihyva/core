/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:08 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 11:43:24 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

void	*mcalloc(t_size nmemb, t_size size)
{
	void		*addr;

	addr = malloc(nmemb * size);
	if (addr)
		mset(addr, 0, nmemb * size);
	return (addr);
}

/*
**  ----------------------------------------------------------------------------
**
**	mcalloc
**
**	Void memory allocation (c); allocates and formats `nmemb` amount of
**	elements of size `size`.
**
**  ----------------------------------------------------------------------------
*/
