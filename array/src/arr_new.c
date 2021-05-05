/*******************************************************************************
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
