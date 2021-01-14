#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct Tree;
typedef struct Tree* posTree;
typedef struct Tree{
	char op[10];
	posTree left;
	posTree right;


}TREE;
struct stack;
typedef struct stack* posStack;
typedef struct stack {
	posTree el;
	posStack next;
}STACK;

posTree createTreeNode();
posStack createStackNode();
int main() {}



posTree createTreeNode()
{
	posTree q = (posTree)malloc(sizeof(TREE));
	if (q == NULL) return NULL;
	q->left = q->right = NULL;
	return q;
}

posStack createStackNode()
{
	posStack q = (posStack)malloc(sizeof(STACK));
	if (q == NULL) return NULL;
	q->next = q->el = NULL;
	return q;
}
int popFromStack(posStack head, posTree* returnValue)
{
	if (head == NULL || head->next == NULL || returnValue == NULL) return 1;
	posStack tmp = head->next;
	*returnValue = tmp->el;
	head->next = tmp->next;
	free(tmp);

	return 0;
}
