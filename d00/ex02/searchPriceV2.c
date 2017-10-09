#include "header.h"
#include <string.h>

static int binary_search(struct s_art **arts, int start, int end, char *name)
{
	int		mid;

	if (start > end)
		return (-1);
	mid = (start + end) / 2;
	if (strcmp(name, arts[mid]->name) < 0)
		return (binary_search(arts, start, mid - 1, name));
	else if (strcmp(name, arts[mid]->name) > 0)
		return (binary_search(arts, mid + 1, end, name));
	return (arts[mid]->price);
}
int searchPrice(struct s_art **arts, int n, char *name)
{
	return (binary_search(arts, 0, n - 1, name));
}
