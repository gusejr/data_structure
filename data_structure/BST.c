#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
}node;
void push(int push_num, node** root)  //����
{
	node* tra = *root;
	node* newnode = (node*)malloc(sizeof(node));
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	newnode->data = push_num;
	if (*root == NULL)
	{
		*root = newnode;
	}
	while (tra !=NULL)
	{
		if (push_num > tra->data)  // ������ Ŭ��
		{
			if (tra->rchild == NULL)  //�������
			{
				tra->rchild = newnode;
				return;
			}
			else
			{
				tra = tra->rchild;
			}
		}
		else if (push_num < tra->data)
		{
			if (tra->lchild == NULL)
			{
				tra->lchild = newnode;
				return;
			}
			else
			{
				tra = tra->lchild;
			}
		}
		else // ���� ��
		{
			printf("�ߺ��� ��\n");
			return;
		}
	}
}
void del(int del_data, node** root)  // ����
{
	node* tra = *root;
	node* del_node = NULL; // ������ ���
	node* back_node = NULL; // ������ ����� ���� ���
	while (tra)
	{
		if (tra->data == del_data)  // ���� ��尡 ���� ���� ���� ��
		{ 
			del_node = tra;
			break;
		}
		else if (del_data > tra->data)  // ���� ����� ������ ���� ������ ����� �����Ͱ� �� Ŭ ��
		{
			back_node = tra;
			tra = tra->rchild;
		}
		else if(del_data < tra->data) // �� ���� ��
		{
			back_node = tra;
			tra = tra->lchild;
		}
	}
	if (del_node == NULL)
	{
		printf("���� ����\n");
		return;
	}
	if (del_node->lchild == NULL && del_node->rchild == NULL)  // ������ ����� ���ʰ� �������� ������� �� -> �������
	{
		if (back_node->lchild == del_node) // ���� ����� ���� ��� ���� �� ��� �ϋ�
		{
			back_node->lchild = NULL;
		}
		else if (back_node->rchild == del_node)
		{
			back_node->rchild = NULL;
		}
		else if (back_node == NULL)
		{
			*root = NULL;
		}
	}
	else if (del_node->lchild == NULL || del_node->rchild == NULL)  // ������ ����� ���� Ȥ�� �������� ����� ��
	{
		if (back_node == NULL)
		{
			if (del_node->lchild != NULL)
			{
				*root = del_node->lchild;
			}
			else
			{
				*root = del_node->rchild;
			}
		}
		else if (del_node->lchild != NULL) // �������� ����� ��
		{
			if (back_node->lchild == del_node)
			{
				back_node->lchild = del_node->lchild;
			}
			else
			{
				back_node->rchild = del_node->lchild;
			}
		}
		else if (del_node->rchild != NULL)  // ������ ����� ��
		{
			if (back_node->rchild == del_node)
			{
				back_node->rchild = del_node->rchild;
			}
			else
			{
				back_node->lchild = del_node->rchild;
			}
		}
	}
	else  // ������ ����� ���ʰ� �������� �����Ͱ� ������� ��
	{
		node* max_node = del_node->lchild;
		node* max_back_node = del_node;
		while (max_node->rchild != NULL)  // ���� ū �� ã��
		{
			max_back_node = max_node;
			max_node = max_node->rchild;
		}
		if (back_node == NULL)
		{
			*root = max_node;
		}
		else if (back_node->lchild == del_node)
		{
			back_node->lchild = max_node;
		}
		else
		{
			back_node->rchild = max_node;
		}
		if (max_back_node == del_node)
		{
			max_node->rchild = del_node->rchild;
		}
		else
		{
			max_back_node->rchild = max_node->lchild;
			max_node->lchild = del_node->lchild;
			max_node->rchild = del_node->rchild;
		}
	}
	free(del_node);
}
node* search(int sr, node* root)  // Ž��
{
	node* search_node = root;
	while (search_node)
	{
		if (search_node->data == sr)
		{
			return search_node;
		}
		else if (search_node->data > sr)
		{
			search_node = search_node->lchild;
		}
		else if (search_node->data < sr)
		{
			search_node = search_node->rchild;
		}
	}
	return search_node;
}
void traverse(node* root) // ���� ��ȸ  ��޿�
{
	node* tra = root;
	
}
int main()
{
	// int num;
	node* root = NULL;
	node* find = NULL;
	push(10, &root);
	push(7, &root);
	push(4, &root);
	push(8, &root);
	push(11, &root);
	del(7, &root);
	find = search(7, root);
	if (find == NULL)
	{
		printf("���� ã�� �� ����\n");
	}
	printf("%d %d", root->lchild->data, root->lchild->rchild->data);
}