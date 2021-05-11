/*******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 ******************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

static int	has_exact_fraction(double nbr, int precision, double div)
{
	double		int_part;
	double		frac_part;
	uintmax_t	integral_frac;

	frac_part = ft_modf(ft_fabs(nbr), &int_part);
	integral_frac = (uintmax_t)(frac_part * div * 10);
	if (integral_frac % ft_uintmax_pow(5, precision + 1) == 0)
		return (1);
	else
		return (0);
}

int	rounds_half_to_even(double nbr, int precision)
{
	double	div;

	div = ft_dpow(10.0, precision);
	if (ft_fabs(nbr * div) - (uintmax_t)ft_fabs(nbr * div) != 0.5)
		return (0);
	if (has_exact_fraction(nbr, precision, div))
		return (1);
	else
		return (0);
}

static double	round_half_to_even(double nbr, double div, size_t precision)
{
	double	tmp;
	double	int_part;
	double	frac_part;

	tmp = nbr;
	if (precision == 0)
	{
		tmp /= 10;
		precision = 1;
	}
	frac_part = ft_modf(tmp, &int_part);
	while (precision-- > 0)
		frac_part *= 10;
	if ((uintmax_t)frac_part % 2 == 0 && nbr < 0.0)
		return (nbr + 0.5 / div);
	else if ((uintmax_t)frac_part % 2 == 0 && nbr >= 0.0)
		return (nbr - 0.5 / div);
	else if (nbr < 0.0)
		return (nbr - 0.5 / div);
	else
		return (nbr + 0.5 / div);
}

long double	round_double(double nbr, size_t precision)
{
	size_t		i;
	double		div;
	long double	long_nbr;

	i = 0;
	div = 1.0;
	long_nbr = nbr;
	while (i++ < precision)
		div *= 10;
	if (rounds_half_to_even(nbr, (int)precision))
		long_nbr = round_half_to_even(nbr, div, precision);
	if (ft_isnegative(nbr))
		long_nbr = (long_nbr - 0.5 / div);
	else
		long_nbr = (long_nbr + 0.5 / div);
	return (long_nbr);
}