#include "inc/core.h"
#include <iostream>

void	print_int(void *data)
{
	std::cout << *(int *)data << "\n";
}

int main(void)
{
	core::array	*A;
	core::map	*M;

	A = new core::array(1, sizeof(int));
	M = new core::map(10, CR_MAP_LINEAR, map_hash_fast);
	for (int i = 0; i < 100; i++)
		A->add_last(&i);
	A->foreach(print_int);
	print("len = %d\n", A->len());
	delete A;
	delete M;
}