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

int global = 3;
int arr[2];

sem *par;

	
void func0(){
	for(int i = 0; i < 3; i++)
		{
		arr[i] = 0; 
		}
	
	for(;;)
	{
		printf("global: %d \n",global);		
		P(par);//wait for par
		P(par);
		P(par);
		sleep(1);
		printf("\n");
		if (global ==0)
		{
			global = 3;
			for(int i =0; i < 3; i++)
			{
				printf("child%d: %d \n",i+1, arr[i]);			
			}
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
		
			if(global == 1 && !(arr[0] > arr[1] )&& !(arr[0] > arr[2]) )
			{
				
				arr[0]++;
				
				for(int i =0; i < 3; i++)
				{
					printf("func 1 child%d: %d \n",i+1, arr[i]); 
				}
				
				global--;
				sleep(1);
			}	
		V(par);			
	}
	
}
void func2(){
	for(;;)
	{	
		P(par);
		if(global == 2 && !(arr[1] > arr[0] )&& !(arr[1] > arr[2]))
		{	
			arr[1]++;			
			for(int i =0; i < 3; i++)
			{
				printf("func 2 child%d: %d \n",i+1, arr[i]); 
			}
			
			global--;
			sleep(1);	
		}
		V(par);
	}
}
void func3(){
	for(;;)
	{	
		P(par);
		if(global == 3 && !(arr[2] > arr[1] )&& !(arr[2] > arr[0]))
		{			
			arr[2]++;
			for(int i =0; i < 3; i++)
			{
				printf("func 3 child%d: %d \n",i+1, arr[i]); 
			}
			
			global--;
			sleep(1);	
		}
		V(par);
	}
}

int main(){
	par = (struct sem*) malloc(sizeof(struct sem));
	RunQ = (struct TCB_t*) malloc(sizeof(struct TCB_t));
	RunQ = NULL;
	InitSem(par, 1);

	start_thread(func0);
	start_thread(func1);
	start_thread(func2);
	start_thread(func3);
	run();
	return 0;
	
	
	
	//return ;
}