#ifndef STRING_H
# define STRING_H

#include "../../../inc/types.h"

t_str	str(char *str);
void	str_free(t_str *str);
t_str	str_new(t_size len);
t_str	str_cpy(t_str dst, t_str src);
t_str	str_append(t_str dst, t_str src);
t_str	str_ncpy(t_str dst, t_str src, size_t len);
void	str_write(t_str str);
t_pstr	str_chr(t_str src, t_pstr b);
t_pstr	pstr_assign(void *src, size_t size);
void	pstr_write(t_pstr str);
t_size	str_cmp(t_str s1, t_str s2);

t_page	page(t_size size);
t_ssize	page_read_file(t_page *dst, char *filename);
t_ssize	page_write_file(char *dst, t_page *src, t_ssize flag);

void	page_print(t_page p);
void	page_free(t_page *p);
void	str_rev(t_str *src);

#endif
