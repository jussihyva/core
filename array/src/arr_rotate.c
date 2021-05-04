/*******************************************************************************
 * \authors Julius Koskela
 * \brief
 * \param
 * \return
 ******************************************************************************/

#include "../inc/arr.h"

static ssize_t	rot(t_arr *src, ssize_t steps)
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

static ssize_t	rrot(t_arr *src, ssize_t steps)
{
	void	*tmp;
	ssize_t	i;

	tmp = malloc(src->elem_size); // Data overlap when rotating this way so need to allocate.
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

ssize_t	arr_rotate(t_arr *src, ssize_t steps)
{
	if (src->len < 2 || steps == 0)
		return (0);
	if (steps > 0)
		rrot(src, steps);
	else if (steps < 0)
		rot(src, steps);
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ROTATE
**
**	Rotate array. If `steps` is positive positive
**
**  ----------------------------------------------------------------------------
*/

