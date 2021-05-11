/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:35:48 by skoskine          #+#    #+#             */
/*   Updated: 2021/05/11 10:18:32 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <unistd.h>

typedef char *	t_str;

t_str	str_new(size_t len);
t_str	str_dup(const char *src);
size_t	str_len(t_str src);
size_t	str_cmp(t_str s1, t_str s2);

#endif
