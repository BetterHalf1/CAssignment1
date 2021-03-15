
/****************************************************************
 File: main.c
 ------------
 Assignment 1
 Author: Kenneth Tang
 Derived from CS 170
*/

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int main(void)
{
	char myString[50];
	int myint;
	int loop = 1;
	int data;
	IntStack stack = createStack();


	while (loop == 1)
{
	printf("(i)nsert#, (p)op, (q)uit:  ");

	scanf("%s", &myString);

	if(myString[0] == 'p') {

		removeStart(stack);
		printStack(stack);



	}	else if(myString[0] == 'i'){

		int ret = sscanf(myString + 1, "%d", &data);
		if(ret == 1){
			addStart(stack, data);
			printStack(stack);
		}
		else{
			printf("Number not recognized.\n");
		}


	}
	else if(myString[0] == 'q'){
		loop = 0;
	}
	else{
		printf("Input not recognized.\n");
	}


}
	deleteStack(stack);
	printf("\n");
	exit(0);
//*********************************

}
