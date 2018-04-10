/* Code by 
David Willis: 1212719987 
Jon DiSilvestro: 
Project 3
*/

#include <stdio.h>
#include <unistd.h>
#include "sem.h"

int global = 0;
	sem *x;


void func1()
{

	int local = 0;	
	for(;;)
	{
		P(x);
		sleep(1);
		printf("    %d      |            |    %d\n", local, global);
		local++;
		global++;
		V(x);				
	}
}

void func2()
{
	int local = 0;

	for(;;)
	{
		P(x);
		sleep(1);
		printf("	   |	%d	|    %d\n", local, global);
		local++;
		global++;
		V(x);		 
	}
}


int main()
{
	x = (struct sem*) malloc(sizeof(struct sem));
	RunQ = (struct TCB_t*) malloc(sizeof(struct TCB_t));
	RunQ = NULL;
	InitSem(x, 1);
	start_thread(func1);
	start_thread(func2);
	printf("Thread one:");
	printf("  Thread two:");
	printf("  Global:\n");
	run(); 
	return 0;
}
