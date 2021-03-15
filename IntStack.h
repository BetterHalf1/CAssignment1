
/****************************************************************
 File: IntStack.h
 Derived from IntQueue.h
 ----------------
 This is an interface for a creating a stack of integers.
 Supports popping and pushing integers.
 ****************************************************************/

#ifndef UTILS_INTSTACK
#define UTILS_INTSTACK

/****************************************************************
 Type: IntStack
 --------------
 Declaration of an IntStack object takes the form,

   IntStack s;
 */
 typedef struct intstack *IntStack;


/****************************************************************
 Function: createStack()
 -----------------------
 Creates a new stack and returns it.

 Example usages:
   IntStack s1;
   s1 = createStack();

   IntStack s2 = createStack();
 */
 IntStack createStack(void);


/****************************************************************
 Function: isEmpty(IntStack)
 ---------------------------
 Returns true if the argument is the empty stack, false otherwise.

 Example usage, given the IntStack variable q:

   if (!isEmpty(q))
     printf("This is not an empty stack.\n");
 */
 int isEmpty (IntStack stack);


/****************************************************************
 Function: deleteStack(IntStack)
 -------------------------------
 Destroys the stack given as argument. Always call this after
 an IntStack s is no longer needed, as:

    deleteQueue(s);
 */
 void deleteStack(IntStack stack);

/****************************************************************
 Function: addStart(IntStack, int)
 --------------------------------
  Pushes the second argument in the first. The int is put at the
 start of the stack.

 Example usage, given IntStack variable s:

    addStart(s, 2);

 pushes the number 2 at the beginning of the stack s.
 */
 void addStart(IntStack stack, int data);

/****************************************************************
 Function: removeStart(IntStack)
 ---------------------------
 Removes the item at the front of the queue and returns its value.

 Example usage, given IntStack variable s and int variable front:

     front = removeStart(s);


 */
 int removeStart(IntStack stack);

/****************************************************************
 Function: printQueue(IntQueue)
 ------------------------------
 Prints the contents of the stack at the console, starting with
 the front and going to the rear. There is a space between each
 number, and all appear on one line.
 */
void printStack (IntStack stack);

#endif
