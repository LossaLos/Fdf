
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (nb > (LONG_MAX - (*nptr - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(nb * sign));
}
