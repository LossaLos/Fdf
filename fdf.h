
#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

# include <stddef.h>
# include <math.h>
# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_img
{
	char	*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image_ptr;
	int		width_gr;
	int		height_gr;
	t_list	*pointt;
	t_img	img;
	int		witdh;
}				t_mlx;

typedef struct s_scale
{
	double	scale_x;
	double	scale_y;
}				t_scale;

typedef struct s_max
{
	double	max_x;
	double	max_y;
	double	min_x;
	double	min_y;
}				t_max;

typedef struct s_offset
{
	int	center_x;
	int	center_y;
	int	offset_x;
	int	offset_y;
}				t_offset;

typedef struct s_draw
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}				t_draw;

int			mini_main(t_list *map, int witdh);
int			process_element(char *elem, int x, int y, t_list **stack);
int			process_arg(char *arg, int y, t_list **stack, int *w_count);
int			witdh_count(char **tab);

void		center_isometric_projection(t_list *list, \
			int win_width, int win_heig);
void		exit_fail(t_list **stack);
void		ft_clear(t_mlx *data, t_list *map);
void		close_window(t_mlx *data);
void		draw_line(t_img *img, t_point *start, t_point *end);

char		*ft_strstr(char *str, char *to_find);
char		**ft_freee(char **tab);

t_point		*create_new_point(int x, int y, int z);

#endif
