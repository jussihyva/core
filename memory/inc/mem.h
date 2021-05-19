/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 05:08:28 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include "../../inc/types.h"

void				*mem_cpy(void *dst, const void *src, const t_size size);
void				*mem_cpy_safe(void *dst, const void *src, t_size size);
void				*mem_ccpy(void *dst, const void *src, int c, t_size size);
void				*mem_chr(const void *src, int c, t_size size);
void				*mem_move(void *dst, const void *src, t_size size);
void				*mem_set(void *src, int c, t_size size);
void				*mem_alloc(t_size size);
void				*mem_calloc(t_size nmemb, t_size size);
void				mem_del(void **ap);
void				mem_zero(void *src, t_size size);
int					mem_cmp(const void *s1, const void *s2, t_size size);

#endif
