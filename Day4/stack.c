#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TRUE 1            //1��ȯ 
#define FALSE 0           //0��ȯ 
#define MINUS -1          //-1��ȯ 
#define MAX_SIZE 10000
#pragma warning(disable:4996)
typedef struct _stack {
	int arr[MAX_SIZE];
	int top;
}stack;

void stackinit(stack *sp) {//���� �ʱ�ȭ

	sp->top=-1;
}

int isEmpty(stack *sp) {
	if (sp->top == -1)
		return TRUE;
	else
		return FALSE;
}
int isFull(stack *sp) {
	if (sp->top == MAX_SIZE)
		return TRUE;
	else
		return FALSE;
}
int size(stack *sp) {
	return sp->top + 1;
}

void push(stack *sp, int data) {
	if (isFull(sp) == TRUE)
		return;
	else
		sp->arr[++(sp->top)] = data;
	//top�� �ϳ� �ø� �� data ����
}

int pop(stack *sp) {
	if (isEmpty(sp) == TRUE)
		return -1;
	else
		return sp->arr[(sp->top)--];//top�� ��ȯ�� top�ϳ�����.
}


int main() {
	int i;
	char str[20];
	stack stack;
	int n = 20;
	int num;
	stackinit(&stack);
	for (i = 0; i < n; i++) {
		printf("��ɾ �Է��Ͻÿ�\n");
		scanf("%s", str);
		if (strcmp(str, "push") == 0) {
			printf("�Է��ϼ���\n");
			scanf("%d", &num);
			push(&stack, num);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n", pop(&stack));
		}
		
	}
	return 0;

}