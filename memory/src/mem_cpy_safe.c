/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cpy_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:35 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:29:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

void	*mem_cpy_safe(void *dst, const void *src, t_size n)
{
	const t_byte	*src8;
	t_byte			*dst8;

	if (src == NULL)
		return (NULL);
	src8 = (const t_byte *)src;
	dst8 = (t_byte *)dst;
	while (n--)
		*dst8++ = *src8++;
	return (dst);
}
