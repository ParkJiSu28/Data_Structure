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
	struct InOutputFile File;
	FILE *fp,*ffp;
	fp = fopen("list.txt", "r+t");
	ffp = fopen("list2.txt", "w+t");
	if (fp == NULL) {
		printf("예외처리.");
		return 0;
	}
	

	while (fscanf(fp, "%s %c %s %s %f %d %d", File.name, &File.gender, File.residence, File.subject, &File.grade, &File.height, &File.weight) != EOF) 
		fprintf(ffp, "%s %c %s %s %f %d %d\n", File.name, File.gender, File.residence, File.subject, File.grade, File.height, File.weight);
	
	fclose(fp);
	fclose(ffp);
}
