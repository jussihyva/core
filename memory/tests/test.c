#include "../../inc/core.h"
#include <assert.h> 















typedef struct	s_test
{
	int			x;
	float		y;
	void		*mem;
}				t_test;

int		test_mem_set()
{
	char	s[11] = "aaaaaaaaaa";

	mem_set(s, 'b', 10);
	assert(mem_cmp(s, "bbbbbbbbbb", 10) == 0);
	return (1);
}

int		test_mem_cmp()
{
	t_test	obj;
	char	*str;
	int		x;
	float	y;

	// Null
	/*assert(mem_cmp(NULL, NULL, 1) == 0);*/
	// Chars
	// Ints
	// Struct
	return (1);
}





int		main(void)
{
	test_mem_set();
	test_mem_cmp();
}
