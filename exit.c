
#include "fdf.h"

void	exit_fail(t_list **stack)
{
	ft_lstclear(stack, free);
	write(1, "MAP error\n", 10);
	exit(0);
}

void	ft_clear(t_mlx *data, t_list *map)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->image_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_lstclear(&map, free);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	exit(EXIT_SUCCESS);
}
