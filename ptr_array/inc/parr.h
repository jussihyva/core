/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 22:12:17 by julius           ###   ########.fr       */
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
int				parr_free(t_parr *arr);
int				parr_grow(t_parr *arr, size_t new_size);
int				parr_null(t_parr *arr);

/*
**	---------------------------------------------------------------------------
**
**	Add or delete member(s)
*/

int				parr_add(t_parr *arr, void *node, size_t index);
int				parr_add_first(t_parr *arr, void *node);
int				parr_add_last(t_parr *arr, void *node);
int				parr_add_mult(t_parr *arr, size_t len, ...);
int				parr_assign(t_parr *dst, void **src, size_t size);
int				parr_del(t_parr *arr, size_t index);
int				parr_del_first(t_parr *arr);
int				parr_del_last(t_parr *arr);

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

int				parr_copy(t_parr *dst, t_parr *src);
int				parr_join(t_parr *dst, size_t len, ...);
int				parr_split(t_parr *dst, t_parr *src);
int				parr_rotate(t_parr *arr, ssize_t steps);

/*
**	---------------------------------------------------------------------------
**
**	Templates
*/

int				parr_dup(t_parr *dst, t_parr *src, size_t size);
int				parr_read_file(t_parr *dst, char *filename);
int				parr_write_file(char *dst, t_parr *src, ssize_t flag,
				int (*f)(void **, void *));
int				parr_write(t_parr *dst, t_parr *src,
				int (*f)(void **, void *));
int				parr_search(t_parr *dst, t_parr *src, void *key,
				void *(*f)(void *, void *));
void			*parr_find(t_parr *src, void *key,
				void *(*f)(void *, void *));
int				parr_iterate(t_parr *arr,
				int (*f)(void **, size_t));
int				parr_parse(t_parr *dst, t_parr *src,
				int (*f)(t_parr *, void *));

#endif
