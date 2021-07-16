#include "array_class.h"

core::array::array(t_size len, t_size elem_size)
{
	t_ret	ret;

	ret = arr_new(&this->c_struct, len, elem_size);
	if (ret < 0)
	{
		arr_free(&this->c_struct);
		throw t_ret (ret);
	}
}

core::array::~array(void)
{
	arr_free(&this->c_struct);
}

t_ssize	core::array::len(void)
{
	return (this->c_struct.len);
}

t_ret	core::array::add(void *elem, t_size index)
{
	return (arr_add(&this->c_struct, elem, index));
}

t_ret	core::array::add_first(void *elem)
{
	return (arr_add_first(&this->c_struct, elem));
}

t_ret	core::array::add_last(void *elem)
{
	return (arr_add_last(&this->c_struct, elem));
}

void	*core::array::get(t_size index)
{
	return (arr_get(&this->c_struct, index));
}

void	*core::array::get_first(void)
{
	return (arr_get_first(&this->c_struct));
}

void	*core::array::get_last(void)
{
	return (arr_get_last(&this->c_struct));
}

t_ret	core::array::take(void *dst, t_size index)
{
	return (arr_take(dst, &this->c_struct, index));
}

t_ret	core::array::take_first(void *dst)
{
	return (arr_take_first(dst, &this->c_struct));
}

t_ret	core::array::take_last(void *dst)
{
	return (arr_take_last(dst, &this->c_struct));
}

t_ret	core::array::del(t_size index)
{
	return (arr_del(&this->c_struct, index));
}

t_ret	core::array::del_first(void)
{
	return (arr_del_first(&this->c_struct));
}

t_ret	core::array::del_last(void)
{
	return (arr_del_first(&this->c_struct));
}

t_ret	core::array::put(void *src, t_size size)
{
	return (arr_put(&this->c_struct, src, size));
}

t_ret	core::array::copy(t_array *src)
{
	return (arr_copy(&this->c_struct, src));
}

t_ret	core::array::join(t_array *src)
{
	return (arr_join(&this->c_struct, src));
}

t_ret	core::array::foreach(
			void (*f)(void *))
{
	return (arr_foreach(&this->c_struct, f));
}

t_ret	core::array::iter(
			t_ssize (*f)(void *, t_size))
{
	return (arr_iter(&this->c_struct, f));
}

t_ret	core::array::iter_range( t_size start, t_size end,
			t_ssize (*f)(void *, t_size))
{
	return (arr_iter_range(&this->c_struct, start, end, f));
}

t_ret	core::array::parse(t_array *dst,
			t_ssize (*f)(t_array *, void *))
{
	return (arr_parse(&this->c_struct, dst, f));
}

void	core::array::sort(
			t_ssize (*f)(void *, void *))
{
	return (arr_sort(&this->c_struct, f));
}

t_ret	core::array::find(void *key)
{
	return (arr_find(&this->c_struct, key));
}

t_ret	core::array::find_by(const void *key,
			t_ssize (*f)(const void *, const void *))
{
	return (arr_find_by(&this->c_struct, key, f));
}

t_ret	core::array::search(t_array *key)
{
	return (arr_search(&this->c_struct, key));
}

t_ret	core::array::rotate(t_ssize steps)
{
	return (arr_rotate(&this->c_struct, steps));
}

