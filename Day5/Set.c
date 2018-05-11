
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

typedef struct {
	char s_subred[30];
	int num;
}S_sub;

Student *stu_CREATE(int size) {
	Student *stu = (Student*)malloc(sizeof(Student) * size);
	return stu;
}
void stu_LOAD(Student *stu, int *count) {
	int i, j = 0;
	int result = 0;
	Student new_student;
	FILE *fp = fopen("list.txt", "r+t");
	while (fscanf(fp, "%s %c %s %s %f %d %d", new_student.name, &(new_student.gender), new_student.residence, new_student.subject, &(new_student.grade), &(new_student.height), &(new_student.weight)) != EOF) {

		if ((*count) == 0){
			stu[0] = new_student;
			*count = 1;;
			continue;
		}
		for (i = 0; i <(*count); i++) {
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
	
	fclose(fp);
}


void Q1(Student *stu, int *count) {
	int i;
	int result = 0;
	for (i = 0; i <= (*count); i++) {
		result = strcmp(stu[i].name, "김문희");
		if (result == 0) {
			printf("Q1 : %s가 사는 곳은: %s\n", stu[i].name, stu[i].residence);
			break;
		}
		else if (i == (*count))
		{
			printf("Q1 : SEARCH한 내용: 찾을수 없습니다.\n");
			break;
		}
	}
}
void Q2(Student *stu, int *count) {
	int i;
	int result = 0;
	float h_grade;
	int people=0;
	int better_grade_people = 0;
	for (i = 0; i <= (*count); i++) {
		result = strcmp(stu[i].name, "천하은");
		if (result == 0) {
			h_grade = stu[i].grade;
			break;
		}
	} 
	for (i = 0; i < (*count); i++) {
		if (h_grade >= stu[i].grade) {
			people++;
		}
	}
	better_grade_people = *count - people;
	printf("Q2: 천하은보다 성적이 더 좋은 사람은 총 %d 명이다.\n",better_grade_people);
}


void Q3(Student *stu, int *count) {
	S_sub *numsub = (S_sub*)malloc(sizeof(S_sub)*(*count));
	int student_count ,num_C_count= 0;
	int max = 0;
	int num_count = 0;
	
	for (int initialization = 0; initialization < *count; initialization++)
		numsub[initialization].num = 0;

	for (student_count = 0; student_count < *count; student_count++) {
		if (student_count == 0) {
			strcpy(numsub[0].s_subred, stu[student_count].subject);
			numsub[0].num = 1;
			num_count++;
			continue;
		}
		for (num_C_count = 0; num_C_count < num_count; num_C_count++) {
			if (strcmp(numsub[num_C_count].s_subred, stu[student_count].subject) == 0) {
				numsub[num_C_count].num++;
				break;
			}
		}
		if (num_C_count == num_count) {
			strcpy(numsub[num_count].s_subred, stu[student_count].subject);
			numsub[num_count].num++;
			num_count++;
		}
	}
	for (int i = 0; i < num_count; i++) {
		if (numsub[i].num > max) {
			max = numsub[i].num;
		}
	}
	for (int i = 0; i < num_count; i++) {
		if (numsub[i].num == max) {
			printf("Q3 :가장 학생이 많은 학과는 :%s \n", numsub[i].s_subred);
			break;
		}
	}
}

void Q4(Student *stu, int *count) {
	S_sub *numsub = (S_sub*)malloc(sizeof(S_sub)*(*count));
	int student_count, num_C_count = 0;
	int num_count = 0;
	
	S_sub Bubble_sort;
	for (int initialization = 0; initialization < *count; initialization++)
		numsub[initialization].num = 0;

	for (student_count = 0; student_count < *count; student_count++) {
		if (student_count == 0) {
			strcpy(numsub[0].s_subred, stu[student_count].residence);
			numsub[0].num = 1;
			num_count++;
			continue;
		}
		for (num_C_count = 0; num_C_count < num_count; num_C_count++) {
			if (strcmp(numsub[num_C_count].s_subred, stu[student_count].residence) == 0) {
				numsub[num_C_count].num++;
				break;
			}
		}
		if (num_C_count == num_count) {
			strcpy(numsub[num_count].s_subred, stu[student_count].residence);
			numsub[num_count].num++;
			num_count++;
		}
	}

	for (int i = 0; i < num_count - 1; i++) {

		for (int j = 0; j < num_count - 1; j++) {

			if (numsub[j].num < numsub[j + 1].num) {
				Bubble_sort = numsub[j];
				numsub[j] = numsub[j + 1];
				numsub[j + 1]= Bubble_sort;
			}
		}
	}
	printf("Q4: 거주지가 많은 지역 순은:");
	for (int i = 0; i < num_count; i++) {
		printf(" %s  ", numsub[i].s_subred);
	}
}

void Q5(Student *stu, int *count) {
	S_sub *numsub = (S_sub*)malloc(sizeof(S_sub)*(*count));
	int student_count, num_C_count = 0;
	int num_count = 0;

	for (int initialization = 0; initialization < *count; initialization++)
		numsub[initialization].num = 0;

	for (student_count = 0; student_count < *count; student_count++) {
		if (student_count == 0) {
			strcpy(numsub[0].s_subred, stu[student_count].name);
			numsub[0].num = 1;
			num_count++;
			continue;
		}
		for (num_C_count = 0; num_C_count < num_count; num_C_count++) {
			if (strcmp(numsub[num_C_count].s_subred, stu[student_count].name) == 0) {
				numsub[num_C_count].num++;
				break;
				
			}
		}
		if (num_C_count == num_count) {
			strcpy(numsub[num_count].s_subred, stu[student_count].name);
			numsub[num_count].num++;
			num_count++;
		}
	}
	for (int i = 0; i < num_count; i++) {	
		if (numsub[i].num != 1) {
			printf("\nQ5: 이름을 ID로 사용 할 수 없습니다.\n");
			return ;
		}
	}
	printf("\nQ5: 이름을 ID로 사용할 수 있습니다.\n");

}
void main() {

	Student *stu = NULL;
	int count = 0;
	stu=stu_CREATE(100);
	stu_LOAD(stu, &count);
	Q1(stu, &count);
	Q2(stu, &count);
	Q3(stu, &count);
	Q4(stu, &count);
	Q5(stu, &count);
	free(stu);
}
