
#include "fdf.h"

void	free_map(char *line, t_list *stack)
{
	free(line);
	exit_fail(&stack);
}

void	check_line(char *line)
{
	if (line[2] == '\0')
	{
		free(line);
		write(1, "MAP Error", 10);
		exit(EXIT_FAILURE);
	}
}

t_list	*get_map(int fd, t_list *stack, int *width)
{
	int		y;
	char	*line;
	int		t;

	y = 0;
	line = get_next_line(fd);
	check_line(line);
	if (!line)
		free_map(line, stack);
	while (line != NULL)
	{
		t = process_arg(line, y++, &stack, width);
		if (t == 0)
			free_map(line, stack);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (stack);
}

int	main(int gc, char **gv)
{
	int		fd;
	int		width;
	t_list	*stack;
	t_list	*map;

	if (gc != 2 || (ft_strstr(gv[1], ".fdf") == NULL))
		return (write(2, "ARG Error\n", 10));
	fd = open(gv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Invalid ARG\n", 12);
		exit(0);
	}
	stack = NULL;
	map = get_map(fd, stack, &width);
	close(fd);
	mini_main(map, width);
	return (0);
}
