
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*list;
	t_list		*newelem;
	void		*result;

	list = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (lst)
	{
		result = f(lst->content);
		newelem = ft_lstnew(result);
		if (newelem == NULL)
		{
			ft_lstclear(&list, del);
			del(result);
			return (NULL);
		}
		ft_lstadd_back(&list, newelem);
		lst = lst->next;
	}
	return (list);
}
