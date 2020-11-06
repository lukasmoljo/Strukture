#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct ucenik {
    char* ime, * prez;
    int god;
    ucenik* next;
} ucenik;

ucenik* newUcenik(char* i, char* p, int g) {
    ucenik* U = (ucenik*)malloc(sizeof(ucenik));
    U->ime = i;
    U->prez = p;
    U->god = g;
    U->next = NULL;
    return U;
}

void dodajIza(ucenik* head, char* prez1, char* ime, char* prez2, int god) { 
    ucenik* novi = newUcenik(ime, prez2, god);
    ucenik* i = head;
    while (i != NULL && strcmp(i->prez, prez1) != 0)
        i = i->next;
    if (i == NULL)
        printf("Ne postoji prez1!\n");
    else {
        novi->next = i->next;
        i->next = novi;
    }
}

void dodajIspred(ucenik* head, char* prez1, char* ime, char* prez2, int god) { 
    ucenik* novi = newUcenik(ime, prez2, god);
    if (strcmp(head->prez, prez1) == 0) { 
        novi->next = head;
        head = novi;
    }
    else {
        ucenik* i;
        for (i = head; i->next != NULL && strcmp(i->next->prez, prez1); i = i->next) {} 
        if (i->next == NULL)
            printf("Ne postoji prez1!\n");
        else {
            novi->next = i->next;
            i->next = novi;
        }
    }
}

void swap(ucenik* a, ucenik* b) { 
    char* tmp = a->ime;
    a->ime = b->ime;
    b->ime = tmp;
    tmp = a->prez;
    a->prez = b->prez;
    b->prez = tmp;
    int temp = a->god;
    a->god = b->god;
    b->god = temp;
}

int strcmp(char* s1, char* s2) { 
    int res = 0;                  
    for (; *s1 != '\0' && *s2 != '\0' && res == 0; s1++, s2++)
        res = *s1 - *s2;
    return res;
}

void sort(ucenik* head) {
    for (ucenik* i = head; i != NULL; i = i->next)
        for (ucenik* j = i; j != NULL; j = j->next)
            if (strcmp(j->prez, i->prez) < 0) 
                swap(i, j); 
}