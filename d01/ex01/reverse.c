#include "header.h"
#include <stdio.h>

void        printReverse(struct s_node *lst)
{
    static int flag = 0;
    if (!lst)
        return ;
    flag++;
    printReverse(lst->next);
    flag--;
    printf("%s", lst->word);
    printf("%c", (flag == 0) ? '\n': ' ');
}