#include "inc/core.h"
# define CR_RECOVERY_POLICY 0

typedef struct	s_core
{
	uint8_t		set;
	t_parray	errors;
}				t_core;

t_core	g_core;

void	core_error(const char *func, char *file, size_t line, char *message)
{
	char	*error;

	if (g_core.set == 0)
	{
		print("CORE NOT ACTIVE\n");
		print("- Activate with the function core_activate in the main method.\n");
		print("- Remember to deactivate at the end of the program with core_deactivate.\n");
	}
	error = format("func: %s, file: %s, line %d\n%s", func, file, line, message);
	parr_add_last(&g_core.errors, error);
}

void	core_activate()
{
	g_core.errors = parr_new(1);
	g_core.set = 1;
}

void	core_deactivate()
{
	size_t	i;

	i = 0;
	while (i < g_core.errors.len)
	{
		free(parr_get(&g_core.errors, i));
		i++;
	}
	parr_free(&g_core.errors);
}

void	*core_malloc(size_t bytes)
{
	void	*out;

	out = malloc(bytes);
	if (CR_RECOVERY_POLICY == 0)
		exit(-1);
	else if (CR_RECOVERY_POLICY == 1)
	{
		core_error(__FUNCTION__, __FILE__, __LINE__, "FAILED ALLOCATION");
		return (NULL);
	}
	return (out);
}

void	core_log()
{
	size_t	i;

	i = 0;
	while (i < g_core.errors.len)
	{
		print("%s\n", parr_get(&g_core.errors, i));
		i++;
	}
}

int main(void)
{
	core_activate();
	size_t	i;

	i = 1;

	if (i == 1)
	{
		core_error(__FUNCTION__, __FILE__, __LINE__, "I IS NOT SUPPOSED TO BE 1!!!!");
	}
	core_log();
	core_deactivate();
}
