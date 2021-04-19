
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:06:47 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCORE_H
# define LIBCORE_H

# define CR_STOP -1
# define CR_CONTINUE 1
# define CR_FAIL 0
# define CR_EMPTY -1
# define CR_SUCCESS 1
# define CR_WRITE 0
# define CR_APPEND 1
# define CR_PREPEND -1

# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>

# include "../mem/inc/mem.h"
# include "../arr/inc/arr.h"

#endif
