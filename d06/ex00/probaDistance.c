#include <stdlib.h>

double probaDistance(int dist, int *locations, int n)
{
	int		i = 0;
	int		j = 1;
	int		count = 0;
	int		possible = 0;

	while (i < n)
	{
		while( j < n)
		{
			if ((locations[j] - locations[i]) > dist)
				count++;
			possible++;
			j++;
		}
		i++;
		j = i + 1;
	}
	return ((count * 1.0) / (possible * 1.0));
}
