
#include "libft.h"

void	*ft_bzero(void *ptr, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
	return (ptr);
}
