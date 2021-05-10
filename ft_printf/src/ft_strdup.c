/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:26:23 by skoskine          #+#    #+#             */
/*   Updated: 2021/05/10 17:51:04 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (s2 == NULL)
		return (NULL);
	return (ft_memcpy(s2, s1, s1_len + 1));
}
