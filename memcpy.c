# include "inc/core.h"

int main(void)
{
	char	*str = "MEMORY";


	char	*str2;

	str2 = malloc(s_len(str) + 1);
	str2 = mem_cpy(str2, str, s_len(str) + 1);
	print("%s\n", str2);
}
