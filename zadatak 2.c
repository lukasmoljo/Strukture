#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ucenik* pozicija;
struct ucenik {
	char ime[50];
	char prez[50];
	int godina;
	pozicija next;

};

int UnosP(int x, char imena[], char prezimena[], pozicija head) {

	pozicija q = NULL;
	q = (pozicija)malloc (sizeof(struct ucenik));
	if (q == NULL)
		return -1;
	q->godina = x;
	strcpy(q->ime, imena);
	strcpy(q->prez, prezimena);

	q->next= head;
	head = q;

	return 0;

}

void ispisi(pozicija p) {

	while (p != NULL) {
		printf("%s %s %d \n", p->ime, p->prez, p->godina);
		p = p->next;
	
	
		
	}
}




void UnosK(pozicija u, pozicija head) {
	if (head == NULL) {
		head = u;
		return;
	}
	pozicija i = head;
	while (i->next != NULL)
		i = i->next;
	i->next = u;
}
pozicija trazi(char prez[], pozicija head) {
	pozicija index = head;
	for (;index != NULL;index = index->next) {
		if (strcmp(prez, index->prez) == 0)
			return index;
	}
	return NULL;


}
void brisi(char prezime[50], pozicija head) {
	if (strcmp(head->prez, prezime) == 0) {
		pozicija tmp = head;
		head = head->next;
		free(tmp);
		return;



	}
	pozicija index = head;
	for (; index->next != NULL && strcmp(index->next->prez, prezime) != 0;index = index->next) {}
	free(index->next);
	index->next = index->next->next;
}

int main() {
	int i;
	pozicija lista;
	for (i = 0;i < 10;i++) {
		pozicija np;
		scanf("%s %s %d", np->ime, np->prez, &np->godina);
		UnosK(np, lista);
		ispisi(lista);
		printf("\n");
	}
}
	
	
	

