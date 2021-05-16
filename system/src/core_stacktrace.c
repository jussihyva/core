#include "../inc/system.h"
# define CR_STACK_TRACE_MAX 1024

char	*core_stacktrace(size_t offset)
{
	char		*trace;
	char		**strings;
	size_t		size;
	void		*array[CR_STACK_TRACE_MAX];
	size_t		i;

	trace = NULL;
	offset++;
	size = backtrace(array, CR_STACK_TRACE_MAX);
	strings = backtrace_symbols(array, size);
	trace = s_join(trace, strings[offset]);
	trace = s_join_free(trace, "\n", 1);
	i = offset + 1;
	while (i < size)
	{
		trace = s_join_free(trace, strings[i], 1);
		trace = s_join_free(trace, "\n", 1);
		i++;
	}
	free(strings);
	return (trace);
}
