#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200
int arr[MAX_SIZE];

typedef struct alfa *alfaptr;

struct alfa
{
	int x;
	alfaptr next;
};
alfaptr rear = NULL, front = NULL;
void push(int x)
{
	alfaptr node;
	node = (alfaptr)malloc(sizeof(struct alfa));
	node->x = x;
	node->next = NULL;
	if (!front)
	{
		front = node;
		rear = node;
	}
	else
	{
		rear->next = node;
		rear = node;
		node->next = NULL;
	}
}

void pop()
{
	alfaptr node;
	if (!front)
		printf("ERROR1\n");
	else if (front == rear)
	{
		free(front);
		rear = NULL;
		front = NULL;
	}
	else
	{
		node = front->next;
		free(front);
		front = node;
	}
}
void search(int x)
{
	alfaptr node = front;
	int counter = 0;
	while (node)
	{
		if (node->x == x)
			counter++;
		node = node->next;
	}
	if (counter == 0)
	{
		printf("ERROR2\n");
		return;
	}
	printf("%d\n", counter);
}

void rpop()
{ // pop last element
	alfaptr node = front;
	if (node == rear)
	{
		pop();
		return;
	}
	while (node)
	{
		if (node->next == rear)
		{
			break;
		}
		node = node->next;
	}
	free(rear);
	rear = node;
	rear->next = NULL;
}

void set()
{
	alfaptr node = front;
	for (int i = 0; i < MAX_SIZE && node; i++, node = node->next)
		arr[i] = node->x;
}

int size()
{
	alfaptr node = front;
	int count = 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	return count;
}

void show()
{
	if (front)
	{
		for (int i = 0; i < size(); i++)
			printf("%d ", arr[i]);
	}
	else
	{
		printf("ERROR3");
	}
}

int average()
{

	alfaptr node = front;
	int sum = 0, count = 0;
	while (node)
	{
		sum += node->x;
		count++;
		node = node->next;
	}
	if (count == 0)
		return 0;
	return sum / count;
}

int main()
{
	int cmd;
	int x;
	while (true)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1: // push
			scanf("%d", &x);
			push(x);
			break;
		case 2: // pop
			pop();
			break;
		case 3: // rpop
			rpop();
			break;
		case 4: // search
			scanf("%d", &x);
			search(x);
			break;
		case 5: // set
			set();
			break;
		case 6: // show
			show();
			printf("\n");
			break;
		case 7: // size
			printf("%d\n", size());
			break;
		case 8:
			printf("%d\n", average());
			break;
		case 10:
			exit(0);
			break;
		default:
			break;
		}
	}
}