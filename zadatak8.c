#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSIZE 64


struct tree;
typedef struct tree* treePos;
typedef struct tree {
	char* name;
	treePos sibling;
	treePos child;
}TREE;

struct stack;
typedef struct stack* stackPos;
typedef struct stack {
	char* nodeName;
	treePos el;
	stackPos next;
}STACK;




treePos createTreeNode();
stackPos createStackNode();
int printPath(stackPos p);
int addToStack(stackPos head, treePos current, char* name);
int makeDir(treePos p, char* name);
int changeDir(treePos* current, stackPos head, char* name);
int upDir(treePos* current, stackPos head);
int dir(treePos p);
int deleteTree(treePos p);
int deleteStack(stackPos p);

int main(void)
{
	TREE root;
	STACK head;
	treePos current;
	char c, * nodeName = NULL;
	int error = 0;

	root.next = root.child = NULL;
	head.next = NULL;
	root.name = (char*)malloc(sizeof(char) * BUFFSIZE);
	nodeName = (char*)malloc(sizeof(char) * BUFFSIZE);
	memset(root.name, '\0', BUFFSIZE);
	memset(nodeName, '\0', BUFFSIZE);

	printf("Name of root: ");
	scanf(" %s", nodeName);
	strcpy(root.name, nodeName);
	current = &root;
	printPath(head.next);
	printf("%s>\n", current->name);

	do
	{
		printf("1 - md\n2 - cd dir\n3 - cd..\n4 - dir\n5 - exit\n");
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
			printf("Name of new directory: ");
			scanf(" %s", nodeName);
			error = makeDir(current, nodeName);
			printPath(head.next);
			printf("%s>\n", current->name);
			memset(nodeName, '\0', BUFFSIZE);
			break;
		case '2':
			printf("Name of directory: ");
			scanf(" %s", nodeName);
			error = changeDir(&current, &head, nodeName);
			printPath(head.next);
			printf("%s>\n", current->name);
			memset(nodeName, '\0', BUFFSIZE);
			break;
		case '3':
			error = upDir(&current, &head);
			printPath(head.next);
			if (error) printf("Alrerady in the root!\n");
			printf("%s>\n", current->name);
			break;
		case '4':
			printPath(head.next);
			printf("%s>\n", current->name);
			dir(current->child);
			break;
		default:
			break;
		}
	} while (c != '5');

	deleteStack(&head);
	deleteTree(&root);

	system("pause");
	return 0;
}
int printPath(stackPos p)
{
	if (p == NULL) return 0;
	printPath(p->next);
	printf("%s", p->nodeName);
	return 0;
}

int addToStack(stackPos head, treePos current, char* name)
{
	stackPos q = createStackNode();
	if (q == NULL) return 1;
	q->el = current;
	strcpy(q->nodeName, name);
	strcat(q->nodeName, "\\");
	q->next = head->next;
	head->next = q;
	return 0;
}

treePos createTreeNode()
{
	treePos q = (treePos)malloc(sizeof(TREE));
	if (q == NULL) {
		printf("Can't allocate memory!\n");
		return NULL;
	}
	q->sibling = NULL;
	q->child = NULL;
	q->name = (char*)malloc(sizeof(char) * BUFFSIZE);
	return q;
}
stackPos createStackNode()
{
	stackPos q = (stackPos)malloc(sizeof(STACK));
	if (q == NULL) {
		printf("Can't allocate memory!\n");
		return NULL;
	}
	q->next = NULL;
	q->nodeName = (char*)malloc(sizeof(char) * BUFFSIZE);
	return q;
}
int addToStack(stackPos head, treePos current, char* name)
{
	stackPos q = createStackNode();
	if (q == NULL) return 1;
	q->el = current;
	strcpy(q->nodeName, name);
	strcat(q->nodeName, "\\");
	q->next = head->next;
	head->next = q;
	return 0;
}

int makeDir(treePos p, char* name)
{
	if (p == NULL) return 1;
	treePos q = createTreeNode();
	treePos tmp = NULL;
	if (q == NULL) return 1;
	strcpy(q->name, name);
	if (p->child == NULL)
	{
		p->child = q;
	}
	else if (strcmp(p->child->name, q->name) >= 0)
	{	
		if (strcmp(p->child->name, q->name) == 0) {
			printf("Can't make directory with a same name!\n");
			return 1;
		}
		q->next = p->child;
		p->child = q;
	}
	else
	{
		tmp = p->child;
		while (tmp->next != NULL && (strcmp(tmp->next->name, q->name) < 0)) {
			
			tmp = tmp->next;
		}
		if (tmp->next != NULL && strcmp(q->name, tmp->next->name) == 0) {
			printf("Can't make directory with a same name!\n");
			return 1;
		}
		q->next = tmp->next;
		tmp->next = q;
	}
	return 0;
}

int changeDir(treePos* current, stackPos head, char* name)
{
	treePos p = (*current)->child;
	while (p != NULL && strcmp(p->name, name)) {
		p = p->next;
	}
	if (p == NULL) {
		printf("Directory does not exist!\n");
		return 1;
	}
	addToStack(head, *current, (*current)->name);
	*current = p;

	return 0;
}

int upDir(treePos* current, stackPos head)
{
	if (head->next == NULL) return 1;
	stackPos tmp = head->next;
	*current = head->next->el;
	head->next = tmp->next;
	free(tmp);
	return 0;
}

int dir(treePos p)
{
	if (p == NULL)
		printf("\n");
	while (p != NULL) {
		printf("\t\t%s\n", p->name);
		p = p->next;
	}
	return 0;
}

int deleteStack(stackPos p)
{
	stackPos tmp = NULL;
	while (p != NULL && p->next != NULL) {
		tmp = p->next;
		free(tmp->nodeName);
		p->next = tmp->next;
		free(tmp);
	}
}

int deleteTree(treePos p)
{
	if (p == NULL)
		return 0;
	deleteTree(p->child);
	deleteTree(p->next);
	free(p);
	return 0;
}
