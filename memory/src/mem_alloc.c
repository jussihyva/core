/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:56 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/12 15:31:13 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

void		*mem_alloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p)
		mem_zero(p, size);
	return (p);
}

/*
**  ----------------------------------------------------------------------------
**
**	MEM_alloc
**
**	Void memory allocation; allocates `size` bytes of memory and initializes
**	the memory.
**
**  ----------------------------------------------------------------------------
*/
