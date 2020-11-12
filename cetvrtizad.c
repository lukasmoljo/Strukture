#include<stdlib.h>
#include<stdio.h>
typedef struct polinom* position;
struct polinom {

	int eks, koef;
	position next;
};
position stvori()
{
	position q = (position)malloc(sizeof(position));
	if (q == NULL) {
		printf("Greska pri alociranju memorije!\n");
		return NULL;
	}
	q->next = NULL;
	return q;
}
int obrisiSve(position p)
{
	position temp = NULL;
	while (p->next != NULL) {
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
}


int ubaci(position p, position q)
{
	q->next = p->next;
	p->next = q;
}
void citajpolinom(position p, char* polinom1) {
	FILE* file = NULL;
	file = fopen(polinom1, "r");
	if (file == NULL) {
		printf("Greška u u?itavanju");
		return -1;
	}
	position q = NULL, temp = NULL;
	while (!feof(file)) {
		temp = p;
		q = stvori();
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
int ispis(position p)
{
	while (p != NULL) {
		printf("%d %d\n", p->koef, p->eks);
		p = p->next;
	}
}
int suma(position suma, position p, position q)
{
	position novi = NULL, temp = NULL;
	while (p != NULL && q != NULL) {
		if (p->next->eks > q->next->eks) {
			novi = stvori();
			if (novi == NULL)
				return -1;
			if (p->eks > q->eks) {
				novi->koef = p->koef;
				novi->eks = p->eks;
			}
			else if (p->eks < q->eks) {
				novi->koef = q->koef;
				novi->eks = q->eks;
			}
			else {
				novi->eks = p->eks;
				novi->koef = p->koef + q->koef;
				p = p->next;
				q = q->next;
			}
			ubaci(suma, novi);
			suma = novi;

		}
		if (p == NULL)
			temp = q;
		else
			temp = p;
		while (temp != NULL) {
			novi = createNew();
			if (novi == NULL)
				return 1;
			kopiraj(novi, temp);
			ubaci(suma, novi);
			suma = novi;
			temp = temp->next;
		}
		return 0;
	}
}
int pomnozi(position rez, position p, position q)
{
	position novi = NULL, temp = NULL, qHead = q;
	while (p != NULL) {
		while (q != NULL) {
			temp = rez;
			novi = createNew();
			if (novi == NULL)
				return 1;
			novi->eks = q->exp + p->eks;
			novi->koef = q->koef * p->koef;
			while (temp->next != NULL && temp->next->eks > novi->eks)
				temp = temp->next;
			if (novi->eks == temp->eks) {
				temp->koef += novi->koef;
				free(novi);
				if (temp->next->koef == 0) {
					novi = temp->next;
					temp->next = novi->next;
					free(novi);
				}
			}
			else
				ubaci(temp, novi);
			q = q->next;
		}
		p = p->next;
		q = qHead;
	}
}
	
	
	
	

	
	

