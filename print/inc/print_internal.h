/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#ifndef PRINT_INTERNAL_H
# define PRINT_INTERNAL_H

# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include <stdint.h>
# include <sys/types.h>

typedef struct s_data
{
	int		alt_form;
	int		zero_padding;
	int		neg_field_width;
	int		blank_signed;
	int		plus_signed;
	size_t	min_field_width;
	int		has_precision;
	size_t	precision;
	int		zero_precision;
	char	length_modifier[3];
	char	conversion;
	int		is_negative;
	int		is_zero;
}			t_data;

int				_vasprint(char **ret, const char *format, va_list ap);
int				_parse(const char *format, va_list *ap, char **result);
int				_get_conversion_specs(t_data *specs, const char *format);
int				_parse_percentage(t_data *specs, char **result);
int				_parse_string(t_data *specs, char *str, char **result);
int				_parse_char(t_data *specs, char c, char **result);
int				_parse_pointer(t_data *specs, void *ptr, char **result);
int				_parse_ints(t_data *specs, va_list *ap, char **result);
int				_parse_unsigned_ints(t_data *specs, va_list *ap, char **result);
int				_parse_signed_ints(t_data *specs, va_list *ap, char **result);
int				_parse_doubles(t_data *specs, va_list *ap, char **result);
int				_parse_double(t_data *specs, double value, char **result);
int				_parse_long_double(t_data *specs, long double value,
					char **result);
char			*_parse_int_result(t_data *specs, char *number,
					size_t result_len);
size_t			_add_padding(size_t len, char c, char *result);
size_t			_add_prefix(t_data *specs, char *result);
size_t			_add_number(t_data *specs, char *number, char *result);
char			*_dtoa(double nbr, size_t precision);
long double		_round_double(double nbr, size_t precision);
int				_rounds_half_to_even(double nbr, int precision);
int				_atoi(const char *str);
void			*_realloc(void *ptr, size_t ptr_size, size_t size);
char			*_uintmax_itoa_base(uintmax_t n, int base, int uppercase);
char			*_intmax_itoa_base(intmax_t n, int base);
double			_dpow(double base, int power);
double			_modf(double value, double *iptr);
int				_abs(int n);
double			_fabs(double nbr);
long double		_fabsl(long double nbr);
uintmax_t		_uintmax_pow(int base, int power);
double			_sqrt(double value);

#endif
