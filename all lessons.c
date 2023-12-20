//libraries
#include <stdio.h> 
#include <stdlib.h>

//defination of struct
struct node {
	int data;
	struct node* next;
};

//creating nodes function
struct node* createNode(int x) {
	struct node* yeni = (struct node*)malloc(sizeof(struct node));
	yeni->data = x;
	yeni->next = NULL;
	return yeni;
};
//print nodes function
void printNode(struct node* head) {
	struct node* tmp = head;
	while (tmp != NULL) {
		printf("%d\n",tmp->data);
		tmp = tmp->next;
	}	
}

//add the beggining of the nodes
void insert(struct node** head, int x) {
	struct node* yeni = createNode(x);
	yeni->next = *head;
	*head=yeni;
}

//after x add y
void addBetween(struct node* head, int x,int y) {
	struct node* yeni = createNode(y);
	struct node* tmp = head;
	while (tmp->data !=x ) {
		tmp = tmp->next;
	}
		
	
	yeni->next = tmp ->next;
	tmp->next = yeni;
}

//add the end of the list
void addEndOfList(struct node* head, int x) {
	struct node* yeni = createNode(x);
	struct node* tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = yeni;
	yeni->next = NULL;
}

//delete begining of the list
void deleteBeginnig(struct node** head) {
	struct node* tmp = *head;
	*head = tmp->next;
	free(tmp);}

//delete from between
void deleteFromList(struct node* head, int x) {
	struct node* silinecek;
	struct node* tmp = head;
	while (tmp->next->data != x)
		tmp = tmp->next;
	silinecek = tmp->next;
	tmp->next = tmp->next->next;
	free(silinecek);
}

//delete from end of the list
void deleteLastNode(struct node* head) {
	struct node* tmp = head;
	while (tmp->next->next!=NULL) 
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
	
}

//reverse
void reverse(struct node** head) {
	struct node* tmp, *tmp2, *tmp3;
	tmp = *head; tmp2=NULL;
	while (tmp != NULL) {
		tmp3 = tmp2;
		tmp2 = tmp;
		tmp = tmp->next;
		tmp2->next = tmp3;
	}
	*head = tmp2;
}

//connect two list
void connectList(struct node* head1, struct node* head2) {
	struct node* tmp = head1;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next =head2;
}

//insert circle lisr
void insertCircle(struct node** head, int x) {
	struct node* yeni = createNode(x);
	struct node* tmp = *head;
	while (tmp->next != *head) 
		tmp = tmp->next;
	tmp->next = yeni;
	yeni->next = *head;
	*head = yeni;
}

//add end of the list
void addCircleList(struct node** head, int x) {
	struct node* yeni = createNode(x);
	struct node* tmp = *head;
	while (tmp->next != *head) 
		tmp = tmp->next;
	tmp->next = yeni;
	yeni->next = *head;
	
}

//deleteBeginingOfCircle
void deleteBeginingOfCircle(struct node** head) {
	struct node* tmp = *head;
	struct node* tmp2 = *head;
	while (tmp->next != *head)
		tmp = tmp->next;
	tmp->next = tmp->next->next;
	*head = tmp->next;
	free(tmp2);
}

//deleteEndOfTheCircle
void deleteEndOfTheCircle(struct node* head) {
	struct node* tmp = head;
	while (tmp->next->next != head) 
		tmp = tmp->next;
	free(tmp->next);
	tmp->next=head;
}

//convert from circle to linked list
void convertfromCtoL(struct node* head) {
	struct node* tmp = head;
	while (tmp->next != head)
		tmp = tmp->next;
	tmp->next = NULL;
	
}

//print circle list
void printCircleList(struct node* head) {
	struct node* tmp = head;
	do {
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	} while (tmp != head);
}

int main() {
	//old style defination nodes
	/*
	struct node* eskidugum1 = (struct node*)malloc(sizeof(struct node));
	struct node* eskidugum2 = (struct node*)malloc(sizeof(struct node));
	struct node* eskidugum3= (struct node*)malloc(sizeof(struct node));
	eskidugum1->data = 5;
	printf("%d", eskidugum1->data);
	*/
	
	//definition nodes with function
	//struct node* dugum1 = createNode(1);
	//struct node* dugum2 = createNode(2);
	//struct node* dugum3 = createNode(3);

	////connect nodes
	//dugum1->next = dugum2;
	//dugum2->next = dugum3;
	//dugum3 -> next = NULL;

	////different list
	//struct node* dugum11 = createNode(1);
	//struct node* dugum21 = createNode(2);
	//struct node* dugum31 = createNode(3);

	//dugum11->next = dugum21;
	//dugum21->next = dugum31;
	//dugum31->next = NULL;



	//insert(&dugum1, 5);	// use & because head is changed, others not

	//addBetween(dugum1, 2, 5);
	
	//addEndOfList(dugum1, 10);

	//deleteBeginnig(&dugum1);
	
	//deleteFromList(dugum1,2);

	//deleteLastNode(dugum1);

	//reverse(&dugum1);

	//connectList(dugum1, dugum11);

	//printNode(dugum1);


	//circle list
	struct node* circledugum1 = createNode(1);
	struct node* circledugum2 = createNode(2);
	struct node* circledugum3 = createNode(3);
	struct node* circledugum4 = createNode(4);
	struct node* circledugum5 = createNode(5);
	struct node* circledugum6 = createNode(6);
	circledugum1->next = circledugum2; circledugum2->next = circledugum3;circledugum3->next = circledugum4;circledugum4->next = circledugum5;circledugum5->next = circledugum6;circledugum6->next = circledugum1;


	//insertCircle(&circledugum1, 9);
	
	//addCircleList(circledugum1,8);
	 
	//deleteBeginingOfCircle(&circledugum1);

	deleteEndOfTheCircle(circledugum1);

	printCircleList(circledugum1);

	
}