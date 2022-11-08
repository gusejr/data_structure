#include <stdio.h>
#include <string.h>

char stack[51];
int top = -1;

void push(char parenthesis)
{
	if (top != 50)
	{
		stack[++top] = parenthesis;
	}
}
char pop()
{
	if (top != -1)
	{
		return stack[top--];
	}
}
int main()
{
	int times = 0;
	scanf_s("%d", &times);
	for (int i = 0; i < times; i++)
	{
		top = -1;
		int parenthesis_count = 0, flag = 1;
		char parenthesis[51] = { 0 };
		scanf_s("%s", &parenthesis, sizeof(parenthesis));
		for (int j = 0; j < strlen(parenthesis); j++)
		{
			if ('(' == parenthesis[j])
			{
				push(parenthesis[j]);
			}
			else
			{
				if (top == -1)
				{
					printf("NO\n");
					flag = 0;
					break;
				}
				else
				{
					if (stack[top] == '(')
					{
						pop();
					}
				}
			}
		}
		if (top > -1)
		{
			printf("NO\n");
			continue;
		}
		if (flag == 1)
		{
			printf("YES\n");
		}
	}
}