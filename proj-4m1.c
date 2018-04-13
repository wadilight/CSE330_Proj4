/* Code by 
David Willis: 1212719987 
Jon DiSilvestro: 
Project 4
*/

#include <stdio.h>
#include <unistd.h>
#include "sem.h"

int arr[2];

sem *par;
sem *child;

	
void func0(){
	for(int i = 0; i < 3; i++)
		{
		arr[i] = 0;
		printf("child%d: %d \n",i+1, arr[i]);
		}
	
	for(;;)
	{		
		P(child);
		P(child);
		P(child);
		
		sleep(1);
		printf("\n");			
		for(int i =0; i < 3; i++)
		{
			printf("child%d: %d \n",i+1, arr[i]); 
		}	
		V(par);	
		V(par);	
		V(par);		
	}
}
void func1(){
	for(;;)
	{	
			P(par);
			arr[0]++;
			V(child);		
	}
	
}
void func2(){
	for(;;)
	{	
			P(par);
			arr[1]++;
			V(child);
	}
}
void func3(){
	for(;;)
	{
			P(par);
			arr[2]++;
			V(child);
	}
}

int main(){
	par = (struct sem*) malloc(sizeof(struct sem));
	child = (struct sem*) malloc(sizeof(struct sem));
	RunQ = (struct TCB_t*) malloc(sizeof(struct TCB_t));
	RunQ = NULL;
	InitSem(par, 3);
	InitSem(child, 1);
	start_thread(func0);
	start_thread(func1);
	start_thread(func2);
	start_thread(func3);
	run();
	return 0;
	
	
	
	//return ;
}