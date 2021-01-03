#include<stdio.h>
#include<string.h>
struct stablo;
typedef struct stablo* pointer;
typedef struct stablo {
	pointer left;
	pointer right;
	int el;
}stablo;

pointer alokacija();
int Unos(pointer, int);
int Postorder(pointer);
int Preorder(pointer);
pointer PronadiEl(pointer, int);
pointer max(pointer);







int main() {



}
pointer alokacija()
{
	pointer q = (pointer)malloc(sizeof(stablo));;
	if (q == NULL) return NULL;
	q->left = q->right = NULL;
	return q;
}
int Unos(pointer r, int br) {

	if (r == NULL) {
		r = alokacija();
		if (r == NULL)
			return 0;
		r->el = br;

	}


	else if (r->el > br) {
		r->left = Unos(r->left, br);

	}
	else if (r->el < br) {
		r->right = Unos(r->right, br);

	}
	else
		printf("brojevi su jednaki, sto znaci da taj broj ve? postoji u stablu");
}
int Postorder(pointer r) {
	if (r != NULL) {
		Postorder(r->left);
		Postorder(r->right);
		printf("%d", r->el);

	}
	return 0;
}
int Preorder(pointer r) {
	if (r != NULL) {
		printf("%d", r->el);
		Preorder(r->left);
		Preorder(r->right);
	}
	return 0;
}
pointer PronadiEl(pointer r, int x)
{
	if (r == NULL) {
		printf("Element ne postoji!\n");
		return NULL;
	}
	else if (x < r->el) {
		return PronadiEl(r->left, x);
	}
	else if (x > r->el) {
		return PronadiEl(r->right, x);
	}
	else {
		printf("Element pronaden!\n");
	}
	return r;

}
pointer max(pointer root) {

	if (root==NULL) return NULL;
	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}
//za min je slicna funkcija samo sto uzimamo i mičemo lijevi pointer//
pointer Izbrisi(pointer root, int x) {

	if (p == NULL)
		return NULL;
	else if (root->el == x)
		return root;
	
}
