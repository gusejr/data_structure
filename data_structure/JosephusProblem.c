// 2씩 건너뜀 K번째 되는 숫자 제거
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5001
int queue[MAX_SIZE];
int front = 0;
int rear = 0;

void push(int human)
{
	if (front != (rear + 1) % MAX_SIZE)
	{
		rear = (rear + 1) % MAX_SIZE;
		queue[rear] = human;
	}
}
int pop()
{
	if (rear != front)
	{
		front = (front + 1) % MAX_SIZE;
		return queue[front];
	}
	else
	{
		return -1;
	}
}
int main()
{
	int human, k, bowl;
	scanf_s("%d %d", &human, &k);
	int josephus_problem[MAX_SIZE] = { 0 };
	for (int i = 1; i <= human; i++)
	{
		push(i);
	} 
	for (int i = 0; i < human; i++)
	{
		for (int j = 0; j < k; j++)
		{
			bowl = pop();
			if (bowl == -1)
			{
				break;
			}
			if (j == k - 1)
			{
				josephus_problem[i] = bowl;
			}
			else
			{
				push(bowl);
			}
		}
	}
	printf("<");
	for (int i = 0; i < human; i++)
	{
		printf("%d", josephus_problem[i]);
		if (i != human - 1)
		{
			printf(", ");
		}
	}
	printf(">");
}
