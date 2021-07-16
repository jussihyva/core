#ifndef RNG_H
# define RNG_H
#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
///
/// rng.h
///
/// \authors Julius Koskela
///
/// \brief Header for random data generation.
///
///////////////////////////////////////////////////////////////////////////////

# include "../../../inc/types.h"

t_uint32	rng();
void		rng_seed(unsigned int seed);
t_int32		rng_range(t_int32 min, t_int32 max);
void		rng_string(char *dst, t_size size);

#ifdef __cplusplus
}
#endif
# endif