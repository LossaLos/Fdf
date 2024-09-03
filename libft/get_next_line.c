
#include "libft.h"

static int	ft_strchr_pos(const char *s, int c)
{
	unsigned char	uc;
	size_t			i;

	i = 0;
	uc = (unsigned char)c;
	while (*s != '\0')
	{
		if (*(unsigned char *)s == uc)
		{
			return (i + 1);
		}
		s++;
		i++;
	}
	if (uc == '\0')
	{
		return (i);
	}
	return (i);
}

static void	append_to_backup(char **backup, char *buf, int reading)
{
	char	*tmp;

	buf[reading] = '\0';
	tmp = *backup;
	*backup = ft_strjoin(tmp, buf);
	free(tmp);
}

static char	*extract_line(int fd, char *buf, char *backup)
{
	int		reading;

	reading = 1;
	while (reading > 0)
	{
		reading = read(fd, buf, BUFFER_SIZE);
		if (reading == -1)
			return (NULL);
		else if (reading == 0)
			break ;
		if (backup == NULL)
		{
			backup = ft_strdup("");
			if (!backup)
				return (NULL);
		}
		append_to_backup(&backup, buf, reading);
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	return (backup);
}

static char	*extract_after(char *line)
{
	size_t	i;
	size_t	line_len;
	char	*save;

	line_len = ft_strlen(line);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	save = ft_substr (line, i + 1, line_len - i);
	if (!save)
		return (NULL);
	if (save[0] == '\0')
	{
		free(save);
		save = NULL;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	char		*tmp;
	static char	*save = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		free(save);
		return (save = NULL, NULL);
	}
	buf = malloc ((BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = extract_line (fd, buf, save);
	free (buf);
	if (!line)
		return (NULL);
	save = extract_after (line);
	tmp = ft_substr (line, 0, ft_strchr_pos(line, '\n'));
	free(line);
	if (!tmp)
		return (NULL);
	return (tmp);
}
