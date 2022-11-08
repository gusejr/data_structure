#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[10];
	Node* next;
}Node;
void add_node(Node* back_node, const char* data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	Node* temp = back_node->next;
	back_node->next = newnode;
	newnode->next = temp;
	strcpy_s(newnode->name, sizeof(newnode->name), data);
}
void del_node(Node* back_node)
{
	Node* temp = back_node->next;
	back_node->next = back_node->next->next;
	free(temp);
}
int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	add_node(head, "hyeondeok");
	add_node(head->next, "eunsol");
	printf("%s ", head->next->name);
	printf("%s", head->next->next->name);
}