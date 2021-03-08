
/****************************************************************
 File: main.c
 ------------
 A main program to demonstrate the IntQueue ADT.
 It enqueues the numbers 0 through 99 and then dequeues
 them.
*/

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int main(void)
{
	char ch;
	printf("Enter 'p' to print, 'q' to quit: ");
	int ret = scanf("%c", &ch);
	if (ch == 'q'){
		printf("Quitting program\n");
		exit(0);
	}/*
	if (ret = 1) {
		printf("You entered %c\n", ch);
	}
	*/
	int i;
	int data;
	IntStack stack = createStack();

	for (i=0; i<5; i++) {
		data = i;
		printf("Adding to stack, %d\n", data);
		addStart(stack, data);

		printStack(stack);

	}

	if (!isEmpty(stack))
	{
		while (!isEmpty(stack))
		{
			data = removeStart(stack);
			printf("Popped %d\n", data);
			printStack(stack);
		}
	}
	else
		printf("Stack is empty.\n");

	deleteStack(stack);

	return 0;
}
