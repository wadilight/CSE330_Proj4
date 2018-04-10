#ifndef THREADS_H_   
#define THREADS_H_

#include "q.h"

TCB_t *RunQ = NULL;

void printPID(TCB_t *thread);


void start_thread(void (*function)(void))
{ 
	//allocate a stack (via malloc) of a certain size (choose 8192)
	void *stack_ptr = malloc(8192);
	// allocate a TCB (via malloc)
	TCB_t *thread = (struct TCB_t*)malloc(sizeof(struct TCB_t));
	//call init_TCB with appropriate arguments
	init_TCB (thread, function, stack_ptr, 8192);
	//initialize the thread_ID
	thread->thread_id = global_thread_id;
	//call addQ to add this TCB into the “RunQ” which is a global header pointer
	AddQueue(&RunQ, thread);
	printPID(thread);
}

void run()
{   // real code
    TCB_t* Curr_Thread = RunQ;
    ucontext_t parent;     // get a place to store the main context, for faking
    getcontext(&parent);   // magic sauce
    swapcontext(&parent, &(Curr_Thread->context));  // start the first thread
}

void yield() // similar to run
{ 
   TCB_t *Prev_Thread = RunQ;
   RotateQ(&RunQ);
   TCB_t *Curr_Thread = RunQ;
   swapcontext(&(Prev_Thread->context), &(Curr_Thread->context)); //swap the context, from Prev_Thread to the thread pointed to Curr_Thread
}

void printPID(TCB_t *thread){

	printf("ID initialized: %d \n", thread->thread_id);


}

#endif 
