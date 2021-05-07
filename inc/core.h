
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
# define CR_SUCCESS 1
# define CR_FAIL 0
# define CR_TRUE 1
# define CR_FALSE 0
# define CR_NOALLOC 0
# define CR_EMPTY -1
# define CR_WRITE 0
# define CR_APPEND 1
# define CR_PREPEND -1
# define CR_STRING NULL
# define CR_PARR_NULL (t_parray) {NULL, 0, 0}
# define CR_ARR_NULL (t_array) {NULL, 0, 0, 0}
# define CR_GRAPH_NULL (t_graph) {CR_MAP_NULL, NULL}
# define CR_GRAPH_NULL_NODE (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, NULL, NULL}
# define CR_GRAPH_EDGE_NULL (t_graph_edge) {NULL, NULL, NULL}
# define CR_MAP_NULL_NODE (t_map_node) {NULL, NULL}
# define CR_MAP_NULL (t_map) {NULL, 0, 0, 0.0, NULL, NULL, NULL}
# define CR_MAP_START_CAPACITY 4
# define CR_MAP_LOAD_FACTOR 0.4
# define CR_MAP_HASH map_hash_1
# define CR_MAP_PROBE map_probe_quad_pow2
# define CR_MAP_RESIZE map_resize_pow2
# define CR_PI 3.14159265358979323846
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <stdbool.h>

# include "../memory/inc/mem.h"
# include "../array/inc/arr.h"
# include "../ptr_array/inc/parr.h"
# include "../linear_algebra/inc/lin.h"
# include "../cstring/inc/cstr.h"
# include "../map/inc/map.h"
# include "../graph/inc/graph.h"

#endif
