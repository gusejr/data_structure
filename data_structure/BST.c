#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;
void push(int push_num, node** root)  //����
{
	node* tra = *root;
	node* newnode = (node*)malloc(sizeof(node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = push_num;
	if (*root == NULL)
	{
		*root = newnode;
	}
	while (tra !=NULL)
	{
		if (push_num > tra->data)  // ������ Ŭ��
		{
			if (tra->right == NULL)  //�������
			{
				tra->right = newnode;
				return;
			}
			else
			{
				tra = tra->right;
			}
		}
		else if (push_num < tra->data)
		{
			if (tra->left == NULL)
			{
				tra->left = newnode;
				return;
			}
			else
			{
				tra = tra->left;
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
			tra = tra->right;
		}
		else if(del_data < tra->data) // �� ���� ��
		{
			back_node = tra;
			tra = tra->left;
		}
	}
	if (del_node == NULL)
	{
		printf("���� ����\n");
		return;
	}
	if (del_node->left == NULL && del_node->right == NULL)  // ������ ����� ���ʰ� �������� ������� �� -> �������
	{
		if (back_node->left == del_node) // ���� ����� ���� ��� ���� �� ��� �ϋ�
		{
			back_node->left = NULL;
		}
		else if (back_node->right == del_node)
		{
			back_node->right = NULL;
		}
		else if (back_node == NULL)
		{
			*root = NULL;
		}
	}
	else if (del_node->left == NULL || del_node->right == NULL)  // ������ ����� ���� Ȥ�� �������� ����� ��
	{
		if (back_node == NULL)
		{
			if (del_node->left != NULL)
			{
				*root = del_node->left;
			}
			else
			{
				*root = del_node->right;
			}
		}
		else if (del_node->left != NULL) // �������� ����� ��
		{
			if (back_node->left == del_node)
			{
				back_node->left = del_node->left;
			}
			else
			{
				back_node->right = del_node->left;
			}
		}
		else if (del_node->right != NULL)  // ������ ����� ��
		{
			if (back_node->right == del_node)
			{
				back_node->right = del_node->right;
			}
			else
			{
				back_node->left = del_node->right;
			}
		}
	}
	else  // ������ ����� ���ʰ� �������� �����Ͱ� ������� ��
	{
		node* max_node = del_node->left;
		node* max_back_node = del_node;
		while (max_node->right != NULL)  // ���� ū �� ã��
		{
			max_back_node = max_node;
			max_node = max_node->right;
		}
		if (back_node == NULL)
		{
			*root = max_node;
		}
		else if (back_node->left == del_node)
		{
			back_node->left = max_node;
		}
		else
		{
			back_node->right = max_node;
		}
		if (max_back_node == del_node)
		{
			max_node->right = del_node->right;
		}
		else
		{
			max_back_node->right = max_node->left;
			max_node->left = del_node->left;
			max_node->right = del_node->right;
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
			search_node = search_node->left;
		}
		else if (search_node->data < sr)
		{
			search_node = search_node->right;
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
	printf("%d %d", root->left->data, root->left->right->data);
}