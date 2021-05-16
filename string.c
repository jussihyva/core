#include "inc/core.h"

typedef t_mem t_fstr;
typedef t_parray t_page;

t_fstr	fstr_new(size_t size)
{
	t_fstr	new;

	new = core_malloc(size);
	return (new);
}

t_fstr	fstr(const char *src)
{
	t_fstr	new;
	size_t	len;

	len = s_len (src);
	new = fstr_new(len + 1);
	mem_cpy(new.data, src, len + 1); 
	return (new);
}

size_t	fstr_len(t_fstr src)
{
	return (src.size - 1);
}

t_mem	fstr_join(t_mem dst, t_mem src)
{
	t_mem	new;
	uint8_t	*mem_dst;

	new = core_malloc(dst.size + src.size);
	mem_dst = new.data;
	mem_cpy(mem_dst, dst.data, dst.size - 1);
	mem_dst += dst.size - 1;
	mem_cpy(mem_dst, src.data, src.size);	
	return (new);
}

void	test_fstr_usage(void)
{
	t_fstr	s1;
	t_fstr	s2;
	t_fstr	s3;

	s1 = fstr("New string!");
	s2 = fstr("Another string...");
	print("%s\n", s1.data);
	print("%s\n", s2.data);
	print("%llu\n", fstr_len(s1));

	s3 = fstr_join(s1, s2);
	core_free(&s1);
	core_free(&s2);
	core_free(&s3);
}

int main(void)
{
	core_activate();
	test_fstr_usage();
	core_log();
	core_deactivate();
}
