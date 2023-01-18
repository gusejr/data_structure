#include <stdio.h>
int com_arr[101][101] = { 0 };
int visit[101] = { 0 };
int virus = 0;

void DFS(int start, int count)
{
	visit[start] = 1;
	for (int i = 1; i <= count; i++)
	{
		if (com_arr[start][i] == 1 && visit[i] == 0)
		{
			virus++;
			DFS(i, count);
		}
	}
}
int main()
{
	int computer, computer_num1, computer_num2, edge;
	scanf_s("%d %d", &computer, &edge);
	for (int i = 0; i < edge; i++)
	{
		scanf_s("%d %d", &computer_num1, &computer_num2);
		com_arr[computer_num1][computer_num2] = 1;
		com_arr[computer_num2][computer_num1] = 1;
	}
	DFS(1, computer);
	printf("%d", virus);
}