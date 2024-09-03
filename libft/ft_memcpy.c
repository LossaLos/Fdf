
#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	size_t			i;
	char			*dest;
	const char		*sourc;

	if ((char *)from == NULL && (char *)to == NULL)
	{
		return (NULL);
	}
	dest = (char *)to;
	sourc = (char *)from;
	i = 0;
	while (i < n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (to);
}
