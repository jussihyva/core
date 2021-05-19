#ifndef SYSTEM_H
# define SYSTEM_H

# include "../../ptr_array/inc/parr.h"
# include "../../inc/types.h"

typedef struct	s_file_pos
{
	const char	*func;
	char		*file;
	t_size		line;
}				t_file_pos;

void	core_error(t_file_pos *err_pos, char *message);
void	core_debug(t_file_pos *file_pos, t_size count, ...);
void	core_activate();
void	core_deactivate();
void	core_log();
t_mem	core_malloc(t_size bytes);
t_ssize	core_realloc(t_mem *mem, t_size new_size);
void	core_free(t_mem *mem);
t_page	core_stacktrace(t_size offset);

#endif
