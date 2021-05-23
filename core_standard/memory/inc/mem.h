/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/23 21:07:09 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

#include "../../../inc/types.h"

void		*mcpy(void *dst, const void *restrict src, t_size n);
void		*mcpy_safe(void *dst, const void *src, t_size size);
void		*mccpy(void *dst, const void *src, int c, t_size size);
void		*mchr(const void *src, int c, t_size size);
void		*mmove(void *dst, const void *src, t_size size);
void		*mset(void *src, int c, t_size size);
void		*minit(t_size size);
void		*mcalloc(t_size nmemb, t_size size);
void		mdel(void **ap);
void		mzero(void *src, t_size size);
int			mcmp(const void *s1, const void *s2, t_size size);
void		mswap(void *a, void *b, t_size n);
t_mem		mem_new(t_size bytes);
t_hmem		hmem_range(t_mem src, size_t s, size_t t);
t_ssize		mem_realloc(t_mem *mem, t_size new_size);
void		mem_free(t_mem *mem);
t_mem		mem_cpy(t_mem dst, t_mem src, size_t size);
t_mem		mem_assign(void *src, size_t size);
t_hmem		mem_chr(t_mem src, t_mem b);
void		mem_print(t_mem src);

#endif
