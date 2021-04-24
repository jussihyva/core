/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 19:45:29 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H
# include "../../inc/core.h"

void				*mem_cpy(void *dst, const void *src, const size_t size);
void				*mem_cpy_safe(void *dst, const void *src, size_t size);
void				*mem_ccpy(void *dst, const void *src, int c, size_t size);
void				*mem_chr(const void *src, int c, size_t size);
void				*mem_move(void *dst, const void *src, size_t size);
void				*mem_set(void *src, int c, size_t size);
void				*mem_alloc(size_t size);
void				*mem_calloc(size_t nmemb, size_t size);
void				mem_del(void **ap);
void				mem_zero(void *src, size_t size);
int					mem_cmp(const void *s1, const void *s2, size_t size);

#endif
