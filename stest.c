#include "inc/core.h"
# include <string.h>
#include <time.h>
# include <unistd.h>

# define STRINGSIZE 100000

t_size	iters = 5000;

t_str	big_string()
{
	t_str	str;
	size_t	i;
	str = str_new(STRINGSIZE);
	i = 0;
	while (i < STRINGSIZE)
	{
		str.mem.data[i] = 'a';
		i++;
	}
	return (str);
}

double	test_cstring_speed(t_str s1, t_str s2)
{
	double	time;
	t_size	i;
	clock_t begin = clock();

	i = 0;
	while (i < iters)
	{
		s1 = str_append(s1, s2);
		i++;
	}
	mem_grow(&s1.mem, s1.len);
	// str_write(s1);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("TEST CSTRING\n%f\n", time_spent);
	printf("SIZE\n%llu\n", s1.mem.size);
}

int main(void)
{
	t_str	s1;
	t_str	s2;
	t_str	s3;
	t_pstr	s3p;
	t_pstr	chr;

	s1 = big_string();
	s2 = big_string();
	test_cstring_speed(s1, s2);
	s3 = str("abcdefghijklmnopqrstuvxyz");
	chr = pstr_assign("diau", 4);
	s3p = str_chr(s3, chr);
	mem_print(s3.mem);
	print("\n\n");
	pstr_write(s3p);
}