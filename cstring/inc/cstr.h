#ifndef LIBCSTR_H
# define LIBCSTR_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdint.h>
# include <float.h>
# define READLINE_MAX_BUFF 1
# define READLINE_MAX_FD 2

char				*s_cat(char *dest, const char *src);
char				*s_ncat(char *dest, const char *src, uint64_t n);
uint64_t			s_lcat(char *dst, const char *src, uint64_t size);
char				*s_rev(char *str);
char				*s_chr(const char *s, int c);
char				*s_rchr(const char *s, int c);
int					s_cmp(const char *s1, const char *s2);
int					s_ncmp(const char *s1, const char *s2, uint64_t n);
char				*s_cpy(char *dest, const char *src);
char				*s_ncpy(char *dest, const char *src, uint64_t n);
uint64_t			s_lcpy(char *dst, const char *src, uint64_t dstsize);
char				*s_dup(const char *s);
char				*s_ndup(const char *s, uint64_t n);
char				*s_cdup(const char *s1, char c);
char				*s_copy(char *str, size_t start, size_t end, size_t flag);
uint64_t			s_len(const char *s);
char				*s_str(const char *h, const char *n);
char				*s_nstr(const char *h, const char *n, uint64_t len);
char				*s_new(uint64_t size);
void				s_del(char **as);
void				s_clr(char *s);
void				s_iter(char **ref, int (*fptr)(int c));
void				s_iteri(char *s, void (*f)(unsigned int, char *));
char				*s_map(char const *s, char (*f)(char));
char				*s_mapi(char const *s, char (*f)(unsigned int, char));
int					s_equ(char const *s1, char const *s2);
int					s_nequ(char const *s1, char const *s2, uint64_t n);
char				*s_sub(char const *s, unsigned int start, uint64_t len);
char				*s_csub(char *s, char c);
char				*s_join(char const *s1, char const *s2);
char				*s_trim(char const *s);
char				**s_split(char const *s, char c);
int					s_lenc(char *s, char c);
int					s_sum(char *str);
char				*s_appendc(char *str, char c);
void				s_ctoc(char *str, int from, int to);
char				*s_newc(size_t size, int c);
char				*s_join_free(char *s1, char *s2, size_t flag);
char				*s_fill(char *data, size_t b_size, char *flags);
char				*s_cut(char *s, size_t size);
void				s_swp(char *a, char *b);
int					s_find_first(char *ref, char *src);
int					s_readline(const int fd, char **line);

#endif
