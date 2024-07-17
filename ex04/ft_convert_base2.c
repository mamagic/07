#include <stdlib.h>

int		len(char *str);
int		find_char(char ch, char *base_to);
int		cal_result_len(long long num, char *base_to);

char	*tranlate_loop(long long num, char *base_to, int size, char *arr)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		arr[0] = '-';
		num = -num;
	}
	while (num >= len(base_to))
	{
		arr[size - i - 2] = base_to[num % len(base_to)];
		num /= len(base_to);
		i++;
	}
	if (arr[0] == '-')
		arr[1] = base_to[num % len(base_to)];
	else
		arr[0] = base_to[num % len(base_to)];
	arr[size - 1] = '\0';
	return (arr);
}

char	*translate(long long num, char *base_to)
{
	char	*arr;
	int		size;

	size = cal_result_len(num, base_to);
	if (size <= 0)
		return NULL;
	arr = (char *)malloc(sizeof(char) * (size));
	arr = tranlate_loop(num, base_to, size, arr);
	return (arr);
}

int	cal_result_len(long long num, char *base_to)
{
	int	i;
	int	base_to_len;

	i = 2;
	if (num < 0)
	{
		i = 3;
		num = -num;
	}
	base_to_len = len(base_to);
	if (base_to_len <= 1)
		return 0;
	while (num >= base_to_len)
	{
		num /= base_to_len;
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	int_number;

	int_number = 0;
	if (check_base(base_from) || check_base(base_to))
		return (NULL);
	int_number = ten_base(nbr, base_from);
	if (int_number < -2147483648 || int_number > 2147483647)
		return (NULL);
	return (translate(int_number, base_to));
}
