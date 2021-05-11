/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:29:10 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:04:41 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

uint64_t	s_lcpy(char *dst, const char *src, uint64_t size)
{
	uint64_t	i;
	uint64_t	j;

	i = 0;
	j = 0;
	if (!dst)
		return (0);
	while (src[j])
		j++;
	if (!size)
		return (j);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_lcpy
**
**	String copy; copies `size` contents from `src` to `dst`. Destination string
**	must be able to hold the contents of `src`.
**
**	Returns the lenght of the copied string.
**
**  ----------------------------------------------------------------------------
*/
