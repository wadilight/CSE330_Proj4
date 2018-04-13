/* Code by 
David Willis: 1212719987 
Jon DiSilvestro: 
Project 4
*/

#include <stdio.h>
#include <unistd.h>
#include "sem.h"

int N = 4; //number of children
int arr['N'];

sem *par;
sem *child;
	
void func0(){
	for(int i = 0; i < N; i++){
			arr[i] = 0;
		}	
	
	for(;;){
		
		sleep(1);
					
		for(int i =0; i < N; i++){
			P(child);			
		}	
		
		for(int i =0; i < N; i++){			
			printf("\nchild %d: %d ",i+1, arr[i]); 			
		}
		
		for(int i =0; i < N; i++){			 
			V(par);
		}			
	}
}
void func1(){
	for(;;){
		printf("\n");
		
		for(int i =0; i < N; i++){
			P(par);	
			arr[i]++;
			V(child);				
		}					
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