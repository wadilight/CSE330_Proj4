#ifndef Q_H_   
#define Q_H_

#include <stdio.h>
#include <stdlib.h>
#include "tcb.h"  

//---New Queue points to head---//
TCB_t *newQueue(){
	TCB_t *head = NULL;

return head;	
}

//---New Queue item that allocates memory---//
TCB_t *NewItem(){ 

	TCB_t *item = (struct TCB_t*)malloc(sizeof(struct TCB_t));
	item->next = NULL;
	item->prev = NULL;

return item;
}

//---Adds Queue item to Queue head---//
void AddQueue(TCB_t **head, TCB_t *item){

	if ((*head) != NULL) {
		if ((*head)->next == NULL) {
			// Queue has one element 
			(*head)->prev = item; 
			(*head)->next = item; 
			item->prev = (*head); 
			item->next = (*head); 
		}
		else {

			// Queue has more than one elment
			item->prev = (*head)->prev; 
			item->next = (*head);
			(*head)->prev->next = item; 
			(*head)->prev = item; 
		}
	} 
	else {
		// Queue is empty
		(*head) = item; 
	}
	
	return;
}

//---Deletes from head Queue then returns pointer---//
TCB_t *DelQueue(TCB_t **head){ 

	struct TCB_t *del = *head;

	// Check if queue is empty
	if (head != NULL) {
		if ((*head)->next == NULL) {
			//Queue has one elment
			*head = NULL;
		}
		else {
		//Queue has more than one element
			(*head)->prev->next = (*head)->next;
			(*head)->next->prev = (*head)->prev;

			*head = (*head)->next;
		}
	}
	
	return del;
}

//---Rotates the Queue around head---//
void RotateQ(TCB_t **head){

	//TA reccomended this change
	AddQueue(head, DelQueue(head));
	//(*head) = (*head)->prev; //omg that worked LOL

}
/*
void print(TCB_t **head){

	if((*head) == NULL){
		printf(" \n");
	}
	else{
	TCB_t *temp = (*head);

	while(temp->next != (*head)){
	
		printf("%d ", temp->data);
		temp = temp->next;
		
	}
	printf("%d \n",temp->data);
}
}*/

#endif 
