/*******************************************************************************
 * \authors Julius Koskela
 * \brief
 * \param
 * \return
 ******************************************************************************/

#include "../inc/arr.h"

void	*arr_take_first(void *dst, t_arr *src)
{
	dst = arr_take(dst, src, 0);
	return (dst);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_TAKE_FIRST
**
**	Take the first member from the array. Contrary to get, take also
**	removes the member from the array. For this same reason it takes as the
**	first argument a pointer to an allocated memory sufficient to hold
**	src->elem_size amount of data.
**
**  ----------------------------------------------------------------------------
*/
