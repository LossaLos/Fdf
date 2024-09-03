
#include "fdf.h"

int	get_color(int z)
{
	if (z <= -10)
		return (0xDC1FFF);
	else if (z <= -8)
		return (0xDD55FF);
	else if (z <= -6)
		return (0xDE88FF);
	else if (z <= -4)
		return (0xDFBBFF);
	else if (z <= -2)
		return (0xE0EEFF);
	else if (z < 0)
		return (0xCCCCFF);
	else if (z == 0)
		return (0xB9FFFF);
	else if (z <= 2)
		return (0x7AFFD4);
	else if (z <= 4)
		return (0x3BFFAA);
	else if (z <= 6)
		return (0x00FF80);
	else if (z <= 8)
		return (0x00FF55);
	else
		return (0x00FFA3);
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	int	position;

	if (x < 0 || x >= 2000 || y < 0 || y >= 2000)
		return ;
	position = (y * img->line_bytes + x * (img->pixel_bits / 8));
	*(int *)(img->buffer + position) = color;
}

void	init_draw(t_draw *draw, t_point *start, t_point *end)
{
	draw->x0 = start->x;
	draw->y0 = start->y;
	draw->x1 = end->x;
	draw->y1 = end->y;
	draw->color = get_color(end->z);
	draw->dx = draw->x1 - draw->x0;
	draw->dy = draw->y1 - draw->y0;
	if (draw->x0 < draw->x1)
		draw->sx = 1;
	else
		draw->sx = -1;
	if (draw->y0 < draw->y1)
		draw->sy = 1;
	else
		draw->sy = -1;
	if (draw->dx < 0)
		draw->dx = -draw->dx;
	if (draw->dy < 0)
		draw->dy = -draw->dy;
	if (draw->dx > draw->dy)
		draw->err = draw->dx / 2;
	else
		draw->err = -draw->dy / 2;
}

void	draw_line(t_img *img, t_point *start, t_point *end)
{
	t_draw	draw;

	init_draw(&draw, start, end);
	while (1)
	{
		put_pixel_to_image(img, draw.x0, draw.y0, draw.color);
		if (draw.x0 == draw.x1 && draw.y0 == draw.y1)
			break ;
		draw.e2 = draw.err;
		if (draw.e2 > -draw.dx)
		{
			draw.err -= draw.dy;
			draw.x0 += draw.sx;
		}
		if (draw.e2 < draw.dy)
		{
			draw.err += draw.dx;
			draw.y0 += draw.sy;
		}
	}
}
