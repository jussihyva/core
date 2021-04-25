/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lin_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 11:40:17 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

ssize_t	parse_vec(t_arr *dst, t_parr *src)
{
	t_vec4	curr;
	size_t	i;

	i = 0;
	while (i < src->len - 10)
	{
		curr.v[0] = atof(parr_get(src, i));
		curr.v[1] = atof(parr_get(src, i + 1));
		curr.v[2] = atof(parr_get(src, i + 2));
		curr.v[3] = atof(parr_get(src, i + 3));
		arr_add_last(dst, &curr);
		i += 4;
	}
	return (i);
}


int		main(int argc, char **argv)
{
	t_parr	file;
	t_arr	buffer;

	file = parr_new(1);
	buffer = arr_new(1, sizeof(t_vec4));
	parr_read_file(&file, argv[1]);
	parse_vec(&buffer, &file);
	arr_iter(&buffer, lin_v4_print);
	parr_free(&file);
	arr_free(&buffer);
}

/*
 * Comment
 */
