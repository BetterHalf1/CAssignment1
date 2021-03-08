
/****************************************************************
 File: IntQueue.c
 ----------------
 This file implements the IntQueue interface given in IntQueue.h.
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "IntStack.h"


/****************************************************************
 The queue is implemented as a linked list of nodes, each
 containing an int queue entry and a pointer to the next node.
*/
struct node {
	int data;
	struct node *next;
};
typedef struct node Node;

/****************************************************************
 The state of the queue is encapsulated in this struct, which
 contains a pointer to the head and tail of the queue. The IntQueue
 ADT is a pointer to a struct of this type.
*/
struct intstack {
	Node *head;
	Node *tail;
};

/*****************************************************************/
IntStack createStack()
{

	IntStack stack = (IntStack) malloc(sizeof(struct intstack));

	if (stack == NULL) {
		printf("Out of memory!\n");
		exit(1);
	}

	stack->head = NULL;
	stack->tail = NULL;

	return stack;
}

/*****************************************************************/
int isEmpty (IntStack stack)
{
	return (stack->head == NULL) && (stack->tail == NULL);
}

/****************************************************************
 Implementation note: Each dequeue both removes the element from
 the queue and deallocates the node. The last call to free()
 deallocates the intqueue struct.
*/
void deleteStack(IntStack stack)
{

	do {
		removeStart(stack);
	} while (!isEmpty(stack));

	free(stack);
}

/****************************************************************
 Implementation note: This is a private function for creating
 an intqueue node pointer with given data contents. It's only
 here to make enqueue() a little easier to read.
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
 Implementation note: Since an empty queue just consists of a
 NULL head and tail, it is necessary to distinguish that as a
 special case. A similar comment holds for dequeue.
*/
void addStart(IntStack stack, int data)
{
	Node *node = createNode(data);
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
		printf("Attempt to print empty stack failed.\n");
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
