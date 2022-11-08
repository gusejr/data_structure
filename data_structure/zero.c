//스택 : 0 들어오면 pop 함
//0 이 아니면 노드 추가 
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
int stack[MAX_SIZE];
int top = -1;


void push(int num)
{
	if (top != MAX_SIZE - 1)
	{
		stack[++top] = num;
	}
}
int pop()
{
	if (top != -1)
	{
		return stack[top--];
	}
}
int main()
{
	int time, number, sum = 0;
	scanf_s("%d", &time);
	for (int i = 0; i < time; i++)
	{
		scanf_s("%d", &number);
		if (number == 0)
		{
			pop();
		}
		else
		{
			push(number);
		}
	}
	for (int i = 0; i <= top; i++)
	{
		sum = sum + stack[i];
	}
	printf("%d", sum);
 }