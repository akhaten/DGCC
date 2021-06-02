/**
 * \author Jessy Khafif
 * \file stack.h
 */

#ifndef __STACK_H__
#define __STACK_H__

#include "includes.h"


/**
 * \struct Stack
 * \brief Data structure for First In First Out (FIFO)
 */
typedef struct s_Stack *Stack;



/**
 * \brief Create new stack
 * \post stack_isEmpty(stack_new()) == true
 * \return stack
 */
Stack stack_new(void);


/**
 * \brief Delete the stack
 * \param[in,out] s : stack
 * \pre (s != NULL)
 * \post (s == NULL)
 */
void stack_destruct(Stack s);


/**
 * \brief Get the size of stack
 * \param[in,out] s : stack
 * \pre (s != NULL)
 * \return size of stack
 */
int stack_size(const Stack s);


/**
 * \brief Know if the stack is empty
 * \param[in,out] s : stack
 * \pre (s != NULL)
 * \return Stack is empty ?
 */
bool stack_isEmpty(const Stack s);


/**
 * \brief Get the element from the top of stack
 * \param[in,out] s : stack
 * \pre (s != NULL) && (stack_isEmpty(s) == 0)
 * \return the top element of stack
 */
void* stack_top(const Stack s);


/**
 * \brief Add element in stack
 * \param[in,out] s : stack
 * \param[in] e : generic element
 * \pre (s != NULL) && (e != NULL)
 * \return stack modified
 */
Stack stack_push(Stack s, void *e);


/**
 * \brief Remove element in stack
 * \param[in,out] s : stack
 * \pre (s != NULL) && (stack_isEmpty(s) == 0)
 * \return stack modified
 */
Stack stack_pop(Stack s);


/**
 * \brief Apply the function f on elements of the stack
 * \param[in,out] s : stack
 * \param[in] f : function
 * \pre (s != NULL)
 */
void stack_map(Stack s, void* f(void *e));


#endif