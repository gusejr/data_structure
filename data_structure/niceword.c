#include <stdio.h>
#include <string.h>

char stack[1000001];
int top = -1;

void push(char word)
{
	if (top != 1000001)
	{
		stack[++top] = word;
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
	int times = 0, count_nice_word = 0;
	scanf_s("%d", &times);
	for (int i = 0; i < times; i++)
	{
		top = -1;
		char word[1000001] = { 0 };
		scanf_s("%s", &word, sizeof(word));
		if (strlen(word) % 2 == 1) // È¦¼ö ÀÏ ¶§ ¾ÈµÊ
		{
			continue;
		}
		for (int j = 0; j < strlen(word); j++)
		{
			if (top == -1 || stack[top] != word[j])
			{
				push(word[j]);
			}
			else if (stack[top] == word[j])
			{
				pop();
			}
		}
		if (top == -1)
		{
			count_nice_word++;
		}
	}
	printf("%d", count_nice_word);
}