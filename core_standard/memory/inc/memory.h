/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/23 21:26:54 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

#include "../../../inc/types.h"

void		*mcpy(void *dst, const void *restrict src, t_size n);
void		*mcpy_safe(void *dst, const void *src, t_size size);
void		*mccpy(void *dst, const void *src, int c, t_size size);
void		*mchr(const void *src, int c, t_size size);
void		*mmove(void *dst, const void *src, t_size size);
void		*mset(void *src, int c, t_size size);
void		*minit(t_size size);
void		*mcalloc(t_size nrawb, t_size size);
void		mdel(void **ap);
void		mzero(void *src, t_size size);
int			mcmp(const void *s1, const void *s2, t_size size);
void		mswap(void *a, void *b, t_size n);

#endif
