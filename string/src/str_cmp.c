#include "../../inc/core.h"

size_t	str_cmp(t_str s1, t_str s2)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = str_len(s1);
	s2_len = str_len(s2);
	if (s1_len != s2_len)
		return (1);
	return ((size_t)mem_cmp(s1, s2, s1_len));
}
