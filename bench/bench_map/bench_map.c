#include "../../inc/core.h"
#include <assert.h>
#include <time.h>

t_size	iters = 100000;

typedef struct s_args
{
	t_map		map;
	t_parray	keys;
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

	args = ptr;
	i = 0;
	while (i < args->keys.len)
	{
		key = parr_get(&args->keys, i);
		map_add(&args->map, "PAYLOAD", key);
		i++;
	}
}

void	bench_map_get(void *ptr)
{
	t_args	*args;
	char	*key;
	char	*ret;
	t_size	i;

	args = ptr;
	i = 0;
	while (i < args->keys.len)
	{
		key = parr_get(&args->keys, i);
		ret = map_get(&args->map, key);
		assert(s_cmp(ret, "PAYLOAD") == 0);
		i++;
	}
}

void	bench_map_del(void *ptr)
{
	t_args	*args;
	char	*key;
	t_ret	ret;
	t_size	i;

	args = ptr;
	i = 0;
	while (i < args->keys.len)
	{
		key = parr_get(&args->keys, i);
		ret = map_del(&args->map, key);
		assert(ret >= 0);
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
	t_size		i;

	if (argc < 4)
	{
		print("usage: test[count][keysize][method]\n");
		return (0);
	}
	rng_seed(0);
	count = s_toi(argv[1]);
	keysize = s_toi(argv[2]);
	parr_new(&args.keys, 1);
	i = 0;
	while (i < count)
	{
		char *str = malloc(keysize + 1);
		rng_string(str, keysize);
		parr_add_last(&args.keys, str);
		i++;
	}
	if (s_cmp(argv[3], "L") == 0)
		map_new(&args.map, 1, CR_MAP_LINEAR, map_hash_fast);
	else
		map_new(&args.map, 1, CR_MAP_QUADRATIC, map_hash_fast);
	print("add: %f\n", test_clock(&args, bench_map_add));
	print("get: %f\n", test_clock(&args, bench_map_get));
	print("del: %f\n", test_clock(&args, bench_map_del));
	print("readd: %f\n", test_clock(&args, bench_map_add));
	if (s_cmp(argv[4], "PRINT") == 0)
		map_print(&args.map);
	map_free(&args.map);
	parr_foreach(&args.keys, free_string);
	parr_free(&args.keys);
}
