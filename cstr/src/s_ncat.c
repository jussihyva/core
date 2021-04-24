/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ncat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:29:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 23:21:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char		*s_ncat(char *s1, const char *s2, uint64_t n)
{
	uint64_t	i;
	uint64_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && j < n)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_ncat
**
**	String catenate (n); appends a copy of `n` characters from the
**	null-terminated string s2 to the end of the null-terminated string s1.
**	The string s1 must have sufficient space to hold the result.
**
**  ----------------------------------------------------------------------------
*/
