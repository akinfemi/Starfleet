#include <stdlib.h>

struct s_item *create_item (char *message) {
	struct s_item *item = malloc(sizeof(*item));
	item->message = message;
	item->next = NULL;
	return (item);
}

struct	s_queue *queueInit(void)
{
		struct s_queue *new_queue = malloc(sizeof(*new_queue));
		if (!new_queue)
			return (NULL);
		new_queue->first = NULL;
		new_queue->last = NULL;
		return (new_queue);
}

void	enqueue(struct s_queue *queue, char *message)
{
		struct s_item *item = NULL;
		struct s_item *temp = NULL;
		if (!queue || !message)
			return ;
		item = create_item(message);
		if (!queue->first)
			queue->first = item;
		else
		{
			temp = queue->first;
			while(temp->next)
				temp = temp->next;
			temp->next = item;
		}
		queue->last = item;
}

char	*dequeue(struct s_queue *queue)
{
		struct s_item	*temp = NULL;
		char	*val = NULL;
		if (!queue)
			return (val);
		if (queue->first)
		{
			temp = queue->first;
			val = temp->message;
			queue->first = temp->next;
		}
		if (!queue->first)
			queue->last = NULL;
		return (val);
}

char	*peek(struct s_queue *queue)
{

		struct s_item	*temp = NULL;
		char	*val = NULL;
		if (!queue)
			return (val);
		if (queue->first)
		{
			temp = queue->first;
			val = temp->message;
		}
		return (val);
}

int		isEmpty(struct s_queue *queue)
{
	if (!queue)
		return (1);
	if (!(queue->first))
		return (1);
	return (0);
}
