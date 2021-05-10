/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 08:31:27 by skoskine          #+#    #+#             */
/*   Updated: 2021/05/10 17:50:50 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;
	size_t	copy_size;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		new = NULL;
	}
	else
		new = (void *)malloc(new_size);
	if (new != NULL && ptr != NULL)
	{
		if (new_size < old_size)
			copy_size = new_size;
		else
			copy_size = old_size;
		ft_memcpy(new, ptr, copy_size);
		if (new_size > old_size)
			ft_memset((void *)(&((char *)new)[old_size]),
				0, new_size - old_size);
		free(ptr);
	}
	return (new);
}
