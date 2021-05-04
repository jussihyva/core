#include "../inc/core.h"

int main(void)
{
	t_map	m;
	char	*course;

	m = map_new();
	course = NULL;
	map_add(&m, "Quantum Physics 1", "qp01");
	map_add(&m, "Quantum Physics 2", "qp02");
	map_add(&m, "Computer Science 1", "cs01");
	map_add(&m, "Computer Science 2", "cs02");
	course = map_get(&m, "qp02");
	printf("Course: %s\n", course);
}