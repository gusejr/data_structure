#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct students
{
	char id[20];
	char dept[20];
	int year;
	char name[20];
	double height;
	double weight;
	char blood[5];
	struct students* next;
}students;

void print_stud_info(students* tra)
{
	printf("ID : %s\n", tra->id);
	printf("�а� : %s\n", tra->dept);
	printf("���г⵵ : %d\n", tra->year);
	printf("�̸� : %s\n", tra->name);
	printf("Ű : %lf\n", tra->height);
	printf("������ : %lf\n", tra->weight);
	printf("������ : %s\n", tra->blood);
}
void push_stud_info(students* data, students* stud) //�л� ���� �Է� push
{
	data->next = stud->next;
	stud->next = data;
}
void del_stud_info(students* stud, const char* del_id) //�л� ���� ���� ID  
{
	// ������ ����� ���� ��带 ã�ƾ���
	// ID �� ���� ��尡 ������ ���
	students* tra = stud;
	students* prev;
	while (1)
	{
		prev = tra;
		tra = tra->next;
		if (tra == NULL)
		{
			printf("�˻� ����� ã�� �� �����ϴ�\n");
			break;
		}
		if (strcmp(tra->id, del_id) == 0)
		{
			prev->next = tra->next;
			free(tra);
			break;
		}
	}
}
void search_stud_name(students* stud, const char* search_name) //�л� �˻� �̸�
{
	students* tra = stud->next;
	while (1)
	{
		if (tra == NULL)
		{
			printf("�˻� ����� ã�� �� �����ϴ�\n");
			break;
		}
		if (strcmp(tra->name, search_name) == 0)
		{
			print_stud_info(tra);
			break;
		}
		tra = tra->next;
	}
}
void search_stud_id(students* stud, const char* search_id)  // �л� ID�� �˻�
{
	students* tra = stud->next;
	while (1)
	{
		if (tra == NULL)
		{
			printf("�˻� ����� ã�� �� �����ϴ�\n");
			break;
		}
		if (strcmp(tra->id, search_id) == 0)
		{
			print_stud_info(tra);
			break;
		}
		tra = tra->next;
	}
}
void show_stud_info(students* stud) //�л� ���� ��� : ���
{	
	students* tra = stud;
	while (tra->next != NULL)
	{
		tra = tra->next;
		print_stud_info(tra);
	}
}
void end_program() // ���α׷� ����
{
	exit(1);
}

int main()
{
	int option;
	students* stud = (students*)malloc(sizeof(students));
	stud->next = NULL;
	while (1)
	{		
		printf("1. �л� ���� �Է�\n2. �л� ���� ����\n3. �л� �˻�\n4. �л� ���� ���\n5. ���α׷� ����\n");
		scanf_s("%d", &option);
		if (option == 1)
		{
			students* data = (students*)malloc(sizeof(students));
			printf("ID �� �Է��ϼ��� ");
			scanf_s("%s", &data->id, sizeof(data->id));
			printf("dept �� �Է��ϼ��� ");
			scanf_s(" ");
			gets_s(data->dept, sizeof(data->dept));
			printf("year �� �Է��ϼ��� ");
			scanf_s(" %d", &data->year);
			printf("name �� �Է��ϼ��� ");
			scanf_s(" %s", &data->name, sizeof(data->name));
			printf("height �� �Է��ϼ��� ");
			scanf_s("%lf", &data->height);
			printf("weight �� �Է��ϼ��� ");
			scanf_s("%lf", &data->weight);
			printf("blood �� �Է��ϼ��� ");
			scanf_s(" %s", &data->blood, sizeof(data->blood));
			push_stud_info(data, stud);
		}
		else if (option == 2)  // ����
		{
			char del_id[20];
			printf("������ ID�� �Է��� �ּ��� ");
			scanf_s("%s", del_id, sizeof(del_id));
			del_stud_info(stud, del_id);
		}
		else if (option == 3) //�˻� : �̸�, ID, 
		{
			int search_option;
			printf("�̸����� �˻��� 1��\nID�� �˻��� 2��\n");
			scanf_s("%d", &search_option);
			if (search_option == 1) // �̸�
			{
				char search_name[20];
				printf("�˻��� �̸��� �Է����ּ��� ");
				scanf_s(" %s", search_name, sizeof(search_name));
				search_stud_name(stud, search_name);
			}
			else if(search_option == 2) // ID
			{
				char search_id[20];
				printf("�˻��� ID�� �Է����ּ��� ");
				scanf_s(" %s", search_id, sizeof(search_id));
				search_stud_id(stud, search_id);
			}
			else
			{
				printf("�ٽ� �Է��ϼ���\n");
			}
		}
		else if (option == 4)
		{
			show_stud_info(stud);
		}
		else
		{
			end_program();
		}
	}
}