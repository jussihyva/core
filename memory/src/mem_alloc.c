/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:56 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/17 02:26:42 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

void	*mem_alloc(size_t size)
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
