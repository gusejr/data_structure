#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char order[10];
	scanf_s("%s", &order, sizeof(order));
	printf("%s", order);
}