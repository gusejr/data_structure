#include <stdio.h>

// < ���� >
// ���� ��ȣ 1���� N����
// 1 <= N <= 1000  1 <= M <= 10000
// ���� ��ȣ�� ������ ���� �湮
// ����� �׷���

// �ؾ� �� ��
// BFS
// ť
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