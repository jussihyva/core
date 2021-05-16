/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:08 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/17 02:26:42 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

void	*mem_calloc(size_t nmemb, size_t size)
{
	void		*addr;

	addr = malloc(nmemb * size);
	if (addr)
		mem_set(addr, 0, nmemb * size);
	return (addr);
}

/*
**  ----------------------------------------------------------------------------
**
**	MEM_calloc
**
**	Void memory allocation (c); allocates and formats `nmemb` amount of
**	elements of size `size`.
**
**  ----------------------------------------------------------------------------
*/
