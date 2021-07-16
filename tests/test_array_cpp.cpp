#include "../inc/core.h"
#include <iostream>

void	print_int(void *data)
{
	std::cout << *(int *)data << "\n";
}

t_ssize	compare(void *c1, void *c2)
{
	return (*(int *)c1 - *(int *)c2);
}

int main(void)
{
	core::array	*A;
	core::map	*M;

	A = new core::array(1, sizeof(int));
	M = new core::map(10, CR_MAP_LINEAR, map_hash_fast);
	for (int i = 0; i < 100; i++)
	{
		int x = rng_range(1, 50);
		A->add_last(&x);
	}
	A->sort(compare);
	A->foreach(print_int);
	print("len = %d\n", A->len());
	delete A;
	delete M;
}