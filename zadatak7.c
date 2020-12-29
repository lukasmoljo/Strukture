#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define BUFF 16
typedef struct stog* position;
struct stog {

    float br;
    position next;
};
position stvoriNovi();
int Push(position, int);
int Pop(position, int*);
int Izracunaj(char*, int, int, float*);
int CitajizFilea(position, char*);
int Izbrisi(position);

int main() {
	int var = 0;
	stog head;
	head.next = NULL;

	var = readFromFile(&head, "postfiks.txt");
	if (!var)
		printf("%d\n", head.next->el);
	else
		printf("Pogreska!\n");
	Izbrisi(&head);
	system("pause");
	return 0;







}
position stvoriNovi()
{
	position q = (position)malloc(sizeof(position));
	if (q == NULL) {
		printf("Greska u alokaciji memorije!\n");
		return NULL;
	}
	q->next = NULL;
	return q;
}
int Push(int x, position head) {
    position temp = stvoriNovi();
    temp->br = x;
    temp->next = head;
    head = temp;
    return 0;
    }



int Pop(position p, int* num)
{
	if (p == NULL || p->next == NULL)
		return 1;
	position tmp = p->next;
	*num = tmp->br;
	p->next = tmp->next;
	free(tmp);
	return 0;
}
int Izracunaj(char* operation, int a, int b, float* result)
{
	if (operation == NULL || strlen(operation) != 1)
		return 1;
	switch (*operation){
	case '+': 
		*result = a + b;
		break;
	case '-':
		*result = a - b;
		break;
	case '*':
		*result = a * b;
		break;
	case '/':
		if (b == 0)
			printf("Nije dozvoljeno dijeliti sa 0\n ");
		*result = a / b;
		break;
	default:
		printf("Operacija: %s\n", operation);
		return 1;
	}
	return 0;
}
int CitajizFilea(position head, char* ImeFilea) {
	char buffer[BUFF];
	int broj, a = 0, b = 0, rez = 0, temp = 0;

	FILE* f = fopen(ImeFilea, "r");
	if (f == NULL) {
		printf("Problem s otvaranjem filea");
		return -1;
	}
	while (!feof) {
		fscanf(f, "s", buffer);
		if (strlen(buffer) == 0) {
			continue;
		}
		if (sscanf(buffer, "d", &broj > 0)) {
			Push(head, broj);
		}
		else {
			temp = Pop(head, &b);
			if (temp)
				break;
			temp = Pop(head, &a);
			if (temp)
				break;
			temp = Izracunaj(buffer, a, b, &rez);
			if (temp)
				break;
			push(head, rez);
		}
	}
}
int Izbrisi(position p)
{
	position tmp = NULL;
	while (p->next != NULL) {
		tmp = p->next;
		p->next = tmp->next;
		free(tmp);
	}
}
	
		
		
		
			








