
#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)

typedef class node *nptr;
class node { 
	int data; 
	int nchilds; 
	nptr *childs;
public:
	void build(int n, int *cdata);
	void print();
	int Degree();
	int Depth();
	int Width();
};
void node::build(int n, int*cdata) {

	int i; 
	if (this->data < 0) {  
		this->data = cdata[0]; 
		this->nchilds = n - 1; 
		this->childs = (nptr*)calloc(this->nchilds, sizeof(nptr)); 
		for (i = 0; i< this->nchilds; i++) { 
			this->childs[i] = (nptr)malloc(sizeof(node)); 
			this->childs[i]->data = cdata[i + 1]; 
			this->childs[i]->nchilds = 0; 
			this->childs[i]->childs = NULL; 
		} 
		return; 
	}
	if (this->data == cdata[0]){ 
		this->nchilds = n - 1; 
		this->childs = (nptr*)calloc(this->nchilds, sizeof(nptr)); 
		for (int i = 0; i< this->nchilds; i++) { 
			this->childs[i] = (nptr)malloc(sizeof(node)); 
			this->childs[i]->data = cdata[i + 1]; 
			this->childs[i]->nchilds = 0; 
			this->childs[i]->childs = NULL; 
		} 
		return; 
	}
	for (int i = 0; i< this->nchilds; i++) { 
		this->childs[i]->build(n, cdata); 
	}
}


void node::print() {
	int i;
	printf("[%d] ", this->data);
	for (i = 0; i < nchilds; i++) {
		printf("%d  ", this->childs[i]->data);
	}
	printf("\n");
	for (i = 0; i < nchilds; i++)
		this->childs[i]->print();
}

int node::Degree() {
	
	int value = nchilds;
	
	for (int i = 0; i < nchilds; i++) {
		if (this->childs[i] == NULL) {
			return 0;
		}
		else
			value= max(value,this->childs[i]->Degree());
	}
	return value;
}
int node::Depth() {

	
	int value = 0;
	for (int i = 0; i < nchilds; i++) {	
		value = max(value, this->childs[i]->Depth());
	}
	return ++value;
	
}


int node::Width()
{
	int  i, temp = 0;
	int sumwidth = 0;
	int *value = (int*)malloc(sizeof(int)*nchilds);
	for (i = 0; i < nchilds; i++) {
		value[i] = this->childs[i]->Depth();
		
		}
	for (int j = 0; j < nchilds; j++) {
		for (i = 0; i < nchilds - 1; i++) {
			if (value[i + 1] > value[i]) {
				temp = value[i];
				value[i] = value[i + 1];
				value[i + 1] = temp;
			}
		}
	}

	for (i = 0; i < nchilds; i++) {
		sumwidth = value[0] + value[1];
		sumwidth = max(this->childs[i]->Width(), sumwidth);
	}
	return sumwidth;
}



int main() {
	int i;
	int n_tok;
	FILE *fp = fopen("test.txt", "r+t");
	char str[256];
	int tok[10];
	node root;
	while (fgets(str, 256, fp) != NULL) {
		for (i = 0; i < 10; i++)
			tok[i] = -1;
		sscanf(str, "%d %d %d %d %d %d %d %d %d %d", &tok[0], &tok[1], &tok[2], &tok[3],
			&tok[4], &tok[5], &tok[6], &tok[7], &tok[8], &tok[9]);
		for (i = 0, n_tok = 0; i < 10; i++) {
			if (tok[i] >= 0)
				n_tok++;
		}
		root.build(n_tok, tok);
	}
	root.print();
	printf("degree´Â:[%d]\n", root.Degree());

	printf("depth´Â:[%d]\n", root.Depth());
	printf("width:[%d]:",root.Width());
}