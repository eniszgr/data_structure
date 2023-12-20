//libraries
#include <stdio.h> 
#include <stdlib.h>

//definition of two way list
struct node {
	int data;
	struct node* next;
	struct node* prev;
};

//create two way nodes
struct node* createTwoWayNode(int x) {
	struct node* yeni = (struct node*)malloc(sizeof(struct node));
	yeni->data = x;
	yeni->next = NULL;
	yeni->prev = NULL;
	return yeni;
}

//add begining of the list 
void addBeginingtw(struct node** head, int x) {
	struct node* yeni = createTwoWayNode(x);
	yeni->next = *head;
	yeni->next->prev = yeni;//tmp->prev=yeni;
	*head = yeni;

}

//add between in two way list
void addBetweentw(struct node* head, int x, int y) {
	struct node* yeni = createTwoWayNode(y);
	struct node* tmp = head;
	while (tmp->data != x) 
		tmp = tmp->next;
	yeni->next = tmp->next;
	yeni->next->prev = yeni;
	tmp->next = yeni;
	tmp->next->prev = tmp;
}

//delete from begining tw
void deleteFromBegining(struct node** head) {
	struct node* tmp = *head;
	*head = tmp->next;
	tmp->next->prev = NULL;
	free(tmp);
}

//delete last node tw
void deleteLastNode(struct node* head) {
	struct node* tmp = head;
	while (tmp->next->next != NULL) 
		tmp = tmp->next;
	tmp->next = NULL;
	free(tmp->next);
}

//print nodes
void printNode(struct node* head) {
	struct node* tmp = head;
	while (tmp != NULL) {
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

struct dugum {
	int data;
	struct dugum* next;
	struct dugum* prev;
};

struct dugum* createDugum(int x) {
	struct dugum* yeni = (struct dugum*)malloc(sizeof(struct dugum));
	yeni->data = x;
	yeni->next = NULL;
	yeni->prev = NULL;
	return yeni;
}

int main() {

	struct node* twdugum1 = createTwoWayNode(1);
	struct node* twdugum2 = createTwoWayNode(2);
	struct node* twdugum3 = createTwoWayNode(3);
	twdugum1->next = twdugum2; twdugum2->next = twdugum3;
	twdugum3->prev = twdugum2;twdugum2->prev = twdugum1;


	//addBeginingtw(&twdugum1, 0);

	//addBetweentw(twdugum1, 2, 0);
	
	//deleteFromBegining(&twdugum1);
	
	//deleteLastNode(twdugum1);

	//printNode(twdugum1);

	struct dugum* dugum1 = createDugum(1);
	struct dugum* dugum2 = createDugum(2);
	struct dugum* dugum3 = createDugum(3);
	dugum1->next = dugum2;dugum2->next = dugum3;
	dugum3->prev = dugum2;dugum2->prev = dugum1;

	printNode(dugum1);
}