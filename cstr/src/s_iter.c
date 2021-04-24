/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_iter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:28:46 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 23:21:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

void			s_iter(char **ref, int (*fptr)(int c))
{
	int			i;
	int			size;

	i = 0;
	size = s_len(*ref);
	while (i < size)
	{
		(*ref)[i] = fptr((*ref)[i]);
		i++;
	}
}

/*
**  ----------------------------------------------------------------------------
**
**	S_iter
**
**	Perform function `f` (that takes an argument of type `char *`) passed as
**	a function pointer on all elements of string `s`.
**
**  ----------------------------------------------------------------------------
*/
