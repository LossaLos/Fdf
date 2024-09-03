
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next;

	if (lst)
	{
		while (lst)
		{
			next = lst->next;
			f(lst->content);
			lst = next;
		}
	}
}
