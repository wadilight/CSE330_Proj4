/* Code by 
David Willis: 1212719987 
Jon DiSilvestro: 
Project 4
*/

#include <stdio.h>
#include <unistd.h>
#include "sem.h"


/*
1.       The main (parent) thread initializes 
an array of 3 integers to zero.

2.       The parent creates 3 children. Child
 i adds 1 to array[i], where i = 0, 1, 2. Order 
 not important.

3.       The parent waits for the children to 
finish adding, and then prints the values in 
the array.

4.       The children wait for the parent to 
finish printing and then repeats (adds 1 to 
an element of the array)

5.       Continues forever
*/


int N = 8;
int arr['N'];

sem *par;
sem *child;

	
void func0(){
	for(int i = 0; i < N; i++)
		{
		arr[i] = 0;
		}
	
	for(;;)
	{	
		sleep(1);
					
		for(int i =0; i < N; i++)
		{
			P(child);
			
		}	
		for(int i =0; i < N; i++)
		{
			
			printf("child %d: %d \n",i+1, arr[i]); 
			
		}	
		for(int i =0; i < N; i++)
		{
			 
			V(par);
		}			
	}
}
void func1(){
	for(;;)
	{
			for(int i =0; i < N; i++)
			{
				P(par);	
				arr[i]++;
				V(child);				
			}
			printf("\n"); 
						
	}
	
}
int main(){
	par = (struct sem*) malloc(sizeof(struct sem));
	child = (struct sem*) malloc(sizeof(struct sem));
	RunQ = (struct TCB_t*) malloc(sizeof(struct TCB_t));
	RunQ = NULL;
	InitSem(par, N);
	InitSem(child, N);
	start_thread(func0);
	start_thread(func1);
	run();
	return 0;
}