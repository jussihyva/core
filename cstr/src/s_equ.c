/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_equ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:28:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 23:21:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

int			s_equ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	if (s_len(s1) != s_len(s2))
		return (0);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_equ
**
**	String equals; if the two strings are equal, returns 1. Otherwise
**	returns 0.
**
**  ----------------------------------------------------------------------------
*/
