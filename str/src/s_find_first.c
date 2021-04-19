/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_find_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 02:41:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/15 23:45:05 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/str.h"

int				s_find_first(char *ref, char *src)
{
	size_t			i;

	i = 1;
	while (!(s_chr(ref, src[i - 1])))
		i++;
	if (s_chr(ref, src[i - 1]))
		return (i);
	else
		return (0);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_find_first
**
**	Return the index of the first occurence of any character in `ref` from the
**	string `src`.
**
**  ----------------------------------------------------------------------------
*/
