
#include "fdf.h"

void	draw_bottom(t_img *img, t_list *cur, \
			t_point *current, t_point *neighbor)
{
	neighbor = (t_point *)(cur->content);
	draw_line(img, current, neighbor);
}

void	draw_lines_to_neighbors(t_img img, \
				t_list *points, int width)
{
	int		k;
	t_point	*current;
	t_list	*cur;
	t_point	*neighbor;
	int		i;

	k = 1;
	while (points != NULL && points->next != NULL)
	{
		current = (t_point *)(points->content);
		cur = points->next;
		neighbor = (t_point *)(cur->content);
		if (k % width != 0)
			draw_line(&img, current, neighbor);
		i = 0;
		cur = points;
		while (i++ < width && cur != NULL)
			cur = cur->next;
		if (cur != NULL)
			draw_bottom(&img, cur, current, neighbor);
		points = points->next;
		k++;
	}
}

void	get_move_keycode(t_point *point, int move_step, int keycode)
{
	if (keycode == 119)
		point->y -= move_step;
	else if (keycode == 97)
		point->x -= move_step;
	else if (keycode == 115)
		point->y += move_step;
	else if (keycode == 100)
		point->x += move_step;
}

void	key_press(int keycode, t_mlx *data)
{
	t_point	*point;
	t_list	*current;

	if (keycode == 65307)
		mlx_loop_end(data->mlx_ptr);
	else
	{
		current = data->pointt;
		while (current != NULL)
		{
			point = (t_point *)current->content;
			get_move_keycode(point, 10, keycode);
			current = current->next;
		}
		mlx_destroy_image(data->mlx_ptr, data->image_ptr);
		data->image_ptr = mlx_new_image \
			(data->mlx_ptr, data->width_gr, data->height_gr);
		data->img.buffer = mlx_get_data_addr(data->image_ptr, &data-> \
			img.pixel_bits, &data->img.line_bytes, &data->img.endian);
		draw_lines_to_neighbors(data->img, data->pointt, data->witdh);
		mlx_put_image_to_window \
			(data->mlx_ptr, data->win_ptr, data->image_ptr, 0, 0);
	}
}

int	mini_main(t_list *map, int witdh)
{
	t_mlx	data;

	data.witdh = witdh;
	data.pointt = map;
	data.height_gr = 2000;
	data.width_gr = 2000;
	center_isometric_projection(data.pointt, data.width_gr, data.height_gr);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window \
		(data.mlx_ptr, data.height_gr, data.width_gr, "Fdf");
	data.image_ptr = mlx_new_image \
		(data.mlx_ptr, data.height_gr, data.width_gr);
	data.img.buffer = mlx_get_data_addr(data.image_ptr, \
		&data.img.pixel_bits, &data.img.line_bytes, &data.img.endian);
	draw_lines_to_neighbors(data.img, data.pointt, witdh);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.image_ptr, 0, 0);
	mlx_key_hook(data.win_ptr, (void *)key_press, &data);
	mlx_hook(data.win_ptr, 17, 0, (void *)close_window, &data);
	mlx_loop(data.mlx_ptr);
	ft_clear(&data, map);
	return (0);
}
