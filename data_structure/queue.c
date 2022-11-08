#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100000 
int queue[MAX_SIZE];
int rear = -1;

void push(int push_num)
{
	if (rear != MAX_SIZE - 1)
	{
		queue[++rear] = push_num;
	}
}
int pop()
{
	int temp;
	temp = queue[0];
	for (int i = 0; i < rear; i++)
	{
		queue[i] = queue[i + 1];
	}
	rear--;
	return temp;
}

int main()
{
	int times = 0, push_num = 0;
	scanf_s("%d", &times);
	for (int i = 0; i < times; i++)
	{
		char order[7] = { 0 };
		scanf_s("%s", &order, sizeof(order));
		if (strcmp("push", order) == 0)
		{
			scanf_s("%d", &push_num);
			push(push_num);
		}
		else if (strcmp("pop", order) == 0)
		{
			if (rear == -1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", pop());
			}
		}
		else if (strcmp("size", order) == 0)
		{
			printf("%d\n", rear + 1);
		}
		else if (strcmp("empty", order) == 0)
		{
			if (rear != -1)
			{
				printf("0\n");
			}
			else
			{
				printf("1\n");
			}
		}
		else if (strcmp("front", order) == 0)
		{
			if (rear == -1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", queue[0]);
			}
		}
		else if (strcmp("back", order) == 0)
		{
			if (rear == -1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", queue[rear]);
			}
		}
	}
}
