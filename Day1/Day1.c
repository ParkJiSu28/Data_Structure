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
	struct InOutputFile File[50];// ����ü �迭 ����//
	FILE *fp;
	int index =0;
	int i = 0;
	fp = fopen("list.txt", "r+t");

	if (fp == NULL) {
		printf("����ó��.");
		return 0;
	}
	
		while (fscanf(fp, "%s %c %s %s %f %d %d", File[index].name, &File[index].gender, File[index].residence, File[index].subject, &File[index].grade, &File[index].height, &File[index].weight) != EOF) {
			index++;
		}// EOF �� ���� ������ �����ϸ� fprintf�� ����ü ������ ���� ���������Ŀ� �ε��� �� ī��Ʈ//
	
		
	
	for (i = 0; i < index; i++) {
		printf("%s %c %s %s %.2f %d %d\n", File[i].name, File[i].gender, File[i].residence, File[i].subject, File[i].grade, File[i].height, File[i].weight);
	}
	//���Ŀ� �°� �ܼ�â ���//
	fclose(fp);
}
