/*******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 ******************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		n--;
		s++;
	}
	return (NULL);
}
