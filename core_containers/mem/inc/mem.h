/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief A hash map implementation library.
 *
 *****************************************************************************/

#ifndef MEM_H
# define MEM_H

#include "../../../inc/types.h"

t_hmem		hmem_range(t_mem src, size_t s, size_t t);

t_mem		mem_new(t_size bytes);
t_ssize		mem_realloc(t_mem *mem, t_size new_size);
void		mem_free(t_mem *mem);
t_mem		mem_cpy(t_mem dst, t_mem src, size_t size);
t_mem		mem_assign(void *src, size_t size);
t_hmem		mem_chr(t_mem src, t_mem b);
void		mem_print(t_mem src);

#endif
