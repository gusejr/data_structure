#include <stdio.h>
#define MAX_SIZE 500001
int front = 0;
int rear = 0;
int queue[MAX_SIZE];

void push(int cards)
{
	if ((rear + 1) % MAX_SIZE != front)
	{
		rear = (rear + 1) % MAX_SIZE;
		queue[rear] = cards;
	}
}
int pop()
{
	if (rear != front)
	{
		front = (front + 1) % MAX_SIZE;
		return queue[front];
	}
}
int main()
{
	int deck, save;
	scanf_s("%d", &deck);
	for (int i = 1; i <= deck; i++)
	{
		push(i);
	}
	for (int i = 0; i < deck - 1; i++)
	{
		pop();
		push(pop());
	}
	printf("%d", pop());
}