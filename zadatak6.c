#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
typedef struct stog *position;
struct stog {

    int br;
    position next;
};
int Push(int,position);           
int Pop(position);   
void Brisi(position);
void Ispisi(position);  
void UnosK(position, position);
int RadStoga(position);
int RadReda(position);


int main()
{
    srand(time(NULL));

    position head = NULL;
    RadStoga(head);
    RadReda(head);



    return 0;
}
int Push(int x, position head) {
    position temp = NULL;
    temp = (position)malloc(sizeof(position));
    if (temp == NULL) {
        printf("Problem with allocation");
        return -1;
        temp->br = x;
        temp->next = head;
        head = temp;
        return 0;
    }
}
int Pop(position head) {
    position temp = NULL;
    temp = (position)malloc(sizeof(position));
    if (temp == NULL) {
        printf("Problem with allocation");
        return -1;
    }
    temp = head->next;
    head->next = temp->next;
    free(temp);
}
void UnosK(position u, position head) {
    if (head == NULL) {
        head = u;
        return;
    }
    position i = head;
    while (i->next != NULL)
        i = i->next;
    i->next = u;
}
void Ispisi(position p) {

    while (p != NULL) {
        printf("%d \n", p->br);
        p = p->next;



    }
}
void Brisi(position head)
{
    position temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        free(head);
        head = temp;
    }

    
}

int RadStoga(position head) {
    int i = 0, x;
    char s;
    while (i = 0) {
        printf("Ako zelite stavljati na stog upisite  s , a ako zelite maknuti sa stoga unesti m, a ako zelite ispisati listu jer je kraj upisite k\n");
        scanf("%d", &s);
        if (s == "s") {
            scanf("Unesite koji broj zelite unijeti na stog\n %d", &x);
            Push(x, head);
            Ispisi(head);
        }
        else if (s == "m") {
            Pop(head);
            Ispisi(head);

        }
        else if (s == "k") {
            i++;
            Ispisi(head);
        }
    }
    brisi(head);
}
int RadReda(position head) {
    position last = NULL;
    int i = 0;
    char s;
    if (head->next = NULL)
        last = head;
    else {
        while (head->next != NULL) {
            last = head;
        }
    }
    while (i = 0) {
        printf("Ako zelite stavljati u red upisite  s , a ako zelite maknuti iz reda unesite m, a ako zelite ispisati listu jer je kraj upisite k\n");
        scanf("%d", &s);
        if (s == "s") {
            scanf("Unesite koji broj zelite unijeti na stog\n %d", &x);
            Push(x, last);
            Ispisi(head);
        }
        else if (s == "m") {
            Pop(head);
            Ispisi(head);

        }
        else if (s == "k") {
            i++;
            Ispisi(head);
        }

    }
}
