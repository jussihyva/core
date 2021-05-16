#ifndef SYSTEM_H
# define SYSTEM_H
#include "../../inc/core.h"
#include <execinfo.h>
# define CR_RECOVERY_POLICY 0
# define CR_FILE_POS &(t_file_pos){__FUNCTION__, __FILE__, __LINE__}
# define CR_MEM_NULL (t_mem) {0, NULL}
# define DEBUG core_debug
# define ERROR core_error
# define CR_ACTIVE 1
# define CR_TRACK_ALLOC 1
# define CR_TRACK_ALLOC_BACKTRACE 1
# define CR_TRACK_ERROR 1
# define CR_TRACK_ERROR_BACKTRACE 1

typedef struct	s_error_pos
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

typedef struct	s_system_flags
{
	uint8_t		track_errors : 1;
	uint8_t		track_allocs : 1;
}				t_system_flags;

typedef struct	s_core
{
	uint8_t		active : 1;
	uint8_t		track_errors : 1;
	uint8_t		track_errors_backtrace : 1;
	uint8_t		track_allocs : 1;
	uint8_t		track_allocs_backtrace : 1;
	t_parray	errors;
	t_parray	allocs;
	size_t		alloc_index;
}				t_core;

typedef struct	s_tracker
{
	t_mem		mem;
	char		*trace;
}				t_tracker;

typedef struct	s_error
{
	char		*message;
	char		*trace;
}				t_error;

t_core	g_core;

void	core_error(t_file_pos *err_pos, char *message);
void	core_debug(t_file_pos *file_pos, size_t count, ...);
void	core_activate();
void	core_deactivate();
void	core_log();
t_mem	core_malloc(size_t bytes);
t_mem	core_realloc(size_t bytes);
void	core_free(t_mem *mem);
char	*core_stacktrace(size_t offset);

#endif
