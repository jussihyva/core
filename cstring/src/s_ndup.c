/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ndup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:29:59 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:05:02 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_ndup(const char *s, uint64_t n)
{
	char	*out;

	out = (char *)malloc(sizeof(char) * n + 1);
	if (out == NULL)
		return (NULL);
	out = s_ncpy(out, s, n);
	out[n] = '\0';
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_ndup
**
**	String duplicate (n); duplicate `n` characters from `s1`.
**
**	Returns a memory allocated output `out`.
**
**  ----------------------------------------------------------------------------
*/
