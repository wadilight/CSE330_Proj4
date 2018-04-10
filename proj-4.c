/* Code by 
David Willis: 1212719987 
Jon DiSilvestro: 
Project 3
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
int main(){
	
	
}