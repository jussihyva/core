/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cpy_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:35 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:37:35 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

void	*mem_cpy_safe(void *dst, const void *src, size_t n)
{
	const uint8_t	*src8;
	uint8_t			*dst8;

	if (src == NULL)
		return (NULL);
	src8 = (const uint8_t *)src;
	dst8 = (uint8_t *)dst;
	while (n--)
		*dst8++ = *src8++;
	return (dst);
}
