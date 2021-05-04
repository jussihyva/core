/*******************************************************************************
 * \authors Julius Koskela
 * \brief
 * \param
 * \return
 ******************************************************************************/

#include "../inc/arr.h"

void	*arr_get(t_arr *src, size_t index)
{
	uint8_t	*mem_pos;

	if (index > src->len || src->len == 0)
		return (CR_FAIL);
	mem_pos = src->data;
	mem_pos += index * src->elem_size;
	return (mem_pos);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_GET
**
**	Pull a member from a dynamic array at `index`.
**
**  ----------------------------------------------------------------------------
*/
