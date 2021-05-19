#ifndef __STACK_H__
#define __STACK_H__

typedef struct s_Stack *Stack;

/**
 * \file stack.h
 */

/**
 * \brief Create new stack
 * \return stack empty
 */
Stack stack_new(void);

/**
 * \brief Add element in stack
 * \param[in,out] s : stack
 * \param[in] e : generic element
 * \return stack modified
 */
Stack stack_push(Stack s, void *e);

/**
 * \brief Remove element in stack
 * \param[in,out] s : stack
 * \return stack modified
 */
Stack stack_pop(Stack s);

/**
 * \param[in,out] s : stack
 * \return the top element of stack
 */
void* stack_top(const Stack s);

/**
 * \param[in,out] s : stack
 * \return size of stack
 */
int stack_size(const Stack s);

/**
 * \param[in,out] s : stack
 * \return Stack is empty ?
 */
int stack_isEmpty(const Stack s);

/**
 * \brief Delete the stack
 * \param[in,out] s : stack
 */
void stack_destruct(Stack s);

/**
 * \brief Apply the function f on the stack
 * \param[in,out] s : stack
 * \param[in] f : function
 */
void stack_map(Stack s, void* f(void *e));


#endif
