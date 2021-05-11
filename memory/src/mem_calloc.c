/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:08 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:38:44 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

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
