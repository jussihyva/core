/******************************************************************************
 *
 * \brief Dynamic array implementation library.
 *
 * \authors Julius Koskela
 *
 *****************************************************************************/

#ifndef ARRAY_H
# define ARRAY_H

# include <string.h>
# include <stdint.h>
# include <unistd.h>
# include "../../system/inc/system.h"
# include "../../inc/types.h"

t_array		arr_new(size_t len, size_t elem_size);
ssize_t		arr_free(t_array *src);
ssize_t		arr_null(t_array *src);
void		*arr_get(t_array *src, size_t index);
void		*arr_get_first(t_array *src);
void		*arr_get_last(t_array *src);
void		*arr_take(void *dst, t_array *src, size_t index);
void		*arr_take_first(void *dst, t_array *src);
void		*arr_take_last(void *dst, t_array *src);
ssize_t		arr_add(t_array *src, void *node, size_t index);
ssize_t		arr_add_first(t_array *src, void *node);
ssize_t		arr_add_last(t_array *src, void *node);
ssize_t		arr_add_mult(t_array *src, size_t count, ...);
ssize_t		arr_put(t_array *dst, void *src, size_t size);
ssize_t		arr_del(t_array *src, size_t index);
ssize_t		arr_del_first(t_array *src);
ssize_t		arr_del_last(t_array *src);
ssize_t		arr_find(t_array *src, void *key);
ssize_t		arr_search(t_array *src, t_array *key);
ssize_t		arr_copy(t_array *dst, t_array *src);
ssize_t		arr_join(t_array *dst, t_array *src);
ssize_t		arr_join_mult(t_array *dst, size_t count, ...);
ssize_t		arr_rotate(t_array *arr, ssize_t steps);
ssize_t		arr_iter(t_array *src,
				ssize_t (*f)(void *, size_t));
ssize_t		arr_iter_range(t_array *src, size_t start, size_t end,
				ssize_t (*f)(void *, size_t));
ssize_t		arr_find_by(t_array *arr, const void *key,
				ssize_t (*f)(const void *, const void *));
ssize_t		arr_parse(t_array *dst, t_array *src,
				ssize_t (*f)(t_array *, void *));

#endif
