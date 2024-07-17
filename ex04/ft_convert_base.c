
int			find_char(char ch, char *base_to);
int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	white_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || white_space(base[i]))
			return (1);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long long	ten_base(char *nbr, char *base)
{
	int			sign;
	long long	result;

	result = 3000000000;
	result = 0;
	sign = 1;
	while (white_space(*nbr))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	if (*(nbr + 1) == ' ')
		return (result);
	else
		result = 0;
	while (*nbr != '\0')
	{
		result = result * len(base) + find_char(*nbr, base);
		nbr++;
	}
	return (sign * result);
}

int	find_char(char ch, char *base_to)
{
	int	i;

	i = 0;
	while (base_to[i] != '\0')
	{
		if (base_to[i] == ch)
			return (i);
		i++;
	}
	return (len(base_to) + 1);
}
