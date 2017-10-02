#include "header.h"
#include <string.h>
#include <stdio.h>

int searchPrice(struct s_art **arts, int n, char *name)
{
    struct s_art **art_half = NULL;
    if (n <= 0)
        return (-1);
    if (strcmp((*arts)->name, name) == 0)
        return ((*arts)->price);
    art_half = arts + n/2;
    if (strcmp(name, (*art_half)->name) == 0)
        return (*art_half)->price;
    if (strcmp(name, (*art_half)->name) > 0){
        // printf ("here:   %s----%d\n",(*art_half)->name, n);
        return (searchPrice(art_half, n/2, name));
    }
    else if (strcmp(name, (*art_half)->name) < 0)
    {
        // printf ("here:   %s----%d\n",(*art_half)->name, n);
        return (searchPrice(arts, n/2, name));
    }
    return (-1);
}