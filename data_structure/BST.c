#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;
void push(int push_num, node** root)  //삽입
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
		if (push_num > tra->data)  // 오른쪽 클때
		{
			if (tra->right == NULL)  //비어있음
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
		else // 같을 때
		{
			printf("중복된 값\n");
			return;
		}
	}
}
void del(int del_data, node** root)  // 삭제
{
	node* tra = *root;
	node* del_node = NULL; // 삭제할 노드
	node* back_node = NULL; // 삭제할 노드의 이전 노드
	while (tra)
	{
		if (tra->data == del_data)  // 현재 노드가 삭제 노드랑 같을 떄
		{ 
			del_node = tra;
			break;
		}
		else if (del_data > tra->data)  // 현재 노드의 데이터 보다 삭제할 노드의 데이터가 더 클 떄
		{
			back_node = tra;
			tra = tra->right;
		}
		else if(del_data < tra->data) // 더 작을 떄
		{
			back_node = tra;
			tra = tra->left;
		}
	}
	if (del_node == NULL)
	{
		printf("값이 없음\n");
		return;
	}
	if (del_node->left == NULL && del_node->right == NULL)  // 삭제할 노드의 왼쪽과 오른쪽이 비어있을 때 -> 리프노드
	{
		if (back_node->left == del_node) // 이전 노드의 왼쪽 노드 삭제 할 노드 일떄
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
	else if (del_node->left == NULL || del_node->right == NULL)  // 삭제할 노드의 왼쪽 혹은 오른쪽이 비었을 때
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
		else if (del_node->left != NULL) // 오른쪽이 비었을 때
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
		else if (del_node->right != NULL)  // 왼쪽이 비었을 때
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
	else  // 삭제할 노드의 왼쪽과 오른쪽의 데이터가 들어있을 때
	{
		node* max_node = del_node->left;
		node* max_back_node = del_node;
		while (max_node->right != NULL)  // 가장 큰 값 찾기
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
node* search(int sr, node* root)  // 탐색
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
void traverse(node* root) // 전위 순회  루왼오
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
		printf("값을 찾을 수 없음\n");
	}
	printf("%d %d", root->left->data, root->left->right->data);
}