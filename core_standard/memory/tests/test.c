#include "../../../inc/core.h"
#include <assert.h>

typedef struct s_test
{
	int			x;
	float		y;
	void		*mem;
}				t_test;

int		test_mset()
{
	char	s[11] = "aaaaaaaaaa";

	mset(s, 'b', 10);
	assert(mcmp(s, "bbbbbbbbbb", 10) == 0);
	return (1);
}

int		test_mcmp()
{
	t_test	obj;
	char	*str;
	int		x;
	float	y;

	// Null
	/*assert(mcmp(NULL, NULL, 1) == 0);*/
	// Chars
	// Ints
	// Struct
	return (1);
}

int		main(void)
{
	test_mset();
	test_mcmp();
}