#ifndef SYSTEM_INTERNAL_H
# define SYSTEM_INTERNAL_H
#include "../../inc/core.h"

typedef struct	s_core
{
	uint8_t		active : 1;
	uint8_t		track_errors : 1;
	uint8_t		track_errors_backtrace : 1;
	uint8_t		track_allocs : 1;
	uint8_t		track_allocs_backtrace : 1;
	t_parray	errors;
	t_parray	allocs;
}				t_core;

typedef struct	s_tracker
{
	t_mem		mem;
	t_page		trace;
}				t_tracker;

typedef struct	s_error
{
	char		*message;
	t_page		trace;
}				t_error;

t_core	*core_static();

#endif
