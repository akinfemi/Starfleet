#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static struct s_item *new_item(char *key, int value)
{
	struct s_item 	*item;

	item = (struct s_item *)malloc(sizeof(struct s_item));
	item->value = value;
	item->key = strdup(key);
	item->next = NULL;
	return (item);
}

size_t		hash(char *key)
{
	size_t	res;

	res = 0;
	while(key && *key)
	{
		res += *key * 31;
		key++;
	}
	return (res);
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict	*dict;
   
	dict = (struct s_dict *)malloc(sizeof(struct s_dict));
	dict->capacity = capacity;
	dict->items = (struct s_item **)calloc(capacity, sizeof(struct s_item *));
	return (dict);
}

int		dictInsert(struct s_dict *dict, char *key, int value)
{
	size_t			index;
	struct s_item 	*head;

	if (!dict)
		return (-1);
	index = hash(key) % dict->capacity;
	head = dict->items[index];
	if(head == 0)
	{
		head = new_item(key, value);
		dict->items[index] = head;
	}
	else
	{
		while (head->next)
			head = head->next;
		head->next = new_item(key, value);
	}
	return (1);
}

int     dictSearch(struct s_dict *dict, char *key)
{
	size_t			index;
	struct s_item	*item;

	if (!dict)
		return (0);
	index = hash(key) % dict->capacity;
	item = dict->items[index];
	if (!item)
		return (0);
	if (strcmp(item->key, key) == 0)
		return (item->value);
	else
	{
		while (item)
		{
			if (strcmp(item->key, key) == 0)
				return (item->value);
			item = item->next;
		}
	}
	return (0);
}
char        *compress(char *book, struct s_dict *dict)
{
    char    *substring;
    char    *space;
    int     word_len = 0;
    int     res = 0;
    char    n_print[21] = "ABCDEFGHIJKLMNOPQRST";

    while ((space = strchr(book, ' ')))
    {
        word_len = space - book;
        substring = strndup(book, word_len);
        res = dictSearch(dict, substring);
        if (res == 0)
            printf("%s ", substring);
        else
        {
            if (res > 0 && res <= 19)
                printf("@^%c ", n_print[res]);
            else
                printf("@%c ", res);
        }
        book = book + word_len + 1;
        free(substring);
    }
    return (0);
}