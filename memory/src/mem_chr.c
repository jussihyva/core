/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:19 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/17 02:26:42 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

void	*mem_chr(const void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned const char *)s)[i] == (unsigned char)c)
			return ((void *)&((unsigned const char *)s)[i]);
		i++;
	}
	return (NULL);
}

/*
**  ----------------------------------------------------------------------------
**
**	MEM_chr
**
**	Void memory search; function locates the first occurrence of `c`
**	(converted to an unsigned char) in string `s`.
**
**	The `mem_chr` function returns a pointer to the byte located, or NULL if
**	no such byte exists within `n` bytes.
**
**  ----------------------------------------------------------------------------
*/
