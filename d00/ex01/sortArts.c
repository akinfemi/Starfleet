#include <string.h>
#include "header.h"
#include <stdlib.h>
#include <stdio.h>

static int comp_func(const void *arts_a, const void *arts_b)
{
    struct s_art **a = (struct s_art **) arts_a;
    struct s_art **b = (struct s_art **) arts_b;
    return strcmp((*a)->name, (*b)->name);
}

void        sortArts(struct s_art **arts)
{
    int     size = 0;

    if (!arts || !*arts)
        return ;
    while (arts[size])
        size++;
    mergesort(arts, size, sizeof(struct s_art *), comp_func);
}
