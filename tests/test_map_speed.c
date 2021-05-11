
#include "../inc/core.h"
#include "assert.h"

size_t	iters = 800000;

void rand_str(char *dest, size_t length)
{
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0)
	{
        size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
        *dest++ = charset[index];
    }
    *dest = '\0';
}


ssize_t	test_map_insert_speed(t_map *testmap)
{
	char	key[7];
	size_t	val = 666;
	size_t	i;

	i = 0;
	while (i < iters)
	{
    	rand_str(key, sizeof key - 1);
		map_add(testmap, &val, key);
		i++;
	}
	return (1);
}

int main(void)
{
	t_map	testmap;

	testmap = map_new();
	test_map_insert_speed(&testmap);
}

