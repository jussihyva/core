///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Checks if the array is a null array.
///
/// \param src The source array.
///
/// \return If arrary is NULL return TRUE, otherwise return FALSE.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_bool	arr_null(t_array *src)
{
	if (src->raw.data == NULL)
		return (TRUE);
	return (FALSE);
}
