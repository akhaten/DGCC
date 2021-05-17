#ifndef __STACK_H__
#define __STACK_H__

typedef struct s_Stack *Stack;

/**
 * @file stack.h
 */

/**
 * Create new stack
 * @return stack empty
 */
Stack stack_new(void);

/**
 * Add element in stack
 * @param s : the stack
 * @param e : generic element
 * @return stack modified
 */
Stack stack_push(Stack s, void *e);

/**
 * Remove element in stack
 * @param s : stack
 * @return : stack modified
 */
Stack stack_pop(Stack s);

/**
 * @param s : stack
 * @return the top element of stack
 */
void* stack_top(const Stack s);

/**
 * @param s : stack
 * @return size of stack
 */
int stack_size(const Stack s);

/**
 * @param s : stack
 * @return Stack is empty ?
 */
int stack_isEmpty(const Stack s);

/**
 * Delete the stack
 * @param s : stack
 */
void stack_destruct(Stack s);

/**
 * Apply the function f on the stack
 * @param s : stack
 * @param f : function
 */
void stack_map(Stack s, void* f(void *));


#endif
