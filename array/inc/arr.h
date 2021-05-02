/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/03 01:10:32 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBARR_H
# define LIBARR_H
# include "../../inc/core.h"

typedef struct	s_arr
{
	uint8_t		*data;
	size_t		len;
	size_t		alloc_size;
	size_t		elem_size;
}				t_arr;

t_arr			arr_new(size_t len, size_t elem_size);
ssize_t			arr_free(t_arr *src);
ssize_t			arr_null(t_arr *src);
void			*arr_get(t_arr *src, size_t index);
void			*arr_get_first(t_arr *src);
void			*arr_get_last(t_arr *src);
void			*arr_take(void *dst, t_arr *src, size_t index);
void			*arr_take_first(void *dst, t_arr *src);
void			*arr_take_last(void *dst, t_arr *src);
ssize_t			arr_grow(t_arr *src, size_t new_size);
ssize_t			arr_assign(t_arr *dst, void *data, size_t len);
ssize_t			arr_add(t_arr *src, void *node, size_t index);
ssize_t			arr_add_first(t_arr *src, void *node);
ssize_t			arr_add_last(t_arr *src, void *node);
ssize_t			arr_add_mult(t_arr *src, size_t count, ...);
ssize_t			arr_put(t_arr *dst, void *src, size_t size);
ssize_t			arr_del(t_arr *src, size_t index);
ssize_t			arr_del_first(t_arr *src);
ssize_t			arr_del_last(t_arr *src);
ssize_t			arr_find(t_arr *src, void *key);
ssize_t			arr_search(t_arr *src, t_arr *key);
ssize_t			arr_copy(t_arr *dst, t_arr *src);
ssize_t			arr_join(t_arr *dst, t_arr *src);
ssize_t			arr_join_mult(t_arr *dst, size_t count, ...);
ssize_t			arr_rotate(t_arr *arr, ssize_t steps);
ssize_t			arr_iter(t_arr *src,
				ssize_t (*f)(void *, size_t));
ssize_t			arr_iter_range(t_arr *src, size_t start, size_t end,
				ssize_t (*f)(void *, size_t));
ssize_t			arr_find_by(t_arr *arr, const void *key,
				ssize_t (*f)(const void *, const void *));
ssize_t			arr_parse(t_arr *dst, t_arr *src,
				ssize_t (*f)(t_arr *, void *));

#endif
