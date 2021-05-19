/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Create a new array.
 *
 * Creates a new array an allocates alloc_size * elem_size bytes of memory.
 * It is advised that the elem_size is passed using the sizeof operator making
 * it explicit, what type of object the array is supposed to hold. The array
 * will grow automatically, but a better initial alloc_size approcimation will
 * lead to fewer resizes.
 *
 * \param alloc_size Initial estimate of the size of the array as elem_size
 * elements. Has to be > 0.
 * \param elem_size Size of the elemets in the array in bytes. Use sizeof.
 *
 * \return The new array as a t_array object.
 *
 *****************************************************************************/

#include "../../inc/core.h"

t_array	arr_new(t_size alloc_size, t_size elem_size)
{
	t_array	out;

	out.len = 0;
	out.elem_size = elem_size;
	out.mem = mem_new(alloc_size * elem_size);
	if (!out.mem.data)
	{
		print("Allocation failed in function: arr_new!\n");
		exit(-1);
	}
	return (out);
}
