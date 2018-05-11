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
Student *stu_CREATE(int size) {
	Student *stu = (Student*)malloc(sizeof(Student) * size);

	return stu;
}


void stu_INSERT(Student *stu, char*ptr, int*count) {

	char *str = strtok(NULL, "\n");
	Student new_student;
	sscanf(str, "%s %c %s %s %f %d %d", new_student.name, &(new_student.gender), new_student.residence, new_student.subject, &(new_student.grade), &(new_student.height), &(new_student.weight));
	int i, j;
	int result;

	for (i = 0; i < (*count); i++) {
		result = strcmp(stu[i].name, new_student.name);

		if (result == 1)
			break;
	}

	for (j = (*count) - 1; j >= i; j--) {
		stu[j + 1] = stu[j];
	}

	stu[i] = new_student;
	(*count)++;
}

void stu_LOAD(Student *stu,char *ptr,int *count) {
	int i, j = 0;
	int result = 0;
	Student new_student;
	FILE *fp;
	char*str1=strtok(NULL," \n");
	fp = fopen(str1,"r+t");
	while (fscanf(fp,"%s %c %s %s %f %d %d", new_student.name, &(new_student.gender), new_student.residence, new_student.subject, &(new_student.grade), &(new_student.height), &(new_student.weight)) != EOF){

		if (*count == 0) {
			stu[0] = new_student;
			*count = 1;
			continue;
		}

		for (i = 0; i <(*count); i++) {
			result = strcmp(stu[i].name, new_student.name);
			if (result == 1)
				break;
			
		}
		
		for (j = (*count)-1; j >= i; j--) {
			stu[j+1] = stu[j];
		}
		
		stu[i] = new_student;
		(*count)++;
	}
}

void stu_PRINT(Student *stu, int *count) {
	int i = 0;
	for (i = 0; i < *count; i++) {
		printf("%s %c %s %s %.2f %d %d\n", stu[i].name, stu[i].gender, stu[i].residence, stu[i].subject, stu[i].grade, stu[i].height, stu[i].weight);
		
	}
}


	
void stu_DELETE(Student*stu,char*ptr,int *count) {
	char*str = strtok(NULL, "\n");
	Student new_student;
	sscanf(str, "%s %c %s %s %f %d %d", new_student.name, &(new_student.gender), new_student.residence, new_student.subject, &(new_student.grade), &(new_student.height), &(new_student.weight));
	int i, j;
	int result;
	for (i = 0; i < *count; i++) {
		result = strcmp(stu[i].name, new_student.name);
		if (result == 0)
			break;

	}
	if (i == (*count)) {
		printf("존재하지않습니다.");
	}
	for (j = i; j < (*count)-1; j++) {
		stu[j] = stu[j+1];
	}

	(*count)--;
}


void stu_SEARCH(Student *stu, char*ptr,int *count) {
	char *str = strtok(NULL, "\n");
	Student new_student;
	sscanf(str, "%s", new_student.name);

	int i;
	int result = 0;
	for (i = 0; i <= (*count); i++) {
		result = strcmp(stu[i].name, new_student.name);
		if (result == 0) {
		    printf("SEARCH한 내용: %s %c %s %s %.2f %d %d \n", stu[i].name, stu[i].gender,stu[i].residence,stu[i].subject,stu[i].grade,stu[i].height,stu[i].weight);
			break;
		}
		else if(i==(*count))
		{   
			printf("SEARCH한 내용: 찾을수 없습니다.\n");
			break;
		}
	}

}

int main(void) {
	int count = 0;
	Student *stu=NULL;
	FILE *fp1;
	char str[256];
	
	fp1 = fopen("input.txt", "r+t");
		if(fp1== NULL) {
		printf("Failed to open the file\n");
		exit(0);
	}
	while (fgets(str, 256, fp1) != NULL) {
		char *ptr=strtok(str, " \n");
			if (strcmp(str, "CREATE") == 0) {
				stu = stu_CREATE(100);
			}
			else if (strcmp(str, "LOAD") == 0) {
				stu_LOAD(stu,ptr,&count);
			}
			else if (strcmp(str, "INSERT") == 0) {
				stu_INSERT(stu,ptr,&count);
			}
			else if (strcmp(str, "PRINT") == 0) {
				stu_PRINT(stu, &count);
			}
			else if (strcmp(str, "DELETE") == 0) {
				stu_DELETE(stu,ptr,&count);
			}
			else if (strcmp(str, "SEARCH") == 0) {
				stu_SEARCH(stu,ptr,&count);

		}
	}
	fclose(fp1);
	free(stu);
}
