/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/26 01:30:49 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARR_H
# define PARR_H
# include "../../inc/core.h"

typedef struct	s_parr
{
	void		**data;
	size_t		len;
	size_t		size;
}				t_parr;

/*
**	---------------------------------------------------------------------------
**
**	General
*/

t_parr			parr_new(size_t size);
ssize_t			parr_free(t_parr *arr);
ssize_t			parr_grow(t_parr *arr, size_t new_size);
ssize_t			parr_null(t_parr *arr);

/*
**	---------------------------------------------------------------------------
**
**	Add or delete member(s)
*/

ssize_t			parr_add(t_parr *arr, void *node, size_t index);
ssize_t			parr_add_first(t_parr *arr, void *node);
ssize_t			parr_add_last(t_parr *arr, void *node);
ssize_t			parr_add_mult(t_parr *arr, size_t len, ...);
ssize_t			parr_assign(t_parr *dst, void **src, size_t size);
ssize_t			parr_del(t_parr *arr, size_t index);
ssize_t			parr_del_first(t_parr *arr);
ssize_t			parr_del_last(t_parr *arr);

/*
**	---------------------------------------------------------------------------
**
**	Get or take a member
*/

void			*parr_get(t_parr *arr, size_t index);
void			*parr_get_first(t_parr *arr);
void			*parr_get_last(t_parr *arr);
void			*parr_take(t_parr *arr, size_t index);
void			*parr_take_first(t_parr *arr);
void			*parr_take_last(t_parr *arr);

/*
**	---------------------------------------------------------------------------
**
**	Manipulation
*/

ssize_t			parr_copy(t_parr *dst, t_parr *src);
ssize_t			parr_join(t_parr *dst, size_t len, ...);
ssize_t			parr_split(t_parr *dst, t_parr *src);
ssize_t			parr_rotate(t_parr *arr, ssize_t steps);

/*
**	---------------------------------------------------------------------------
**
**	Templates
*/

ssize_t			parr_dup(t_parr *dst, t_parr *src, size_t size);
ssize_t			parr_read_file(t_parr *dst, char *filename);
ssize_t			parr_write_file(char *dst, t_parr *src, ssize_t flag,
				ssize_t (*f)(void *, void *));
ssize_t			parr_write(t_parr *dst, t_parr *src,
				ssize_t (*f)(void *, void *));
ssize_t			parr_search(t_parr *dst, t_parr *src, void *key,
				void *(*f)(void *, void *));
void			*parr_find(t_parr *src, void *key,
				void *(*f)(void *, void *));
ssize_t			parr_iter(t_parr *arr,
				ssize_t (*f)(void *, size_t));
ssize_t			parr_parse(t_parr *dst, t_parr *src,
				ssize_t (*f)(t_parr *, void *));

#endif
