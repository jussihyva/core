/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief
 *
 *****************************************************************************/

#ifndef MATH_H
# define MATH_H

# include "../../inc/core.h"
# include "../../array/inc/arr.h"

double				math_rad(double dgr);
double				math_dgr(double rad);
double				math_sqrt(double n);
int64_t				math_log(int64_t n);
int					math_intlen(int64_t n);
double				math_fabs(double n);
long double			math_flabs(long double n);
double				math_pow(double base, double exp);
double				math_sin(double x, int64_t p);
double				math_cos(double x, int64_t p);
int64_t				math_fac(int64_t n);
uint64_t			math_prime(uint64_t n);
uint64_t			math_nextprime(uint64_t n);
t_array				math_primefac(uint64_t n);
size_t				math_dcnt(uint64_t nb, uint64_t base);
double				math_ceil(double f);
double				math_floor(double x);
double				math_modf(double x, double *iptr);
long double			math_modl(long double x, long double *iptr);
int64_t				math_abs(int64_t n);
int					math_sign(int64_t n);
int					math_fsign(long double n);
long double			math_roundl(long double x);
int64_t				math_ipow(int64_t base, int64_t exp);

#endif
