// < ���� >
// 1. == ���� ==
/*xFy, xMy ���·� family tree�� �Է� �޴´�.
y�� ���� / �����ʿ� ������ �����Ѵ�.
Ʈ���� �����.
����Ѵ�. */

// == ���� ��ȸ ==
// < ������ �ʿ��� �͵� >
// push, search, traverse
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 30
node* circular_queue[MAX_SIZE];
int front = 0;
int rear = 0;
typedef struct node
{
	char data;
	struct node* lchild;
	struct node* rchild;
}node;
node* init(char new_word, node* left_node, node* right_node)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->lchild = left_node;
	newnode->rchild = right_node;
	newnode->data = new_word;
	return newnode;
}
int is_empty() // ť�� ����ִ��� Ȯ��
{
	if (rear == front)
	{
		return 1;
	}
	return 0;
}
node* pop()
{
	if (!is_empty())
	{
		front = (front + 1) % MAX_SIZE;
		return circular_queue[front];
	}
}
void push_queue(node* data)
{
	
	rear = (rear + 1) % MAX_SIZE;
	circular_queue[rear] = data;
}
void push_F(char center_word, char father_word, node** root)
{
	node* father_node = init(father_word, NULL, NULL);
	if (*root == NULL)  // Ʈ���� ������� ��
	{
		node* center_node = init(center_word, father_node, NULL);
		*root = center_node;
		return;
	}
	push_queue(*root);
	while (!is_empty()) // ��Ʈ�� ������� ����
	{
		node* pop_node = pop();
		if (pop_node->data == center_word)
		{
			pop_node->lchild = father_node;
			rear = front = 0;
			return;
		}
		if (pop_node->lchild != NULL)
		{
			push_queue(pop_node->lchild);
		}
		if (pop_node->rchild != NULL)
		{
			push_queue(pop_node->rchild);
		}
	}
	// ť�� �������
	// A ����
	node* change_root = init(center_word, *root, NULL);
	*root = change_root;
}
void push_M(char center_word, char mother_word, node** root)
{
	node* tra = *root;
	node* mother_node = init(mother_word, NULL, NULL);
	if (*root == NULL)
	{
		node* center_node = init(center_word, NULL, mother_node);
		*root = center_node;
		return;
	}
	push_queue(*root);
	while (!is_empty()) // ��Ʈ�� ������� ����
	{
		node* pop_node = pop();
		if (pop_node->data == center_word)
		{
			pop_node->rchild = mother_node;
			rear = front = 0;
			return;
		}
		if (pop_node->lchild != NULL)
		{
			push_queue(pop_node->lchild);
		}
		if (pop_node->rchild != NULL)
		{
			push_queue(pop_node->rchild);
		}
	}
	// ť�� �������
	// A ����
	node* change_root = init(center_word, NULL, *root);
	*root = change_root;
}
void traverse(node* root) // ���� ��ȸ
{
	push_queue(root);
	while (!is_empty()) // ��Ʈ�� ������� ����
	{
		node* pop_node = pop();
		if (pop_node->lchild != NULL)
		{
			push_queue(pop_node->lchild);
		}
		if (pop_node->rchild != NULL)
		{
			push_queue(pop_node->rchild);
		}
		printf("%c", pop_node->data);
	}
}
int input_check(const char* data)
{

	if (strcmp(data, "\0") == 0)
	{
		return 0;
	}
	return 1; 
}
void end(const char* data)
{
	if (strcmp(data, "$$$") == 0)
	{
		exit(0);
	}
}
int main()
{
	node* root = NULL;
	char data[4];
	while (1)
	{
		printf(">>");
		gets_s(data, sizeof(data));
		if (!input_check(data))
		{
			continue;
		}
		end(data);
		if (data[1] == 'F')
		{
			char left_alphabet = data[0];
			char right_alphabet = data[2];
			push_F(left_alphabet, right_alphabet, &root);
		}
		else if (data[1] == 'M')
		{
			char left_alphabet = data[0];
			char right_alphabet = data[2];
			push_M(left_alphabet, right_alphabet, &root);
		}
		traverse();
	}
}