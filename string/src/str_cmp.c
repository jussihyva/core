#include "../../inc/core.h"

t_size	str_cmp(t_str s1, t_str s2)
{
	t_size	s1_len;
	t_size	s2_len;

	s1_len = str_len(s1);
	s2_len = str_len(s2);
	if (s1_len != s2_len)
		return (1);
	return ((t_size)mem_cmp(s1, s2, s1_len));
}
