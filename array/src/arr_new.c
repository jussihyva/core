/*******************************************************************************
 * \authors Julius Koskela
 * \brief
 * \param
 * \return
 ******************************************************************************/

#include "../inc/arr.h"

t_arr	arr_new(size_t alloc_size, size_t elem_size)
{
	t_arr	out;

	out.len = 0;
	out.elem_size = elem_size;
	out.alloc_size = alloc_size;
	out.data = (uint8_t *)malloc(sizeof(uint8_t) * elem_size * alloc_size);
	if (!out.data)
	{
		perror("Array allocation failed in arr_new!\n");
		return (CR_ARR_NULL);
	}
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_NEW
**
**	Allocate a new dynamic array. You can pass any starting alloc_size and resizing
**	will be hanled automatically. A better initial size approximation leads to
**	fewer resizes.
**
**  ----------------------------------------------------------------------------
*/
