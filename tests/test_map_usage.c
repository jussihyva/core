#include "../inc/core.h"

int main(void)
{
	t_map	m;
	char	*course;

	map_new(&m, 10, CR_MAP_QUADRATIC, map_hash_fast);
	map_add(&m, "Quantum Physics 1", "qp01");
	map_add(&m, "Quantum Physics 2", "qp02");
	map_add(&m, "Computer Science 1", "cs01");
	map_add(&m, "Computer Science 2", "cs02");
	map_add(&m, "Computer Science 3", "cs03");
	map_add(&m, "Computer Science 4", "cs04");
	map_add(&m, "Chemistry 1", "ch01");
	map_add(&m, "Chemistry 2", "ch02");
	map_add(&m, "Quantum Chromodynamics", "qd00");

	course = NULL;
	course = map_get(&m, "cs01");
	printf("Course: %s\n", course);

	map_del(&m, "ch01");

	course = map_get(&m, "ch01");
	printf("Course: %s\n", course);

	course = map_get(&m, "cs03");
	printf("Course: %s\n", course);

	map_add(&m, "Computer Science 1", "cs01");
	course = map_get(&m, "ch01");
	printf("Course: %s\n", course);
	map_print(&m);
	map_free(&m);
}
