#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	range;
	int	i;

	range = max - min;
	if (range <= 0)
		return (0);
	result = (int *)malloc(sizeof(int) * range);
	if (result == 0)
		return (0);
	i = 0;
	while (min < max)
		result[i++] = min++;
	return (result);
}
