#ifndef TESTING_H
# define TESTING_H

# include "../../inc/types.h"

double	test_clock(void *params, void (*f)(void *));
t_int32	test_rng(t_int32 min, t_int32 max, t_int32 seed);

#endif
