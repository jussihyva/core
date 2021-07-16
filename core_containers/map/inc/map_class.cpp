#include "map_class.h"

core::map::map(t_size capacity, t_size method, t_uint64 (*hash)(const char *key))
{
	t_ret	ret;

	ret = map_new(&this->c_struct, capacity, method, hash);
	if (ret < 0)
	{
		map_free(&this->c_struct);
		throw t_ret (ret);
	}
}

core::map::~map(void)
{
	map_free(&this->c_struct);
}

t_ret	core::map::add(void *src, const char *key)
{
	return (map_add(&this->c_struct, src, key));
}

t_ret	core::map::del(const char *key)
{
	return (map_del(&this->c_struct, key));
}

void	*core::map::get(const char *key)
{
	return (map_get(&this->c_struct, key));
}

void	core::map::iter(t_ssize (*f)(void *, t_size))
{
	return (map_iter(&this->c_struct, f));
}

char	*core::map::parse(void *dst,
		char *(*f)(void *, void *, const char *key))
{
	return (map_parse(&this->c_struct, dst, f));
}
