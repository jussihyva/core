#ifndef ARRAY_CLASS_H
# define ARRAY_CLASS_H
# include "../../../inc/core.h"
# include "../../../inc/types.h"

namespace core
{
	class array
	{
		private:

		t_array	c_struct;

		public:

		array(t_size len, t_size elem_size);
		~array(void);
		t_ssize	len(void);
		t_ret	add(void *elem, t_size index);
		t_ret	add_first(void *elem);
		t_ret	add_last(void *elem);
		void	*get(t_size index);
		void	*get_first(void);
		void	*get_last(void);
		t_ret	take(void *dst, t_size index);
		t_ret	take_first(void *dst);
		t_ret	take_last(void *dst);
		t_ret	del(t_size index);
		t_ret	del_first(void);
		t_ret	del_last(void);
		t_ret	put(void *src, t_size size);
		t_ret	copy(t_array *src);
		t_ret	join(t_array *src);
		t_ret	foreach(
					void (*f)(void *));
		t_ret	iter(
					t_ssize (*f)(void *, t_size));
		t_ret	iter_range( t_size start, t_size end,
					t_ssize (*f)(void *, t_size));
		t_ret	parse(t_array *dst,
					t_ssize (*f)(t_array *, void *));
		void	sort(
					t_ssize (*f)(void *, void *));
		t_ret	find(void *key);
		t_ret	find_by(const void *key,
					t_ssize (*f)(const void *, const void *));
		t_ret	search(t_array *key);
		t_ret	rotate(t_ssize steps);
		void	print(char *format);
	};
};

#endif /* ARRAY_CLASS */
