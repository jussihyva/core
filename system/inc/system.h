#ifndef SYSTEM_H
# define SYSTEM_H
#include "../../inc/core.h"
#include <execinfo.h>
# define CR_FILE_POS &(t_file_pos){__FUNCTION__, __FILE__, __LINE__}

typedef t_parray t_page;

typedef struct	s_file_pos
{
	const char	*func;
	char		*file;
	size_t		line;
}				t_file_pos;

typedef struct	s_mem
{
	size_t		size;
	void		*data;
}				t_mem;

void	core_error(t_file_pos *err_pos, char *message);
void	core_debug(t_file_pos *file_pos, size_t count, ...);
void	core_activate();
void	core_deactivate();
void	core_log();
t_mem	core_malloc(size_t bytes);
ssize_t	core_realloc(t_mem *mem, size_t new_size);
void	core_free(t_mem *mem);
t_page	core_stacktrace(size_t offset);

#endif
