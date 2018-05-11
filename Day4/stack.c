#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TRUE 1            //1반환 
#define FALSE 0           //0반환 
#define MINUS -1          //-1반환 
#define MAX_SIZE 10000
#pragma warning(disable:4996)
typedef struct _stack {
	int arr[MAX_SIZE];
	int top;
}stack;

void stackinit(stack *sp) {//스택 초기화

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
	//top을 하나 올린 후 data 삽입
}

int pop(stack *sp) {
	if (isEmpty(sp) == TRUE)
		return -1;
	else
		return sp->arr[(sp->top)--];//top값 반환후 top하나내림.
}


int main() {
	int i;
	char str[20];
	stack stack;
	int n = 20;
	int num;
	stackinit(&stack);
	for (i = 0; i < n; i++) {
		printf("명령어를 입력하시오\n");
		scanf("%s", str);
		if (strcmp(str, "push") == 0) {
			printf("입력하세요\n");
			scanf("%d", &num);
			push(&stack, num);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n", pop(&stack));
		}
		
	}
	return 0;

}