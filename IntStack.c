
/****************************************************************
 File: IntStack.c
 Derived from IntQueue.c
 ----------------
 This file implements the IntStack interface given in IntStack.h.
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "IntStack.h"


/****************************************************************
 Stack implemented as nodes derived from IntQueue
*/
struct node {
	int data;
	struct node *next;
};
typedef struct node Node;

/****************************************************************
 The state of the stack is encapsulated in this struct, which
 contains a pointer to the head and tail of the queue. firstEmpty is
 used to avoid repetitive print statements for when stack is empty.
*/
struct intstack {
	Node *head;
	Node *tail;
	int firstEmpty;
};

/****************************************************************
	Initializes Stack
	*/

IntStack createStack()
{

	IntStack stack = (IntStack) malloc(sizeof(struct intstack));

	if (stack == NULL) {
		printf("Out of memory!\n");
		exit(1);
	}

	stack->head = NULL;
	stack->tail = NULL;
	stack->firstEmpty = 1;

	return stack;
}

/****************************************************************
	Returns true if stack is empty, false otherwise.
*/
int isEmpty (IntStack stack)
{
	return (stack->head == NULL) && (stack->tail == NULL);
}

/****************************************************************
 Implementation note: Each pops the first element in a stack
  and deallocates the node. The last call to free()
 deallocates the intStack.
*/
void deleteStack(IntStack stack)
{
	stack->firstEmpty = 2;
	do {
		removeStart(stack);
	} while (!isEmpty(stack));

	free(stack);
}

/****************************************************************
 Implementation note: This is a private function for creating
 an intStack node pointer with given data contents.
*/
static Node *createNode(int data)
{
	Node *node = (Node *) malloc(sizeof(Node));

	if (node == NULL) {
		printf("Out of memory!\n");
		exit(1);
	}

	node->data = data;
	node->next = NULL;

	return node;
}

/****************************************************************
 Implementation note: Since an empty stack just consists of a
 NULL head and tail, it is necessary to distinguish that as a
 special case.
*/
void addStart(IntStack stack, int data)
{
	Node *node = createNode(data);

	stack->firstEmpty = 1;

	if (!isEmpty(stack)) {
		node->next = stack->head;
		stack->head = node;
	}
	else {
		stack->head = node;
		stack->tail = node;
	}


}

/*****************************************************************/
int removeStart(IntStack stack)
{
	Node *temp;
	int data;

	if (stack->head == NULL) {
		// Queue is empty
		if (stack->firstEmpty == 2){
			return 0;
		}
		printf("pop from empty stack failed.\n");

		return 0;
	}
	else {
		temp = stack->head;
		stack->head = stack->head->next;

		if (stack->head == NULL) {
			stack->tail = NULL;
		}

		data = temp->data;
		free(temp);
		return data;
	}
}

/*****************************************************************/
void printStack (IntStack stack)
{
	Node *current;

	if (isEmpty(stack)) {
		if(stack->firstEmpty == 1){
		printf("Empty stack.\n");
		stack->firstEmpty = 0;
	}

		return;
	}

	current = stack->head;

	printf("%d  ", current->data);
	while (current != stack->tail) {
		current = current->next;
		printf("%d  ", current->data);
	}
	printf("\n");
}
