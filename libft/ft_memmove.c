
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = n;
	if ((void *)dest == NULL && (void *)src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	if (d > s && d < s + n)
	{
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
