#include "../inc/core.h"
# define DEBUG cr_debug
# define ERROR cr_error

void	test_debug()
{
	t_size	i;
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

void	test_malloc()
{
	t_mem	memory;

	memory = mem_new(sizeof(t_uint64));
	cr_log();
	mem_free(&memory);
}

int	main(void)
{
	cr_activate();
	printf("\n\033[32;1mCORE SYSTEM EXAMPLE\033[0m\n\n");
	print("Usage examples for core system.\n\n");
	printf("\n\033[32;1mMEMORY MANAGEMENT\033[0m\n\n");
	print("We can track memory allocationsand get size and allocation backtrace.\n\n");
	test_malloc();
	test_error();
	printf("\n\033[32;1mDEBUGGING\033[0m\n\n");
	print("We can create debug messages which contain file, func, line info.\n\n");
	test_debug();
	printf("\n\033[32;1mERROR HANDLING\033[0m\n\n");
	print("We can create error messages and print them with cr_log().\n\n");
	cr_log();
	cr_deactivate();
}
