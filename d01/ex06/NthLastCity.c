#include "header.h"
#include <string.h>

int     get_name(struct s_city *city, int depth, int n, char **name)
{
    int     level;
    if (!city->next)
        return(depth - n);
    level = get_name(city->next, depth + 1, n, name);
    if (level == depth)
        *name = city->name;
    return (level);
}

char        *NthLastCity(struct s_city *city, int n)
{
    char    *name = NULL;

    get_name(city, 0, n, &name);
    return (name);
}