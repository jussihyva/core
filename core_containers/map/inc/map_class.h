#ifndef MAP_CLASS_H
# define MAP_CLASS_H
# include "../../../inc/core.h"
# include "../../../inc/types.h"

namespace core
{
	class map
	{
		private:

		t_map	c_struct;

		public:

		map(t_size capacity, t_size method,
			t_uint64 (*hash)(const char *));
		~map(void);
		t_ret	add(void *src, const char *key);
		t_ret	del(const char *key);
		void	*get(const char *key);
		void	print(void);
		void	iter(
					t_ssize (*f)(void *, t_size));
		char	*parse(void *dst,
					char *(*f)(void *, void *, const char *key));
	};
};

#endif /* ARRAY_CLASS */
