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

typedef struct node
{
	char data;
	struct node* lchild;
	struct node* rchild;
}node;
void init()
{

}
void push_F(char center_word, char father_word, node** root)
{
	node* tra = *root;
	node* father_node = (node*)malloc(sizeof(node));
	father_node->lchild = NULL;
	father_node->rchild = NULL;
	father_node->data = father_word;
	//int tag = 0;
	if (*root == NULL)
	{
		node* center_node = (node*)malloc(sizeof(node));
		center_node->data = center_word;
		center_node->lchild = father_node;
		center_node->rchild = NULL;
		*root = center_node;

	}
	while (tra !=NULL)
	{
		if (tra->data == center_word)
		{
			tra->lchild = father_node;
			return;
		}
		else if (tra->lchild->data == center_word)
		{
			tra = tra->lchild;
		}
		else if (tra->rchild->data == center_word)
		{
			tra = tra->rchild->data;
		}
	}
	
}
void push_M(char center_word, char mother_word, node** root)
{
	node* tra = *root;
	node* mother_node = (node*)malloc(sizeof(node));
	mother_node->lchild = NULL;
	mother_node->rchild = NULL;
	mother_node->data = mother_word;
	if (*root == NULL)
	{
		node* center_node = (node*)malloc(sizeof(node));
		center_node->data = center_word;
		center_node->rchild = mother_node;
		center_node->lchild = NULL;
		*root = center_node;
	}
	while (tra != NULL)
	{
		if (tra->data == center_word)
		{
			tra->rchild = mother_node;
			return;
		}
		else if (tra->lchild->data == center_word)
		{
			tra = tra->lchild;
		}
		else if (tra->rchild->data == center_word)
		{
			tra = tra->rchild->data;
		}
	}
}
void search()
{

}
void traverse() // ���� ��ȸ
{

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
	}
}