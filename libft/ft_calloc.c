
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	max;
	void	*target;

	max = (size_t) - 1;
	if (size > 0 && nmemb > max / size)
	{
		return (NULL);
	}
	if (nmemb == 0 || size == 0)
	{
		target = malloc (0);
	}
	else
		target = malloc (nmemb * size);
	if (target == NULL)
	{
		return (NULL);
	}
	ft_bzero (target, nmemb * size);
	return (target);
}
