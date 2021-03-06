#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static struct s_item *new_item(char *key, struct s_art *value)
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

int		dictInsert(struct s_dict *dict, char *key, struct s_art *value)
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

struct s_art	*dictSearch(struct s_dict *dict, char *key)
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

int		searchPrice(struct s_dict *dict, char *name)
{
	struct s_art *result;

	result = dictSearch(dict, name);
	if (!result)
		return (0);
	return (result->price);
}