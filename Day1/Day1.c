#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)


struct InOutputFile
{
	char name[20];
	char gender;
	char residence[20];
	char subject[30];
	float grade;
	int height;
	int weight;

};

int main() {
	struct InOutputFile File[50];// 구조체 배열 생성//
	FILE *fp;
	int index =0;
	int i = 0;
	fp = fopen("list.txt", "r+t");

	if (fp == NULL) {
		printf("예외처리.");
		return 0;
	}
	
		while (fscanf(fp, "%s %c %s %s %f %d %d", File[index].name, &File[index].gender, File[index].residence, File[index].subject, &File[index].grade, &File[index].height, &File[index].weight) != EOF) {
			index++;
		}// EOF 을 읽을 때까지 수행하면 fprintf로 구조체 변수에 파일 내용저장후에 인덱스 수 카운트//
	
		
	
	for (i = 0; i < index; i++) {
		printf("%s %c %s %s %.2f %d %d\n", File[i].name, File[i].gender, File[i].residence, File[i].subject, File[i].grade, File[i].height, File[i].weight);
	}
	//형식에 맞게 콘솔창 출력//
	fclose(fp);
}
