#include <stdio.h>
#include <string.h>

int main()
{
	int times = 0;
	scanf_s("%d", &times);
	for (int i = 0; i < times; i++)
	{
		int parenthesis_count = 0;
		char parenthesis[51] = { 0 };
		scanf_s("%s", &parenthesis, sizeof(parenthesis));
		for (int j = 0; j < strlen(parenthesis); j++)
		{
			if ('(' == parenthesis[j])
			{
				parenthesis_count++;
			}
			else
			{
				parenthesis_count--;
				if (parenthesis_count == -1)
				{
					printf("NO\n");
					break;
				}
			}
		}
		if (parenthesis_count > 0)
		{
			printf("NO\n");
		}
		else if(parenthesis_count == 0)
		{
			printf("YES\n");
		}
	}
}