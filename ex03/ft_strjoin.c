#include <stdlib.h>
#include <stdio.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int loop(int size, char **strs, char *sep, char *result)
{
	int	i;
	int j;
	int result_index;	

	i = 0;
	result_index = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			result[result_index++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
			result[result_index++] = sep[j++];
		i++;
	}
	return result_index;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		r_len;
	int		i;
	char	*result;
	int		result_index;

	result_index = 0;
	r_len = 0;
	i = 0;
	while (i < size)
		r_len += len(strs[i++]);
	if(size > 0)
		r_len += (size - 1) * len(sep);
	result = (char *)malloc(sizeof(char) * (r_len + 1));
	result_index = loop(size, strs, sep, result);
	if (result == NULL)
		return (NULL);
	result[result_index] = '\0';
	return (result);
}

int	main(void)
{
	char	*strs1[] = {"Hello", "World", "42"};
	char	*sep1;
	char	*result1;
	char	*strs2[] = {"foo", "bar", "baz"};
	char	*sep2;
	char	*result2;
	char	*strs3[] = {"single"};
	char	*sep3;
	char	*result3;

	sep1 = ", ";
	result1 = ft_strjoin(3, strs1, sep1);
	printf("%s\n", result1); // Expected: "Hello, World, 42"
	sep2 = "-";
	result2 = ft_strjoin(3, strs2, sep2);
	printf("%s\n", result2); // Expected: "foo-bar-baz"
	sep3 = ",";
	result3 = ft_strjoin(1, strs3, sep3);
	printf("%s\n", result3); // Expected: "single"
	return (0);
}
