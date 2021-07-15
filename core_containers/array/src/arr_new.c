///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Create a new array.
///
/// Creates a new array and allocates alloc_size * elem_size bytes of memory.
/// It is advised that the elem_size is passed using the sizeof operator making
/// it explicit, what type of object the array is supposed to hold. The array
/// will grow automatically, but a better initial alloc_size approcimation will
/// lead to fewer resizes.
///
/// \param alloc_size Initial estimate of the size of the array as elem_size
/// elements. Has to be > 0.
/// \param elem_size Size of the elemets in the array in bytes. Use sizeof.
///
/// \return The new array as a t_array object.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ret	arr_new(t_array *src, t_size alloc_size, t_size elem_size)
{
	t_ret	ret;

	src->len = 0;
	src->elem_size = elem_size;
	ret = raw_new(&src->raw, alloc_size * elem_size);
	if (ret < CR_SUCCESS)
	{
		src->elem_size = 0;
		return (ret);
	}
	return (CR_SUCCESS);
}
