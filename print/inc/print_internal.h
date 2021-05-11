/*******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 ******************************************************************************/

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

int				ft_vasprintf(char **ret, const char *format, va_list ap);
int				ft_asprintf(char **ret, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

int				parse(const char *format, va_list *ap, char **result);
int				get_conversion_specs(t_data *specs, const char *format);
int				parse_percentage(t_data *specs, char **result);
int				parse_string(t_data *specs, char *str, char **result);
int				parse_char(t_data *specs, char c, char **result);
int				parse_pointer(t_data *specs, void *ptr, char **result);
int				parse_ints(t_data *specs, va_list *ap, char **result);
int				parse_unsigned_ints(t_data *specs, va_list *ap, char **result);
int				parse_signed_ints(t_data *specs, va_list *ap, char **result);
int				parse_doubles(t_data *specs, va_list *ap, char **result);
int				parse_double(t_data *specs, double value, char **result);
int				parse_long_double(t_data *specs, long double value,
					char **result);
char			*parse_int_result(t_data *specs, char *number,
					size_t result_len);

size_t			add_padding(size_t len, char c, char *result);
size_t			add_prefix(t_data *specs, char *result);
size_t			add_number(t_data *specs, char *number, char *result);
char			*ft_dtoa(double nbr, size_t precision);
long double		round_double(double nbr, size_t precision);
int				rounds_half_to_even(double nbr, int precision);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isspace(int c);
void			*ft_realloc(void *ptr, size_t ptr_size, size_t size);
char			*ft_uintmax_itoa_base(uintmax_t n, int base, int uppercase);
char			*ft_intmax_itoa_base(intmax_t n, int base);
double			ft_dpow(double base, int power);
int				ft_isnegative(double nbr);
int				ft_isnan(double nbr);
int				ft_isposinf(double nbr);
int				ft_isneginf(double nbr);
double			ft_modf(double value, double *iptr);
int				ft_abs(int n);
double			ft_fabs(double nbr);
long double		ft_fabsl(long double nbr);
uintmax_t		ft_uintmax_pow(int base, int power);
double			ft_sqrt(double value);

#endif
