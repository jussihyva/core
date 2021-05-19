#ifndef STRING_H
# define STRING_H

# include "../../inc/types.h"

typedef char *	t_str;

t_str	str_new(t_size len);
t_str	str_dup(const char *src);
t_size	str_len(t_str src);
t_size	str_cmp(t_str s1, t_str s2);

#endif
