
#include "libft.h"

static int	find_number(int i)
{
	size_t	intnum;

	intnum = 1;
	if (i < 0)
		i *= -1;
	if (i >= 1000000000)
		return (intnum = 10);
	if (i >= 100000000)
		return (intnum = 9);
	if (i >= 10000000)
		return (intnum = 8);
	if (i >= 1000000)
		return (intnum = 7);
	if (i >= 100000)
		return (intnum = 6);
	if (i >= 10000)
		return (intnum = 5);
	if (i >= 1000)
		return (intnum = 4);
	if (i >= 100)
		return (intnum = 3);
	if (i >= 10)
		return (intnum = 2);
	return (intnum = 1);
}

static char	*ft_reverse(char *res)
{
	size_t		i;
	size_t		j;
	char		tmp;

	j = 0;
	i = ft_strlen(res) - 1;
	while (i > j)
	{
		tmp = res[i];
		res[i] = res[j];
		res[j] = tmp;
		j++;
		i--;
	}
	return (res);
}

static char	*fill_str(char *res, int n, int i, int j)
{
	while (i > j)
	{
		res[j++] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	j;
	int		tmp;
	char	*res;

	j = 0;
	tmp = n;
	if (n == -2147483648)
		return (res = ft_substr("-2147483648", 0, 11));
	i = find_number(n);
	if (tmp < 0)
	{
		res = malloc((i + 2) * sizeof(char));
		n *= -1;
	}
	else
		res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res = fill_str(res, n, i, j);
	if (tmp < 0)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_reverse(res));
}
