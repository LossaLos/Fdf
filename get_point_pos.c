
#include "fdf.h"

t_point	*create_new_point(int x, int y, int z)
{
	t_point	*new_point;

	if (x > 500 || y > 500 || z > 500 || z < -500)
		return (NULL);
	new_point = malloc(sizeof(t_point));
	if (!new_point)
		return (NULL);
	new_point->x = x;
	new_point->y = y;
	new_point->z = z;
	return (new_point);
}

int	process_element(char *elem, int x, int y, t_list **stack)
{
	t_list		*new_elem;
	t_point		*point;
	long long	z;

	z = ft_atoi(elem);
	point = create_new_point(x, y, z);
	if (!point)
		return (0);
	new_elem = ft_lstnew(point);
	if (new_elem == NULL)
	{
		free(point);
		return (0);
	}
	ft_lstadd_back(stack, new_elem);
	return (1);
}

int	process_arg(char *arg, int y, t_list **stack, int *w_count)
{
	char	**tab;
	int		x;
	int		t;

	t = 0;
	tab = ft_split(arg, ' ');
	if (!tab)
	{
		ft_freee(tab);
		return (0);
	}
	*w_count = witdh_count(tab);
	x = 0;
	while (tab[x])
	{
		t = process_element(tab[x], x, y, stack);
		if (t == 0)
		{
			ft_freee(tab);
			return (0);
		}
		x++;
	}
	ft_freee(tab);
	return (*w_count);
}
