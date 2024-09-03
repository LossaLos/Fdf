
#include "fdf.h"

void	iso_projection(int *x, int *y, int z, int scale)
{
	double	radian_angle;
	int		scaled_x;
	int		scaled_y;

	radian_angle = 26.155 * (M_PI / 180);
	scaled_x = *x * (scale / 2.2);
	scaled_y = *y * (scale / 2.2);
	*x = scaled_x * cos(radian_angle) - scaled_y * sin(radian_angle);
	*y = ((scaled_x * sin(radian_angle) + \
		scaled_y * cos(radian_angle)) - z * (scale / 2.2));
}

int	get_scaleand_init_max(t_list *list, int win_width, t_max *max)
{
	t_list	*current;
	t_point	*point;
	int		total_width;
	int		total_height;

	max->min_x = INT_MAX;
	max->max_x = INT_MIN;
	max->min_y = INT_MAX;
	max->max_y = INT_MIN;
	current = list;
	while (current != NULL)
	{
		point = (t_point *)current->content;
		if (point->x < max->min_x)
			max->min_x = point->x;
		if (point->x > max->max_x)
			max->max_x = point->x;
		current = current->next;
	}
	total_width = max->max_x - max->min_x;
	total_height = max->max_y - max->min_y;
	return ((int)win_width / total_width);
}

void	get_minmax(t_max *max, t_point *point)
{
	if (point->x < max->min_x)
		max->min_x = point->x;
	if (point->x > max->max_x)
		max->max_x = point->x;
	if (point->y < max->min_y)
		max->min_y = point->y;
	if (point->y > max->max_y)
		max->max_y = point->y;
}

void	get_center_pos(t_offset *center, t_max max, \
			int win_height, int win_width)
{
	center->center_x = (max.min_x + max.max_x) / 2;
	center->center_y = (max.min_y + max.max_y) / 2;
	center->offset_x = (win_width / 2) - center->center_x;
	center->offset_y = (win_height / 2) - center->center_y;
}

void	center_isometric_projection(t_list *list, int win_width, int win_heig)
{
	t_max		max;
	t_offset	center;
	t_list		*current;
	t_point		*point;
	int			scale;

	current = list;
	scale = get_scaleand_init_max(list, win_width, &max);
	while (current != NULL)
	{
		point = (t_point *)current->content;
		iso_projection(&point->x, &point->y, point->z, scale);
		get_minmax(&max, point);
		current = current->next;
	}
	get_center_pos(&center, max, win_heig, win_width);
	current = list;
	while (current != NULL)
	{
		point = (t_point *)current->content;
		point->x += center.offset_x;
		point->y += center.offset_y;
		current = current->next;
	}
}
