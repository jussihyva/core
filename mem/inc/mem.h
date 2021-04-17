/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/16 20:31:43 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOID_H
# define VOID_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

void				*mem_cpy(void *dst, const void *src, const size_t size);
void				*mem_cpy_safe(void *dst, const void *src, size_t n);
void				*mem_ccpy(void *dst, const void *src, int c, size_t n);
void				*mem_chr(const void *s, int c, size_t n);
int					mem_cmp(const void *s1, const void *s2, size_t n);
void				*mem_move(void *dest, const void *src, size_t n);
void				*mem_set(void *s, int c, size_t n);
void				*mem_alloc(size_t size);
void				*mem_calloc(size_t nmemb, size_t size);
void				mem_del(void **ap);
void				mem_zero(void *s, size_t n);

#endif
