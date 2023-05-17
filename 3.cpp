#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define MAX_SIZE 200
int arr[MAX_SIZE];

typedef struct alfa* alfaptr;

struct alfa {
	long long x;
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
		front = node;
	else {
		if (!rear) // بررسی برای rear برابر با NULL
			front->next = node;
		else
			rear->next = node;
		rear = node;
	}
}

void pop()
{
	alfaptr node;
	if (!front)
		printf("ERROR1");
	else
	{
		node = front->next;
		front = node;
	}
}
void search(int x)
{
	alfaptr node = front;
	int counter = 0, found = 0;
	while (node) {
		if (node->x == x) {
			found = 1;
			break;
		}
		node = node->next;
		counter++;
	}
	if (found)
		printf("%d", counter);
	else
		printf("ERROR2");
}

void rpop() {//pop last element
	if (!front) {
		printf("ERROR4");
		return;
	}
	if (front == rear) {
		free(front);
		front = rear = NULL;
		return;
	}
	alfaptr node = front;
	while (node->next != rear)
		node = node->next;
	free(rear);
	rear = node;
	rear->next = NULL;
}

void set()
{
	if (!front) {
		printf("ERROR5");
		return;
	}
	alfaptr node = front;
	int i = 0;
	while (node) {
		arr[i] = node->x;
		node = node->next;
		i++;
	}
}

int size()
{
	alfaptr node = front;
	int count = 0;
	while (node) {
		count++;
		node = node->next;
	}
	return count;
}

void show()
{
	if (!front) {
		printf("ERROR6");
		return;
	}
	for (int i = 0; i < size(); i++)
		printf("%d ", arr[i]);
}

int average()
{

	alfaptr node = front;
	int sum = 0, count=0;
	while (node) {
		sum += node->x;
		count++;
		node = node->next;
	}
	return sum / count;
}

void main()
{
	int cmd;
	long long int x;
	while (true)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1://push
			scanf("%lld", &x);
			push(x);
			break;
		case 2://pop
			pop();
			break;
		case 3://rpop
			rpop();
			break;
		case 4://search
			scanf("%lld", &x);
			search(x);
			break;
		case 5://set
			set();
			break;
		case 6://show
			show();
			break;
		case 7://size
			printf("%d", size());
			break;
		case 10:
			exit(0);
		}
	}
}