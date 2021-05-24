#include "../inc/string.h"

static t_int64	verify_base_nbr(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= ('A' + base - 10))
		|| (c >= 'a' && c <= ('a' + base - 10)));
}

t_int64	str_toi_base(const t_str str, t_int64 base)
{
	const char	*ptr;
	t_int64		nbr;
	int			sign;
	t_size		i;

	ptr = (const char *)str.raw.data;
	if (!ptr || (base < 2 || base > 16))
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	while (is_wspace(ptr[i]))
		i += 1;
	if (ptr[i] == '-' || ptr[i] == '+')
		ptr[i++] == '-' ? sign *= -1 : sign;
	while (ptr[i] && verify_base_nbr(ptr[i], base))
	{
		if (ptr[i] >= 'A' && 'F' >= ptr[i])
			nbr = (nbr * base) + (ptr[i] - 'A' + 10);
		else if (ptr[i] >= 'a' && 'f' >= ptr[i])
			nbr = (nbr * base) + (ptr[i] - 'a' + 10);
		else
			nbr = (nbr * base) + (ptr[i] - '0');
		i += 1;
	}
	return (nbr * sign);
}
