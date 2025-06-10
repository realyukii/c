/*
* implement queue with linked-list.
* 
* queue core operation:
* - enqueue
* - dequeue
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct list {
	int some_data;
	struct list *next;
};

struct queue {
	struct list *head;
	struct list *tail;
};

void enqueue(struct queue *q, struct list *l)
{
	if (!q->head)
		q->tail = q->head = l;
	else {
		q->tail->next = l;
		q->tail = l;
	}
}

void dequeue(struct queue *q)
{
	struct list *l = q->head;
	if (!l)
		return;
	
	q->head = l->next;
	if (!q->head)
		q->tail = NULL;
	
	free(l);
}

struct list *allocate_list(void)
{
	struct list *list = calloc(1, sizeof(struct list));
	return list;
}

int main(void)
{
	struct queue q;
	int data;
	
	puts("1. enqueue");
	puts("2. dequeue");
	puts("3. front");
	puts("4. rear");
	while (true)
	{
		int choice;
		printf("Enter your choice: ");
		fflush(stdout);
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			struct list *l = allocate_list();
			printf("input some number: ");
			fflush(stdout);
			scanf("%d", &data);
			l->some_data = data;
			if (l)
				enqueue(&q, l);
			break;
		case 2:
			dequeue(&q);
			break;
		case 3:
			if (q.head)
				printf("%d\n", q.head->some_data);
			else
				puts("queue is empty");
			break;
		case 4:
			if (q.tail)
				printf("%d\n", q.tail->some_data);
			else
				puts("queue is empty");
			break;
		
		default:
			printf("invalid choice\n");
			break;
		}
	}
	
	return 0;
}