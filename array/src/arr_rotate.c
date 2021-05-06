/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Rotate a dynamic array.
 *
 * Number of rotations passed as a parameter. A negative number rotates the
 * array counter-clockwise, positive clockwise. 0 does nothing.
 *
 * \param src Source array.
 * \param steps Amount of rotations.
 *
 * \return 1 on success 0 on failure.
 *
 ******************************************************************************/

#include "../inc/arr.h"
#include "../../inc/core.h"

static ssize_t	rot(t_array *src, ssize_t steps)
{
	void	*tmp;
	ssize_t	i;

	steps = steps * -1LL;
	i = 0;
	while (i < steps)
	{
		tmp = arr_get_first(src);
		arr_add_last(src, tmp);
		arr_del_first(src);
		i++;
	}
	return (i);
}

static ssize_t	rrot(t_array *src, ssize_t steps)
{
	void	*tmp;
	ssize_t	i;

	tmp = malloc(src->elem_size);
	i = 0;
	while (i < steps)
	{
		tmp = arr_take_last(tmp, src);
		arr_add_first(src, tmp);
		i++;
	}
	free(tmp);
	return (i);
}

ssize_t	arr_rotate(t_array *src, ssize_t steps)
{
	if (src->len < 2 || steps == 0)
		return (0);
	if (steps > 0)
		rrot(src, steps);
	else if (steps < 0)
		rot(src, steps);
	return (CR_SUCCESS);
}
