#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	struct s_queue *q = queueInit();
	enqueue(q, "Houston,");
	enqueue(q, "we ");
	enqueue(q, "have a problem...");
	printf("First message : %s\n", peek(q));
	dequeue(q);
	printf("First message : %s\n", peek(q));
	dequeue(q);
	dequeue(q);
	printf("Is empty? : %d\n", isEmpty(q));
	enqueue(q, "Hello, ");
	enqueue(q, "how ");
	printf("First message : %s\n", peek(q));
	enqueue(q, "are ");
	enqueue(q, "you?");
	printf("First message : %s\n", peek(q));
	printf("Is empty? : %d\n", isEmpty(q));
	return (0);
}



// Function used for the test
// Don't go further :)

