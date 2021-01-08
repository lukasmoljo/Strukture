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
pointer Unos(pointer, int);
int Postorder(pointer);
int Preorder(pointer);
pointer PronadiEl(pointer, int);
pointer max(pointer);
pointer Izbrisi(pointer, int);
void Inorder(pointer);







int main() {
	pointer root = NULL;
	char c;
	int element;
	do {
		printf("\n1 - Unos\n2 - Pronadi\n3 - Preorder\n4 - Postorder\n5 - Izbrisi\n6 - Kraj/n");
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
			printf("Element je: ");
			scanf(" %d", &element);
			root = Unos(root, element);
			break;
		case '2':
			printf("Koji element tražite? ");
			scanf(" %d", &element);
			PronadiEl(root, element);
			break;
		case '3':
			Preorder(root);
			break;
		case '4':
			Postorder(root);
			break;
		case '5':
			printf("Element to delete: ");
			scanf(" %d", &element);
			root = Izbrisi(root, element);
			break;
		default:
			break;
		}

	} while (c != '6');

	return 0;
}




pointer alokacija()
{
	pointer q = (pointer)malloc(sizeof(stablo));;
	if (q == NULL) return NULL;
	q->left = q->right = NULL;
	return q;
}
pointer Unos(pointer r, int br) {

	if (r == NULL) {
		return br;
	}


	else if (r->el > br) {
		r->left = Unos(r->left, br);

	}
	else if (r->el < br) {
		r->right = Unos(r->right, br);

	}
	else
		free(br);
	return r;
}
void InOrder(pointer current){
	if(current==NULL)return;
	InOrder(current->left);
	printf("%d", current->number);
	InOrder(current->right);

}
int Postorder(pointer r) {
	if (r != NULL) return;
	Postorder(r->left);
	Postorder(r->right);
	printf("%d", r->el);

	
	
}
int Preorder(pointer r) {
	if (r != NULL) return;
	printf("%d", r->el);
	Preorder(r->left);
	Preorder(r->right);
	
	
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

	if (root == NULL) return NULL;
	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}
//za min je slicna funkcija samo sto uzimamo i mičemo lijevi pointer//
pointer Izbrisi(pointer root, int x) {

	if (root == NULL)
		return NULL;
	else if (x < root->el) {
		root->left = Izbrisi(root->left, x);
	}
	else if (x > root->el) {
		root->right = Izbrisi(root->right, x);

	}
	else {
		pointer temp = NULL;
		if (root->left != NULL && root->right != NULL) {
			temp = max(root->left);
			root->el = temp->el;
			root->left = Izbrisi(root->left, temp->el);

		}
		else {
			temp = root;
			if (root->left != NULL)
				root = root->left;

			else {
				root = root->right;
				free(temp);
			}
			return root;


		}
	}
}
