#include "../inc/core.h"

typedef char *	t_str;

t_str	str_new(t_size len)
{
	t_str	new;

	new = (char *)malloc(sizeof(char) * len + 9);
	if (!new)
	{
		printf("Allocation failed in function: arr_new!\n");
		exit(-1);
	}
	mem_cpy(new, &len, 8);
	new[len + 8] = '\0';
	return (&new[8]);
}

t_str	str_dup(char *src)
{
	t_str	new;

	new = str_new(s_len(src));
	s_cpy(new, src);
	return(new);
}

t_str	str_cpy(char *src)
{
	t_str	new;

	new = str_new(s_len(src));
	s_cpy(new, src);
	return(new);
}

t_size	str_len(t_str src)
{
	t_size	len;

	mem_cpy(&len, &src[-8], 8);
	return (len);
}

t_size	str_cmp(t_str s1, t_str s2)
{
	t_size	s1_len;
	t_size	s2_len;

	s1_len = str_len(s1);
	s2_len = str_len(s2);
	if (s1_len != s2_len)
		return (-1);
	return (mem_cmp(s1, s2, s1_len));
}

int	main(void)
{
	t_str	s1;
	t_str	s2;

	s1 = str("String\n");
	s2 = str("Stringi\n");
	printf("len: %zu %s\n", str_len(s1), s1);
	printf("len: %zu %s\n", str_len(s2), s2);
	if (str_cmp(s1, s2) == 0)
	{
		printf("Strings match!\n");
	}
	else
		printf("Strings don't match...\n");
}
