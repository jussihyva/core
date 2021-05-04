/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Free an array passed as an argument.
 *
 * \param src Pointer to an array to be freed.
 *
 * \return 1 on success.
 *
 ******************************************************************************/

#include "../inc/arr.h"

ssize_t	arr_free(t_arr *src)
{
	free(src->data);
	*src = CR_ARR_NULL;
	return (CR_SUCCESS);
}
