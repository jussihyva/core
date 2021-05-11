#ifndef STRING_H
# define STRING_H

#include <unistd.h>

typedef char *	t_str;

t_str	str_new(size_t len);
t_str	str_dup(const char *src);
size_t	str_len(t_str src);
size_t	str_cmp(t_str s1, t_str s2);

#endif
