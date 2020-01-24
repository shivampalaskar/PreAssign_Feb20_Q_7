/*
 ============================================================================
 Name        : PreAssign_Feb20_Q_7.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BankAccounts {
	int id;
	char type[10];
	float bal;
	struct Acount_Holder{
		char name[20];
		char addrs[20];
		char cont[10];

	};
	struct Acount_Holder accHldr;
	struct BankAccounts *nextNode;
	struct BankAccounts *PreNode;
}BANKACC;

BANKACC* createNode();
BANKACC* getLastNode();
BANKACC* get2ndLastNode();
void addNodeAtLast();
void addNodeAtFirst();
void addNodeAtGivenPos(int);
int isEmpty();
int getLength();
int verifyPos(int);
void delFirst();
void delLast();
void delAtPos(int);
void displayNodesRtoL();
void displayNodesLtoR();
int getData();
void findById();
void findByName();

BANKACC* head = NULL;

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int choice,pos;
	do {
		printf("\nChose operation to perform : ");
		printf("\n1) Add at First Position");
		printf("\n2) Add at Last Position");
		printf("\n3) Add at given Position");
		printf("\n4) Display Right to Left");
		printf("\n5) display Left to Right");
		printf("\n6) Delete First");
		printf("\n7) Delete Last");
		printf("\n8) Delete at Given Position");
		printf("\n9) Delete All");
		printf("\n10) Find By Account Id");
		printf("\n11) Find By Account Name");
		printf("\n12) Length");
		printf("\n13)Exit");
		printf("\n Enter Choice : ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			addNodeAtFirst();
			printf("\n Added Successfully");
			break;
		case 2:
			addNodeAtLast();
			printf("\n Added Successfully");
			break;
		case 3:
			printf("\n Enter Position Number : ");
			scanf("%d",&pos);
			if (verifyPos(pos)) {
				addNodeAtGivenPos(pos);
				printf("\n Added Successfully at %d Position", pos);
			}else
				printf("\n Invalid Position");
			break;
		case 4:
			if(isEmpty())
				printf("\nLinked List is Empty");
			else
				displayNodesRtoL();
			break;
		case 5:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else
				displayNodesLtoR();
			break;
		case 6:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else {
				delFirst();
				printf("\n Successfully Deleted");
			}
			break;
		case 7:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else {
				delLast();
				printf("\n Successfully Deleted");
			}
			break;
		case 8:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else {
				printf("\n Enter Position Number : ");
				scanf("%d", &pos);
				if (verifyPos(pos)) {
					delAtPos(pos);
					printf("\n Successfully Deleted");
				} else
					printf("\n Invalid Position");
			}
			break;
		case 9:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else {
				head=NULL;
				printf("\n Successfully Deleted");
			}
			break;
		case 10:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else {
				findById();
			}
			break;
		case 11:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else {
				findByName();
			}
			break;
		case 12:
			printf("\n Length : %d",getLength());
		}
	} while (choice != 13);
	return EXIT_SUCCESS;
}

void findById(){
	int id,check=0;
	printf("\n Enter Account Id : ");
	scanf("%d",&id);
	BANKACC* tempPtr;
	tempPtr = head;
	while (tempPtr != NULL) {
		if (tempPtr->id == id) {
			printf("\n******************************");
			printf("\n Bank Id : %d", tempPtr->id);
			printf("\n Bank Type : %s", tempPtr->type);
			printf("\n Bank Balance : %f", tempPtr->bal);
			printf("\n Bank Account Holder Details : ");
			printf("\n  Name : %s", tempPtr->accHldr.name);
			printf("\n  Address : %s", tempPtr->accHldr.addrs);
			printf("\n  Contact Details : %s", tempPtr->accHldr.cont);
			printf("\n******************************\n");
			check=1;
			break;
		}
		tempPtr = tempPtr->nextNode;
	}
	if (check == 0)
		printf("\n No Details Found");
}

void findByName(){
	char name[20];
	int check=0;
	printf("\n Enter Account Name : ");
	scanf("%s",name);
	BANKACC* tempPtr;
	tempPtr = head;
	while (tempPtr != NULL) {
		if (!(strcmp(tempPtr->accHldr.name,name))) {
			printf("\n******************************");
			printf("\n Bank Id : %d", tempPtr->id);
			printf("\n Bank Type : %s", tempPtr->type);
			printf("\n Bank Balance : %f", tempPtr->bal);
			printf("\n Bank Account Holder Details : ");
			printf("\n  Name : %s", tempPtr->accHldr.name);
			printf("\n  Address : %s", tempPtr->accHldr.addrs);
			printf("\n  Contact Details : %s", tempPtr->accHldr.cont);
			printf("\n******************************");
			check=1;
		}
		tempPtr = tempPtr->nextNode;
	}
	if(check==0)
		printf("\n No Details Found");
}

void delFirst(){
	head = head->nextNode;
}

void delLast(){
	if(getLength()==1)
		head=NULL;
	else {
		BANKACC* sndLastNode;
		sndLastNode = get2ndLastNode();
		sndLastNode->nextNode = NULL;
	}
}

void delAtPos(int pos) {
	BANKACC* tempPtr;
	tempPtr = head;
	if(pos==1){
		delFirst();
		return;
	}if(pos==getLength()){
		delLast();
	}else {
		while ((--pos) > 1) {   // this will give (position-1)th index
			tempPtr = tempPtr->nextNode;
		}
		if (pos == 1) {
			((tempPtr->nextNode)->nextNode)->PreNode = tempPtr;
			tempPtr->nextNode = (tempPtr->nextNode)->nextNode;
		}
	}
}

int isEmpty(){
	if(head==NULL)
		return 1;
	else
		return 0;
}

int getData(){
	int num;
	printf("\n Enter Number : ");
	scanf("%d",&num);
	return num;
}

BANKACC* createNode(){
	BANKACC *newNode = (BANKACC*)malloc(sizeof(BANKACC));
	printf("\nEnter Bank Id : ");
	scanf("%d",&(newNode->id));
	fflush(stdin);
	printf("\nEnter Bank Type(Saving/Current) :");
	scanf("%s",newNode->type);
	fflush(stdin);
	printf("\nEnter Balance : ");
	scanf("%f",&(newNode->bal));
	printf("\nEnter Account Holder Details : ");
	printf("\n Name : ");
	fflush(stdin);
	scanf("%[^\n]s",newNode->accHldr.name);
	printf("\n Address : ");
	fflush(stdin);
	scanf("%[^\n]s",newNode->accHldr.addrs);
	printf("\n Contact Details : ");
	fflush(stdin);
	scanf("%s",newNode->accHldr.cont);
	newNode->nextNode=NULL;
	newNode->PreNode=NULL;
	return newNode;
}

void addNodeAtFirst() {
	BANKACC* newNode;
	BANKACC* tempPtr;
	newNode = createNode();
	if (head == NULL)
		head = newNode;
	else {
		tempPtr = head;
		head = newNode;
		newNode->nextNode = tempPtr;
		tempPtr->PreNode=newNode;
	}
}
void addNodeAtLast(int num){
	BANKACC* newNode;
	BANKACC* tempPtr;
	newNode = createNode(num);
	if(head == NULL)
		head = newNode;
	else{
		tempPtr = getLastNode();
		tempPtr->nextNode = newNode;
		newNode->PreNode = tempPtr;
	}
}

int verifyPos(int pos){
	if (pos > 0 && pos <= getLength())
		return 1;
	else
		return 0;
}

void addNodeAtGivenPos(int pos){
	BANKACC* newNode;
	BANKACC* tempPtr;
	newNode=createNode();
	tempPtr = head;
		if (pos == 1) {
			addNodeAtFirst();
			return;
		}
		while ((--pos) > 1) {  // this will give (position-1)th index
			tempPtr = tempPtr->nextNode;
		}
		if (pos == 1) {
			newNode->nextNode = tempPtr->nextNode;
			tempPtr->nextNode = newNode;
			newNode->PreNode = tempPtr;

			(newNode->nextNode)->PreNode=newNode;
		}
	return;
}

int getLength() {
	BANKACC* tempPtr = head;
	int len=0;
	while (tempPtr != NULL) {
		len++;
		tempPtr = tempPtr->nextNode;
	}
	return len;
}

BANKACC* getLastNode(){
	BANKACC* tempPtr;
	tempPtr=head;
	BANKACC *lastNode;
	while(tempPtr!=NULL){
		lastNode = tempPtr;
		tempPtr = tempPtr->nextNode;
	}
	return lastNode;
}

BANKACC* get2ndLastNode(){
	BANKACC* tempPtr=head;
	BANKACC *sndLastNode=head;
		while ((tempPtr->nextNode) != NULL) {
			sndLastNode = tempPtr;
			tempPtr = tempPtr->nextNode;
		}
	return sndLastNode;
}

void displayNodesRtoL(){
	BANKACC* tempPtr;
	tempPtr=head;
	printf("\n******************************");
	while(tempPtr!=NULL){
		printf("\n Bank Id : %d",tempPtr->id);
		printf("\n Bank Type : %s",tempPtr->type);
		printf("\n Bank Balance : %f",tempPtr->bal);
		printf("\n Bank Account Holder Details : ");
		printf("\n  Name : %s",tempPtr->accHldr.name);
		printf("\n  Address : %s",tempPtr->accHldr.addrs);
		printf("\n  Contact Details : %s",tempPtr->accHldr.cont);
		printf("\n******************************\n");
		tempPtr = tempPtr->nextNode;
	}
}

void displayNodesLtoR() {
	BANKACC* tempPtr;
	tempPtr = getLastNode();
	printf("\n******************************");
	while (tempPtr != NULL) {
		printf("\n Bank Id : %d", tempPtr->id);
		printf("\n Bank Type : %s", tempPtr->type);
		printf("\n Bank Balance : %f", tempPtr->bal);
		printf("\n Bank Account Holder Details : ");
		printf("\n  Name : %s", tempPtr->accHldr.name);
		printf("\n  Address : %s", tempPtr->accHldr.addrs);
		printf("\n  Contact Details : %s", tempPtr->accHldr.cont);
		printf("\n******************************\n");
		tempPtr = tempPtr->PreNode;
	}
}
