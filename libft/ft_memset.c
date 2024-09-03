
#include "libft.h"

void	*ft_memset(void *ptr, int i, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (n > 0)
	{
		*p = (unsigned char)i;
		p++;
		n--;
	}
	return (ptr);
}
