/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lin_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/26 13:03:05 by jkoskela         ###   ########.fr       */
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

static ssize_t	deallocate_str(void *data, size_t i)
{
	free(data);
	return (i);
}

void	transform(t_arr *buffer)
{
	t_mat4	scale;
	t_vec4	*cast;
	size_t	i;

	scale = lin_m4_transform(100);
	lin_m4_print(&scale);
	cast = (t_vec4 *)buffer->data;
	i = 0;
	while (i < buffer->len)
	{
		cast[i] = lin_m4xv4_r(&scale, &cast[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_parr	file;
	t_arr	buffer;

	if (argc != 2)
		return (0);
	file = parr_new(1);
	buffer = arr_new(sizeof(t_vec4));
	parr_read_file(&file, argv[1]);
	parse_vec(&buffer, &file);
	transform(&buffer);
	arr_iter(&buffer, lin_v4_print);
	parr_iter(&file, deallocate_str);
	parr_free(&file);
	arr_free(&buffer);
}

