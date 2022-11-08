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
	printf("학과 : %s\n", tra->dept);
	printf("입학년도 : %d\n", tra->year);
	printf("이름 : %s\n", tra->name);
	printf("키 : %lf\n", tra->height);
	printf("몸무게 : %lf\n", tra->weight);
	printf("혈액형 : %s\n", tra->blood);
}
void push_stud_info(students* data, students* stud) //학생 정보 입력 push
{
	data->next = stud->next;
	stud->next = data;
}
void del_stud_info(students* stud, const char* del_id) //학생 정보 삭제 ID  
{
	// 삭제할 노드의 이전 노드를 찾아야함
	// ID 가 같은 노드가 삭제할 노드
	students* tra = stud;
	students* prev;
	while (1)
	{
		prev = tra;
		tra = tra->next;
		if (tra == NULL)
		{
			printf("검색 결과를 찾을 수 없습니다\n");
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
void search_stud_name(students* stud, const char* search_name) //학생 검색 이름
{
	students* tra = stud->next;
	while (1)
	{
		if (tra == NULL)
		{
			printf("검색 결과를 찾을 수 없습니다\n");
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
void search_stud_id(students* stud, const char* search_id)  // 학생 ID로 검색
{
	students* tra = stud->next;
	while (1)
	{
		if (tra == NULL)
		{
			printf("검색 결과를 찾을 수 없습니다\n");
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
void show_stud_info(students* stud) //학생 정보 출력 : 모두
{	
	students* tra = stud;
	while (tra->next != NULL)
	{
		tra = tra->next;
		print_stud_info(tra);
	}
}
void end_program() // 프로그램 종료
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
		printf("1. 학생 정보 입력\n2. 학생 정보 삭제\n3. 학생 검색\n4. 학생 정보 출력\n5. 프로그램 종료\n");
		scanf_s("%d", &option);
		if (option == 1)
		{
			students* data = (students*)malloc(sizeof(students));
			printf("ID 를 입력하세요 ");
			scanf_s("%s", &data->id, sizeof(data->id));
			printf("dept 를 입력하세요 ");
			scanf_s(" ");
			gets_s(data->dept, sizeof(data->dept));
			printf("year 를 입력하세요 ");
			scanf_s(" %d", &data->year);
			printf("name 를 입력하세요 ");
			scanf_s(" %s", &data->name, sizeof(data->name));
			printf("height 를 입력하세요 ");
			scanf_s("%lf", &data->height);
			printf("weight 를 입력하세요 ");
			scanf_s("%lf", &data->weight);
			printf("blood 를 입력하세요 ");
			scanf_s(" %s", &data->blood, sizeof(data->blood));
			push_stud_info(data, stud);
		}
		else if (option == 2)  // 삭제
		{
			char del_id[20];
			printf("삭제할 ID를 입력해 주세요 ");
			scanf_s("%s", del_id, sizeof(del_id));
			del_stud_info(stud, del_id);
		}
		else if (option == 3) //검색 : 이름, ID, 
		{
			int search_option;
			printf("이름으로 검색은 1번\nID로 검색은 2번\n");
			scanf_s("%d", &search_option);
			if (search_option == 1) // 이름
			{
				char search_name[20];
				printf("검색할 이름을 입력해주세요 ");
				scanf_s(" %s", search_name, sizeof(search_name));
				search_stud_name(stud, search_name);
			}
			else if(search_option == 2) // ID
			{
				char search_id[20];
				printf("검색할 ID를 입력해주세요 ");
				scanf_s(" %s", search_id, sizeof(search_id));
				search_stud_id(stud, search_id);
			}
			else
			{
				printf("다시 입력하세요\n");
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