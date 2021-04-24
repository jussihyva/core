/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_newc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 05:55:44 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 23:21:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char			*s_newc(size_t size, int c)
{
	char		*out;
	size_t		i;

	out = s_new(size);
	i = 0;
	while (i < size)
	{
		out[i] = c;
		i++;
	}
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_new
**
**	String new; create an allocated string of size `size` format string with
**	`c`.
**
**  ----------------------------------------------------------------------------
*/
