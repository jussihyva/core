/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_dcnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:59:53 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:30:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

size_t	math_dcnt(uint64_t nb, uint64_t base)
{
	return ((uint64_t)((math_log(nb) / math_log(base)) + 1));
}

/*
**  ----------------------------------------------------------------------------
**
**	math__digits_base
**
**	Calculate number of digits in `nb` in `base`. floor(log(nb) / log(base)
**
**  ----------------------------------------------------------------------------
*/
