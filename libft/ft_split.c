
#include "libft.h"

static char	**ft_free(char **res, int col)
{
	while (col > 0)
	{
		free(res[col - 1]);
		col--;
	}
	return (res);
}

static size_t	get_word_length(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static int	count_words(char const *s, char c)
{
	size_t	w;
	size_t	i;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			w++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (w);
}

static char	*extract_word(const char *s, char c)
{
	size_t	len;

	len = get_word_length(s, c);
	return (ft_substr(s, 0, len));
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		word_count;
	int		col;

	col = 0;
	word_count = count_words(s, c);
	res = malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (col < word_count)
	{
		while (*s == c)
			s++;
		res[col] = extract_word(s, c);
		if (!res[col])
		{
			ft_free(res, col);
			free(res);
			return (NULL);
		}
		s += get_word_length(s, c);
		col++;
	}
	res[word_count] = NULL;
	return (res);
}
