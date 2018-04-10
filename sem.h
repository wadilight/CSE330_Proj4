#ifndef SEM_H_   
#define SEM_H_

#include "threads.h"  

typedef struct sem {

	struct TCB_t *semq;
	int val;
} sem;

void InitSem(sem* x, int value){

	x->semq = (struct TCB_t*) malloc(sizeof(struct TCB_t));
	x->semq = NULL;
	x->val = value;
}

void P(sem* x){

	(x->val)--;
	if(x->val < 0){
	 //pseudo code:
	//(Curr_thread get added to semaphore queue and a new thread is selected 	//from ReadyQ and put in Curr_Thread – and then swapcontext.)

	TCB_t* Curr_Thread = DelQueue(&RunQ);
	AddQueue(&(x->semq), Curr_Thread);
	swapcontext(&(Curr_Thread->context), &(RunQ->context));
	}
}

void V(sem *x){

	(x->val)++;

	if(x->val <= 0){
	  //pseudo code:
	 //takes a PCB out of the semaphore queue and puts it into the ReadyQ queue. 
	//Note: The V routine also "yields" to the next runnable thread.
	AddQueue(&RunQ, DelQueue(&(x->semq)));
	}
	yield();
}

#endif 
