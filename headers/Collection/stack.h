/**
 * \author Jessy Khafif
 * \file stack.h
 */

#ifndef __STACK_H__
#define __STACK_H__

#include "includes.h"

/**
 * \section Stack
 */

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

/**
 * \struct Stack
 * \brief Data structure for iterator of stack
 * \note The iterator is not valid if there
 * are mutations in the stack (push, pop...).
 * Use stackiterator_reset() after each mutation or
 * a set of mutations. If the stack is destroyed, the
 * stack iterator must be destroyed.
 */
typedef struct s_StackIterator* StackIterator;

/**
 * \brief Create a stack iterartor
 * \param[in] s : stack
 * \return an iterator on the stack
 * \pre (s != NULL)
 */
StackIterator stackiterator_new(Stack s);

/**
 * \brief Destroy the iterator
 * \param[in,out] iter : stack iterator
 * \pre (iter != NULL)
 * \post (iter == NULL)
 */
void stackiterator_destruct(StackIterator iter);

/**
 * \brief Reset the iterator
 * \param[in,out] iter : stack iterator
 * \return stack iterator
 * \pre (iter != NULL)
 */
StackIterator stackiterator_reset(StackIterator iter);

/**
 * \brief Check if there is a next element
 * \param[in,out] iter : stack iterator
 * \return true if the stack iterator can next
 * \pre (iter != NULL)
 * \warning The stack of iterator must be valid.
 */
bool stackiterator_hasnext(StackIterator iter);

/**
 * \brief Move stack iterator to next
 * \param[in,out] iter : stack iterator
 * \return stack iterator
 * \pre (iter != NULL)
 * \warning The stack of iterator must be valid.
 */
StackIterator stackiterator_next(StackIterator iter);

/**
 * \brief Move stack iterator to previous
 * \param[in,out] iter : stack iterator
 * \return stack iterator
 * \pre (iter != NULL)
 * \warning The stack of iterator must be valid.
 */
StackIterator stackiterator_previous(StackIterator iter);

/**
 * \brief Get the value of stack iterator
 * \param[in] iter : stack iterator
 * \return the value of stack iterator
 * \pre (iter != NULL)
 * \warning The stack of iterator must be valid.
 * \note stackiterator_value(stackiterator_new(Stack s)) == NULL
 */
void *stackiterator_value(StackIterator iter);

#endif
