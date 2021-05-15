#include "inc/core.h"
#include "print/inc/print_internal.h"
# define CR_RECOVERY_POLICY 0
# define CR_FILE_POS &(t_file_pos){__FUNCTION__, __FILE__, __LINE__}
# define CR_MEM_NULL (t_mem) {NULL, 0}
# define DEBUG core_debug
# define ERROR core_error

typedef struct	s_error_pos
{
	const char	*func;
	char		*file;
	size_t		line;
}				t_file_pos;

typedef struct	s_mem
{
	void		*data;
	size_t		size;
}				t_mem;

typedef struct	s_core
{
	uint8_t		set;
	t_parray	errors;
}				t_core;

t_core	g_core;

void	core_print_help()
{
	print("CORE NOT ACTIVE\n");
	print("- Activate with the function core_activate in the main method.\n");
	print("- Remember to deactivate at the end of the program with core_deactivate.\n");
}

void	core_error(t_file_pos *err_pos, char *message)
{
	char	*error;

	if (g_core.set == 0)
		core_print_help();
	error = format(
			"\033[1;31m%s\033[0m, \033[1;31m%s\033[0m, \033[1;31m%d\033[0m\n%s",
			err_pos->file,
			err_pos->func,
			err_pos->line,
			message);
	parr_add_last(&g_core.errors, error);
}

char	*core_debug(t_file_pos *file_pos, size_t count, ...)
{
	char	*ret;
	char	*header;
	va_list	ap;
	size_t	i;

	header = format(
			"\033[1;31m%s\033[0m, \033[1;31m%s\033[0m, \033[1;31m%d\033[0m",
			file_pos->file,
			file_pos->func,
			file_pos->line);
	print("DEBUG ");
	printf("%s\n", header);
	free(header);
	va_start(ap, count);
	i = 0;
	while (i < count)
	{
		ret = va_arg(ap, char *);
		print("%s", ret);
		free(ret);
		i++;
	}
	va_end(ap);
	print("\n");
	return (ret);
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

void	core_log()
{
	size_t	i;

	i = 0;
	while (i < g_core.errors.len)
	{
		print("ERROR ");
		printf("%s\n", (char *)parr_get(&g_core.errors, i));
		i++;
	}
}

t_mem	mem_new(size_t bytes)
{
	t_mem	out;

	out.data = malloc(bytes);
	out.size = bytes;
	if (!out.data && CR_RECOVERY_POLICY == 0)
	{
		core_error(CR_FILE_POS, "FAILED ALLOCATION");
		core_log();
		exit(-1);
	}
	else if (!out.data && CR_RECOVERY_POLICY == 1)
	{
		core_error(CR_FILE_POS, "FAILED ALLOCATION");
		return (CR_MEM_NULL);
	}
	return (out);
}

void	test_debug()
{
	size_t	i;
	char	*str;

	str = s_dup("abcdefg");
	i = s_len(str);
	while (i--)
	{
		if (str[i] == 'd' || str[i] == 'a')
		{
			DEBUG(CR_FILE_POS, 3,
			format("Position: %llu\n", i),
			format("Character: %c\n", str[i]),
			format("Pointer: %p\n", &str[i]));
		}
	}
	free(str);
}

void	test_error()
{
	ERROR(CR_FILE_POS, "A terrible error has occured!\n");	
	ERROR(CR_FILE_POS, "Another terrible error has occured!\n");	
	ERROR(CR_FILE_POS, "Yet another terrible error has occured!\n");	
	ERROR(CR_FILE_POS, "Please throw your computer in the bathtub!\n");	
}

int main(void)
{
	core_activate();
	test_debug();
	test_error();
	core_log();
	core_deactivate();
}
