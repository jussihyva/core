/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cpy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:28:18 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:03:29 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_cpy(char *dst, const char *src)
{
	uint64_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_cpy
**
**	String copy; copies the contents of `src` to `dst`. Destination string
**	must be able to hold the contents of `src`.
**
**  ----------------------------------------------------------------------------
*/
