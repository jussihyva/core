/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/13 21:30:32 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARR_H
# define PARR_H

# include <string.h>


typedef struct s_parray
{
	void		**data;
	size_t		len;
	size_t		size;
}				t_parray;

/*
**	---------------------------------------------------------------------------
**
**	General
*/

t_parray		parr_new(size_t size);
ssize_t			parr_free(t_parray *arr);
ssize_t			parr_grow(t_parray *arr, size_t new_size);
ssize_t			parr_null(t_parray *arr);

/*
**	---------------------------------------------------------------------------
**
**	Add or delete member(s)
*/

ssize_t			parr_add(t_parray *arr, void *node, size_t index);
ssize_t			parr_add_first(t_parray *arr, void *node);
ssize_t			parr_add_last(t_parray *arr, void *node);
ssize_t			parr_add_mult(t_parray *arr, size_t len, ...);
ssize_t			parr_assign(t_parray *dst, void **src, size_t size);
ssize_t			parr_del(t_parray *arr, size_t index);
ssize_t			parr_del_first(t_parray *arr);
ssize_t			parr_del_last(t_parray *arr);

/*
**	---------------------------------------------------------------------------
**
**	Get or take a member
*/

void			*parr_get(t_parray *arr, size_t index);
void			*parr_get_first(t_parray *arr);
void			*parr_get_last(t_parray *arr);
void			*parr_take(t_parray *arr, size_t index);
void			*parr_take_first(t_parray *arr);
void			*parr_take_last(t_parray *arr);

/*
**	---------------------------------------------------------------------------
**
**	Manipulation
*/

ssize_t			parr_copy(t_parray *dst, t_parray *src);
ssize_t			parr_join(t_parray *dst, size_t len, ...);
ssize_t			parr_split(t_parray *dst, t_parray *src);
ssize_t			parr_rotate(t_parray *arr, ssize_t steps);

/*
**	---------------------------------------------------------------------------
**
**	Templates
*/

ssize_t			parr_dup(t_parray *dst, t_parray *src, size_t size);
ssize_t			parr_read_file(t_parray *dst, char *filename);
ssize_t			parr_write_file(char *dst, t_parray *src, ssize_t flag,
					ssize_t (*f)(void *, void *));
ssize_t			parr_write(t_parray *dst, t_parray *src,
					ssize_t (*f)(void *, void *));
ssize_t			parr_search(t_parray *dst, t_parray *src, void *key,
					void *(*f)(void *, void *));
void			*parr_find(t_parray *src, void *key,
					void *(*f)(void *, void *));
ssize_t			parr_iter(t_parray *arr,
					ssize_t (*f)(void *, size_t));
ssize_t			parr_parse(t_parray *dst, t_parray *src,
					ssize_t (*f)(t_parray *, void *));

#endif
