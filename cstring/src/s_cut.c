/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:27:21 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 23:21:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char				*s_cut(char *s, size_t size)
{
	if (size < s_len(s))
		s[size] = '\0';
	return (s);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_cut
**
**	Cut string `s` at position size.
**
**  ----------------------------------------------------------------------------
*/