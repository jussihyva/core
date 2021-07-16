#include <iostream>
#include <string>
#include <unordered_map>
#include "../../inc/core.h"
#include <time.h>
#include <stdio.h>
#include <assert.h>

using namespace std;

typedef struct s_args
{
	unordered_map
	<string, string>	map;
	t_parray			keys;
}	t_args;

double	test_clock(
		void *args,
		void (*f)(void *))
{
	clock_t begin = clock();
	f(args);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	return (time_spent);
}

void	bench_map_add(void *ptr)
{
	t_args	*args;
	char	*key;
	t_size	i;

	args = (t_args *)ptr;
	i = 0;
	while (i < args->keys.len)
	{
		key = (char *)parr_get(&args->keys, i);
		args->map[key] = "PAYLOAD";
		i++;
	}
}

void	bench_map_get(void *ptr)
{
	t_args	*args;
	char	*key;
	std::string ret;
	t_size	i;

	args = (t_args *)ptr;
	i = 0;
	while (i < args->keys.len)
	{
		key = (char *)parr_get(&args->keys, i);
		ret = args->map[key];
		assert(s_cmp(&ret[0], "PAYLOAD") == 0);
		i++;
	}
}

void	bench_map_del(void *ptr)
{
	t_args	*args;
	char	*key;
	t_size	i;

	args = (t_args *)ptr;
	i = 0;
	while (i < args->keys.len)
	{
		key = (char *)parr_get(&args->keys, i);
		args->map[key].erase();
		i++;
	}
}

void	free_string(const void *str)
{
	free((char *)str);
}

int main(int argc, char **argv)
{
	t_args		args;
	t_size		count;
	t_size		keysize;


	if (argc < 3)
	{
		print("usage: test[count][keysize]\n");
		return (0);
	}
	rng_seed(0);
	count = s_toi(argv[1]);
	keysize = s_toi(argv[2]);
	parr_new(&args.keys, 1);
	while (count--)
	{
		char *str = (char *)malloc(keysize + 1);
		rng_string(str, keysize);
		parr_add_last(&args.keys, str);
	}
	print("add: %f\n", test_clock(&args, bench_map_add));
	print("get: %f\n", test_clock(&args, bench_map_get));
	print("del: %f\n", test_clock(&args, bench_map_del));
	parr_foreach(&args.keys, free_string);
	parr_free(&args.keys);
}
