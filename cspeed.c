#include "inc/core.h"
# include <string.h>
#include <time.h>
# include <unistd.h>

# define STRINGSIZE 100000

typedef t_mem	t_fstr;

t_fstr	fstr_new(t_size len)
{
	t_fstr	new;

	new = mem_new(len);
	return (new);
}

t_fstr	fstr(char *str)
{
	t_fstr	new;
	t_size	len;

	len = s_len(str);
	new = fstr_new(len);
	new.data = mcpy(new.data, str, len);
	return (new);
}

void	fstr_write(t_fstr str)
{
	if (!(write(1, str.data, str.size)))
		return ;
}

t_fstr	fstr_append(t_fstr dst, t_fstr src)
{
	t_fstr	new;
	t_byte	*mem_ptr;

	new = fstr_new(dst.size + src.size);
	mem_ptr = new.data;
	mem_ptr = mcpy(mem_ptr, dst.data, dst.size);
	mem_ptr += dst.size;
	mem_ptr = mcpy(mem_ptr, src.data, src.size);
	mem_free(&dst);
	return (new);
}

t_size	iters = 5000;

t_fstr	big_string()
{
	t_fstr	str;
	size_t	i;
	str = mem_new(sizeof(char) * STRINGSIZE);
	i = 0;
	while (i < STRINGSIZE)
	{
		str.data[i] = 'a';
		i++;
	}
	return (str);
}

double	test_cstring_speed(t_fstr s1, t_fstr s2)
{
	double	time;
	t_size	i;
	clock_t begin = clock();

	i = 0;
	while (i < iters)
	{
		s1 = fstr_append(s1, s2);
		i++;
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("TEST CSTRING\n%f\n", time_spent);
	printf("SIZE\n%llu\n", s1.size);
}

int main(void)
{
	t_fstr	s1;
	t_fstr	s2;

	s1 = big_string();
	s2 = big_string();
	test_cstring_speed(s1, s2);
}