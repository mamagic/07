#include <stdlib.h>

int	ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (i);
}

int	find_charset(char ch, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (charset[size] != '\0')
		size++;
	while (i < size)
	{
		if (charset[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int	size_charset(char *str, char *charset)
{
	int	word_p;
	int	size;

	word_p = 1;
	size = 0;
	while (*str != '\0')
	{
		if (!find_charset(*str, charset) && word_p)
		{
			word_p = 0;
			size++;
		}
		if (find_charset(*str, charset))
			word_p = 1;
		str++;
	}
	return (size + 1);
}

char	*input_arr(char *str, char *charset, char **arr, int i)
{
	int	arr_size;

	arr_size = 0;
	while (1)
	{
		if (find_charset(*str, charset) || *str == '\0')
			break ;
		arr_size++;
		str++;
	}
	arr[i] = (char *)malloc(sizeof(char) * arr_size);
	ft_strncpy(arr[i], str - arr_size, arr_size);
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * size_charset(str, charset));
	while (*str != '\0')
	{
		if (!find_charset(*str, charset))
		{
			str = input_arr(str, charset, arr, i);
			i++;
			if (*str == '\0')
				break ;
		}
		str++;
	}
	arr[i] = (char *)malloc(1);
	arr[i] = '\0';
	return (arr);
}
