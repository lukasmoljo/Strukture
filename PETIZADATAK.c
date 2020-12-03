#include<stdio.h>
#include<stdlib.h>
typedef struct skup* pozicija;
struct skup {
	int broj;
	pozicija next;
};
pozicija createNew()
{
	pozicija q = (pozicija)malloc(sizeof(_POLINOM));
	if (q == NULL) {
		printf("Greska pri alociranju memorije!\n");
		return NULL;
	}
	q->next = NULL;
	return q;
}
int UnosP(int x, pozicija head) {

	pozicija q = NULL;
	q = (pozicija)malloc(sizeof(struct pozicija));
	if (q == NULL)
		return -1;
	q->broj = x;
	q->next = head;
	head = q;

	return 0;

}

int Unija(pozicija l1, pozicija l2, pozicija uni)
{
	pozicija novi = NULL, tmp = NULL;
	while (l1 != NULL && l2 != NULL) {
		novi = createNew();

		if (l1->el > l2->el) {
			novi->el = l1->el;
			l1 = l1->next;
		}
		else if (l2->el > l1->el) {
			novi->el = l2->el;
			l2 = l2->next;
		}
		else {
			novi->el = l1->el;
			l1 = l1->next;
			l2 = l2->next;
		}

		novi->next = uni->next;
		uni->next = newNode;
		uni = newNode;
	}
	if (l1 == NULL)
		tmp = l2;
	else
		tmp = l1;
	while (tmp != NULL) {
		novi = createNew();

		novi->el = tmp->el;
		novi->next = uni->next;
		uni->next = novi;
		uni = novi;
		tmp = tmp->next;
	}
	return 0;
}

int presjek(pozicija l1, pozicija l2, pozicija pres)
{
	pos novi = NULL;
	while (l1 != NULL && l2 != NULL) {
		if (l1->el > l2->el) {
			l1 = l1->next;
		}
		else if (l2->el > l1->el) {
			l2 = l2->next;
		}
		else if (l1->el == l2->el) {
			novi = createNew();

			novi->el = l1->el;
			l1 = l1->next;
			l2 = l2->next;
			novi->next = pres->next;
			pres->next = novi;
			pres = novi;
		}
	}

	return 0;
}








void ispisi(pozicija p) {

	while (p != NULL) {
		printf(" %d \n", p->broj);
		p = p->next;



	}
}

	
	