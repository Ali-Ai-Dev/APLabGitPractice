#pragma warning (disable : 4996)
#include <Windows.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 200
int arr[MAX_SIZE];

typedef struct alfa * alfaptr;

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
	node->next = nullptr;
	if (!front)
		front = rear = node;
	else {
		rear->next = node;
		rear = node;
	}
}

void pop()
{
	alfaptr temp;
	if (!front)
		printf("ERROR1");
	else
	{
		temp = front;
		front = front->next;
		free(temp);
	}
}
void search(int x)
{
	alfaptr temp = front;
	int counter = 1;
	while (temp)
	{
		if (temp->x == x)
		{
			printf("%d", counter);
			return;
		}
		counter++;
		temp = temp->next;
	}
	printf("ERROR2");
	Sleep(1300);
}

void rpop() {
	alfaptr temp = front;
	while (temp->next->next)
		temp = temp->next;
	free(rear);
	rear = temp;
	rear->next = nullptr;
}

void set()
{
	alfaptr temp = front;
	for (int i = 0; i < MAX_SIZE && temp; i++, temp = temp->next)
		arr[i] = temp->x;
}

int size()
{
	alfaptr temp = front;
	int count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void show()
{
	set();
	if (front)
	{
		for (int i = 0; i < MAX_SIZE && arr[i] != 0; i++)
			printf("%d ", arr[i]);
	}
	else
	{
		printf("ERROR3");
	
	}
}

int average()
{

	alfaptr temp = front;
	int sum = 0, count = 0;
	while (temp) {
		sum += temp->x;
		count++;
		temp = temp->next;
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