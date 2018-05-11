#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#pragma warning(disable:4996)

typedef struct
{
	char name[20];
	char gender;
	char residence[20];
	char subject[30];
	float grade;
	int height;
	int weight;

} Student;
typedef struct _node node;
struct _node {
	Student item;
	node *link;
};

node *head = NULL;

void Creat() {
	node *link = NULL;
}

void Load() {
	int result = 0;
	Student new_student;
	FILE *fp;
	char*str1 = strtok(NULL, " \n");
	fp = fopen(str1, "r+t");
	while (fscanf(fp, "%s %c %s %s %f %d %d", new_student.name, &(new_student.gender), new_student.residence, new_student.subject, &(new_student.grade), &(new_student.height), &(new_student.weight)) != EOF) {

		node *curr;
		curr = head;
		node *newnode = (node*)malloc(sizeof(node));
		newnode->item = new_student;
		newnode->link = NULL;
		if (head == NULL) {
			head = newnode;
			continue;
		}
		if (strcmp(curr->item.name, new_student.name)>0) {
			newnode->link = curr;
			head = newnode;
			continue;
		}

		while (curr->link != NULL) {
			if (strcmp(curr->link->item.name, new_student.name)>0) {
				break;
			}
			curr = curr->link;
		}
		newnode->link = curr->link;
		curr->link = newnode;

	}
}


void Insert_Link() {
	char*str1 = strtok(NULL, "\n");
	int result = 0;;
	node *curr;
	Student new_student;
	curr = head;
	sscanf(str1, "%s %c %s %s %f %d %d", new_student.name, &(new_student.gender), new_student.residence, new_student.subject, &(new_student.grade), &(new_student.height), &(new_student.weight));
	node *newnode = (node*)malloc(sizeof(node));
	newnode->item = new_student;
	newnode->link = NULL;
	if (head == NULL) {
		head = newnode;

	}
	if (strcmp(curr->item.name, new_student.name)>0) {
		newnode->link = curr;
		head = newnode;
	}
	while (curr->link != NULL) {
		if (strcmp(curr->link->item.name, new_student.name) > 0) {
			break;
		}
		curr = curr->link;
	}
	newnode->link = curr->link;
	curr->link = newnode;

}


void Print_Link() {
	node *curr;
	curr = head;
	while (curr != NULL) {
		printf("%s %c %s %s %.2f %d %d\n", curr->item.name, curr->item.gender, curr->item.residence, curr->item.subject, curr->item.grade, curr->item.height, curr->item.weight);
		curr = curr->link;
	}
	printf("\n\n");
}

void Delete_Link() {
	char *str1 = strtok(NULL, " \n");
	node *curr;
	curr = head;
	Student new_student;
	sscanf(str1, "%s", new_student.name);
	if (strcmp(curr->item.name, new_student.name) == 0) {
		node *firstnode = curr;
		curr = curr->link;
		head = curr;
		free(firstnode);
		return ;
	}
	while (curr->link != NULL) {

		if (strcmp(curr->link->item.name, new_student.name) == 0) {
			break;
		}
		curr = curr->link;

	}
	node *dnode = curr->link;
	curr->link = dnode->link;
	free(dnode);
	return;
}

void Search_Link() {
	char *str1 = strtok(NULL, " \n");
	node *curr;
	curr = head;
	while (curr != NULL) {
		if (strcmp(curr->item.name, str1) == 0) {
			printf("Search한 내용은:%s \n", str1);
			return ;
		}
		curr = curr->link;
	}
	printf("Search한 내용을 찾을 수 없습니다.\n");
	return ;
}
int main(void) {


	FILE *fp1;
	char str[256];
	fp1 = fopen("input.txt", "r+t");
	if (fp1 == NULL) {
		printf("Failed to open the file\n");
		exit(0);
	}
	while (fgets(str, 256, fp1) != NULL) {
		char *ptr = strtok(str, " \n");
		if (strcmp(str, "CREATE") == 0) {
			Creat();
		}
		else if (strcmp(str, "LOAD") == 0) {
			Load();
		}
		else if (strcmp(str, "INSERT") == 0) {
			Insert_Link();
		}

		else if (strcmp(str, "PRINT") == 0) {
			Print_Link();
		}

		else if (strcmp(str, "DELETE") == 0) {
			Delete_Link();
		}

		else if (strcmp(str, "SEARCH") == 0) {
			Search_Link();

		}
	}
}