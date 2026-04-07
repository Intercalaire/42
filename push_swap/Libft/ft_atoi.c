
int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	result;
	size_t	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || ('\t' <= nptr[i] && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result += nptr[i] - '0';
		if (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
			result = result * 10;
		i++;
	}
	result = result * sign;
	return (result);
}
