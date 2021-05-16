#include "../inc/map.h"
#include "../../inc/core.h"

uint64_t	map_resize_linear(uint64_t capacity)
{
	return (math_nextprime(capacity));
}
