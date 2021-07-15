///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Rotate a dynamic array.
///
/// Number of rotations passed as a parameter. A negative number rotates the
/// array counter-clockwise, positive clockwise. 0 does nothing.
///
/// \param src Source array.
/// \param steps Amount of rotations.
///
/// \return 1 on success 0 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

static t_ret	rot(t_array *src, t_ssize steps)
{
	void	*tmp;
	t_ret	ret;
	t_ssize	i;

	tmp = malloc(src->elem_size);
	if (!tmp)
		return (CR_ERROR_MALLOC);
	steps = steps * -1LLU;
	i = 0;
	while (i < steps)
	{
		ret = arr_take_first(tmp, src);
		if (ret < 0)
			return (ret);
		ret = arr_add_last(src, tmp);
		if (ret < 0)
			return (ret);
		i++;
	}
	free(tmp);
	return (i);
}

static t_ret	rrot(t_array *src, t_ssize steps)
{
	void	*tmp;
	t_ret	ret;
	t_ssize	i;

	tmp = malloc(src->elem_size);
	if (!tmp)
		return (CR_ERROR_MALLOC);
	i = 0;
	while (i < steps)
	{
		ret = arr_take_last(tmp, src);
		if (ret < 0)
			return (ret);
		ret = arr_add_first(src, tmp);
		if (ret < 0)
			return (ret);
		i++;
	}
	free(tmp);
	return (i);
}

t_ret	arr_rotate(
		t_array *src,
		t_ssize steps)
{
	t_ret	ret;

	if (src->len < 2 || steps == 0)
		return (CR_ERROR_BOUNDS);
	if (steps > 0)
	{
		ret = rrot(src, steps);
		if (ret < 0)
			return (ret);
	}
	else if (steps < 0)
	{
		ret = rot(src, steps);
		if (ret < 0)
			return (ret);
	}
	return (CR_SUCCESS);
}
