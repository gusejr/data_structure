#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 1001
/*1. �迭 ���� Ȯ��(����)
2. ���� ���� �� ã��
3. �Է� Ƚ�� ��ŭ ���ϱ�
4. �ش� ī�� 2 �忡 ���� �� �����*/
typedef struct Heap
{
	long long card_heap[MAX_SIZE];
	int heap_size;
}Heap; 
void push_heap(long long card_number, Heap* cards)
{
	if(cards->heap_size == 0)
	{
		cards->card_heap[1] = card_number;
		(cards->heap_size)++;
		return;
	}
	int size = ++(cards->heap_size);
	while (size != 1)
	{
		if (card_number <= cards->card_heap[size / 2])
		{
			cards->card_heap[size] = cards->card_heap[size / 2];
			cards->card_heap[size / 2] = card_number;
			size = size / 2;
		}
		else
		{
			cards->card_heap[size] = card_number;
			break;
		}
	}
}
long long del_heap(Heap* cards)
{
	long long min = cards->card_heap[1];
	int size = 1;
	while (size * 2 <cards->heap_size || size * 2 + 1 < cards->heap_size)
	{
		if (cards->card_heap[size * 2] <= cards->card_heap[size * 2 + 1])
		{
			cards->card_heap[size] = cards->card_heap[size * 2];
			size = size * 2;
		}
		else
		{
			cards->card_heap[size] = cards->card_heap[size * 2 + 1];
			size = size * 2 + 1;
		}
	}
	--(cards->heap_size);
	return min;
}
int main()
{
	// n = ī�� ��1000, m = ���� Ƚ �� 15 * n
	Heap cards = { {0LL}, 0 };
	int n, m;
	long long input, sum = 0;
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lld", &input);
		push_heap(input, &cards);
		//printf("%d", cards->cards[i]);
	}
	for (int i = 0; i < m; i++)
	{
		long long min1 = del_heap(&cards);
		long long min2 = del_heap(&cards);
		long long new_number = min1 + min2;
		push_heap(new_number, &cards);
		push_heap(new_number, &cards);
	}
	for (int i = 1; i <= n; i++)
	{
		sum = sum + cards.card_heap[i];
		printf("%lld\n", cards.card_heap[i]);
	}
	printf("%lld", sum);
}