///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Sort array
///
/// \param src Source array
/// \param f Comparison method.
///
///////////////////////////////////////////////////////////////////////////////

#include "inc/core.h"

static inline void *_arr_get(t_array *src, t_size index)
{
	t_byte	*raw_pos;

	raw_pos = src->raw.data;
	raw_pos += index * src->elem_size;
	return (raw_pos);
}

static inline void arr_sort_insertion(t_array *src,
		t_ssize lo,
		t_ssize hi,
		t_ssize (*f)(void *, void *)) 
{
	t_ssize	i;
	t_ssize	j;

	i = lo;
    while (i <= hi)
    {
		j = i;
        while (j > lo
				&& f(_arr_get(src, j), _arr_get(src, j - 1)) < 0)
        {
            mswap(_arr_get(src, j), _arr_get(src, j - 1), src->elem_size);
			j--;
        }
		i++;
    }
}

static void	arr_sort_recurse(t_array *src,
	t_ssize low,
	t_ssize high,
	t_ssize (*f)(void *, void *))
{
	t_ssize	pivot;
	t_ssize	a;
	t_ssize	b;
	void	*pivot_ptr;

	while (low < high)
	{
		pivot = low;
		a = low;
		b = high;
		pivot_ptr = _arr_get(src, pivot);
		while (a < b)
		{
			while (a <= high && f(_arr_get(src, a), pivot_ptr) <= 0)
				a++;
			while (b >= low && f(_arr_get(src, b), pivot_ptr) > 0)
				b--;
			if (a < b)
				mswap(_arr_get(src, a), _arr_get(src, b), src->elem_size);
		}
		mswap(pivot_ptr, _arr_get(src, b), src->elem_size);
		arr_sort_recurse(src, low, b - 1, f);
		low = b + 1;
	}
}

void	arr_sort(t_array *src, t_ssize (*f)(void *, void *))
{
	arr_sort_recurse(src, 0, src->len - 1, f);
}
