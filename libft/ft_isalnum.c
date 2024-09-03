
int	ft_isalnum(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') \
		|| (a >= '0' && a <= '9'))
		return (1);
	else
		return (0);
}
