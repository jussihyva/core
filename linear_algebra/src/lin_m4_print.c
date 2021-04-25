/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_m4_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 12:39:26 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lin.h"

void	lin_m4_print(t_mat4 *src)
{
	printf("|-----|-----|-----|-----|\n");
	printf("|%-5.2lf|%-5.2lf|%-5.2lf|%-5.2lf|\n",
		  src->m[0], src->m[1], src->m[2], src->m[3]);
	printf("|-----|-----|-----|-----|\n");
	printf("|%-5.2lf|%-5.2lf|%-5.2lf|%-5.2lf|\n",
		  src->m[4], src->m[5], src->m[6], src->m[7]);
	printf("|-----|-----|-----|-----|\n");
	printf("|%-5.2lf|%-5.2lf|%-5.2lf|%-5.2lf|\n",
		  src->m[8], src->m[9], src->m[10], src->m[11]);
	printf("|-----|-----|-----|-----|\n");
	printf("|%-5.2lf|%-5.2lf|%-5.2lf|%-5.2lf|\n",
		  src->m[12], src->m[13], src->m[14], src->m[15]);
	printf("|-----|-----|-----|-----|\n");
}