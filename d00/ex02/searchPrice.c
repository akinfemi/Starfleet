#include "header.h"
#include <string.h>
#include <stdio.h>

int searchPrice(struct s_art **arts, int n, char *name)
{
    struct s_art **art_half = NULL;
    if (n <= 0)
        return (-1);
    art_half = arts + n/2;
    if (strcmp(name, (*art_half)->name) > 0)
        return (searchPrice(art_half, n/2 + 1, name));
    else if (strcmp(name, (*art_half)->name) < 0)
        return (searchPrice(arts, n/2 - 1, name));
    return (*art_half)->price;
}
