
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = size;
	while (n > 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	if (size > 0)
		*dst = '\0';
	while (*src != '\0')
	{
		src++;
		n--;
	}
	return (size - n);
}
