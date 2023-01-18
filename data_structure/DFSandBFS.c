#include <stdio.h>

// < 조건 >
// 정점 번호 1부터 N까지
// 1 <= N <= 1000  1 <= M <= 10000
// 정점 번호가 작은거 부터 방문
// 양방향 그래프

// 해야 할 것
// BFS
// 큐
int visit[1001] = { 0 };
int matrix[1001][1001] = { 0 };
int queue[1001] = { 0 };
int front = -1;
int rear = -1;
void enqueue(int start)
{
	if (rear == -1)
	{
		queue[0] = start;
		rear++;
	}
	else
	{
		queue[++rear] = start;
	}
}
int dequeue()
{
	return queue[++front];
}
int is_empty()
{
	if (front >= rear)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int start, N, M;
	int current;
	scanf_s("%d %d %d", &N, &M, &start);
	for (int i = 0; i < M; i++)
	{
		int N1, N2;
		scanf_s("%d %d", &N1, &N2);
		matrix[N1][N2] = 1;
		matrix[N2][N1] = 1;
	}
	enqueue(start);
	visit[start] = 1;
	while (!is_empty())
	{
		current = dequeue();
		printf("%d\n", current);
		for (int i = 1; i <= N; i++)
		{
			if (matrix[current][i] == 1 && visit[i] == 0)
			{
				visit[i] = 1;
				enqueue(i);
			}
		}
	}
}