#include<stdlib.h>
#include<stdio.h>
typedef struct polinom* position;
struct polinom {

	int eks, koef;
	position next;
};
position novi()
{
	position q = (position)malloc(sizeof(position));
	if (q == NULL) {
		printf("Greska pri alociranju memorije!\n");
		return NULL;
	}
	q->next = NULL;
	return q;
}
int ubaci(position p, position q)
{
	q->next = p->next;
	p->next = q;
}
void citajpolinom(position p, char* polinom.txt) {
	FILE* file = NULL;
	file = fopen(polinom.txt, "r");
	if (file == NULL) {
		printf("Greška u u?itavanju");
		return -1;
	}
	position q=NULL, temp=NULL;
	while (!feof(file)) {
		temp = p;
		q = novi();
		if (q == NULL)
			return -1;
		fscanf(file, " %d %d", &q->koef, &q->eks);
		if (q->koef == 0) {
			free(q);
			continue;
		}
		while (temp->next != NULL && temp->next->eks > q->eks)
			temp = temp->next;
		if (temp->next != NULL && temp->next->eks == q->eks) {
			temp->next->koef += q->koef;
			free(q);
			if (temp->next->koef == 0) {
				q = temp->next;
				temp->next = q->next;
				free(q);
			}
		}
		else
			ubaci(temp, q);

	}
	fclose(file);
	return 0;
}
	
	
	
	

	
	

