#ifndef PARR_H
# define PARR_H
#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
///
/// \brief Dynamic array implementation library.
///
/// \authors Julius Koskela
///
///////////////////////////////////////////////////////////////////////////////

# include "../../../inc/types.h"

/*
**	---------------------------------------------------------------------------
**
**	General
*/

t_ret			parr_new(t_parray *src, t_size size);
void			parr_free(t_parray *arr);
t_ret			parr_grow(t_parray *arr, t_size new_size);
t_bool			parr_null(t_parray *arr);

/*
**	---------------------------------------------------------------------------
**
**	Add or delete element(s)
*/

t_ret			parr_add(t_parray *arr, void *node, t_size index);
t_ret			parr_add_first(t_parray *arr, void *node);
t_ret			parr_add_last(t_parray *arr, void *node);
t_ret			parr_add_mult(t_parray *arr, t_size len, ...);
t_ret			parr_assign(t_parray *dst, void **src, t_size size);
t_ret			parr_del(t_parray *arr, t_size index);
t_ret			parr_del_first(t_parray *arr);
t_ret			parr_del_last(t_parray *arr);

/*
**	---------------------------------------------------------------------------
**
**	Get or take a element
*/

void			*parr_get(t_parray *arr, t_size index);
void			*parr_get_first(t_parray *arr);
void			*parr_get_last(t_parray *arr);
void			*parr_take(t_parray *arr, t_size index);
void			*parr_take_first(t_parray *arr);
void			*parr_take_last(t_parray *arr);

/*
**	---------------------------------------------------------------------------
**
**	Manipulation
*/

t_ret			parr_copy(t_parray *dst, t_parray *src);
t_ret			parr_join(t_parray *dst, t_size len, ...);
t_ret			parr_split(t_parray *dst, t_parray *src);
t_ret			parr_rotate(t_parray *arr, t_ssize steps);

/*
**	---------------------------------------------------------------------------
**
**	Templates
*/

t_ret			parr_dup(t_parray *dst, t_parray *src, t_size size);
t_ret			parr_read_file(t_parray *dst, char *filename);
t_ret			parr_write_file(char *dst, t_parray *src, t_ssize flag,
					t_ssize (*f)(void *, void *));
t_ret			parr_write(t_parray *dst, t_parray *src,
					t_ssize (*f)(void *, void *));
t_ret			parr_search(t_parray *dst, t_parray *src, void *key,
					void *(*f)(void *, void *));
void			*parr_find(t_parray *src, void *key,
					void *(*f)(void *, void *));
t_ret			parr_iter(t_parray *arr,
					t_ssize (*f)(void *, t_size));
t_ret			parr_parse(t_parray *dst, t_parray *src,
					t_ssize (*f)(t_parray *, void *));
void			parr_foreach(t_parray *src, void (*f)(const void *));

#ifdef __cplusplus
}
#endif
#endif
