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

#include "../inc/array.h"

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

static inline t_ssize	arr_sort_partition(t_array *src,
	t_ssize high,
	t_ssize low,
	t_ssize (*f)(void *, void *))
{
	t_ssize	pivot;
	t_ssize a;
	t_ssize b;
	void	*pivot_ptr;

	a = low;
	b = high;
	pivot = low;
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
	return (b);
}

static void	arr_sort_quick(t_array *src,
	t_ssize low,
	t_ssize high,
	t_ssize (*f)(void *, void *))
{
	t_ssize	b;

	while (low < high - 3)
	{
		b = arr_sort_partition(src, high, low, f);
		if (b - low < high - b)
		{
			arr_sort_quick(src, low, b - 1, f);
			low = b + 1;
		}
		else
		{
			arr_sort_quick(src, b + 1, high, f);
			high = b - 1;
		}
	}
	arr_sort_insertion(src, low, high, f);
}

static void	arr_sort_merge(t_array *src,
	t_ssize l,
	t_ssize m,
	t_ssize r,
	t_ssize (*f)(void *, void *))
{
	t_ssize	i;
	t_ssize	j;
	t_ssize	k;
	t_ssize	n1;
	t_ssize	n2;
	void	*ap;
	void	*bp;
	t_array	a;
	t_array	b;

	n1 = m - l + 1;
	n2 = r - m;
	a = arr_new(n1, src->elem_size);
	b = arr_new(n2, src->elem_size);
	i = 0;
	while (i < n1)
	{
		arr_add_last(&a, _arr_get(src, l + i));
		i++;
	}
	j = 0;
	while (j < n2)
	{
		arr_add_last(&b, _arr_get(src, m + 1  + j));
		j++;
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		ap = _arr_get(&a, i);
		bp = _arr_get(&b, j);
		if ((ap && bp) && f(ap, bp) <= 0)
		{
			mcpy(_arr_get(src, k), ap, src->elem_size);
			i++;
		}
		else if (bp)
		{
			mcpy(_arr_get(src, k), bp, src->elem_size);
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		ap = _arr_get(&a, i);
		mcpy(_arr_get(src, k), ap, src->elem_size);
		i++;
		k++;
	}
	while (j < n2)
	{
		bp = _arr_get(&b, j);
		mcpy(_arr_get(src, k), bp, src->elem_size);
		j++;
		k++;
	}
	arr_free(&a);
	arr_free(&b);
}

static void	arr_sort_part(t_array *src,
		t_ssize l,
		t_ssize r,
		t_ssize (*f)(void *, void *))
{
	t_ssize	m;
	if (l < r)
	{
		m = l + (r - l) / 2;
		arr_sort_part(src, l, m, f);
		arr_sort_part(src, m + 1, r, f);
		arr_sort_merge(src, l, m, r, f);
	}
}

void	arr_sort(t_array *src, t_ssize (*f)(void *, void *))
{
	if (src->len == 0)
		arr_sort_part(src, 0, src->len - 1, f);
	else
		arr_sort_quick(src, 0, src->len - 1, f);
}

