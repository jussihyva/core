#include "../inc/system.h"

t_page	core_stacktrace(size_t offset)
{
	t_page		trace;
	char		**strings;
	size_t		size;
	void		*array[CR_STACK_TRACE_MAX];
	size_t		i;

	trace = parr_new(1);;
	offset++;
	size = backtrace(array, CR_STACK_TRACE_MAX);
	strings = backtrace_symbols(array, size);
	i = offset + 1;
	while (i < size)
	{
		parr_add_last(&trace, strings[i]);
		i++;
	}
	free(strings);
	return (trace);
}
