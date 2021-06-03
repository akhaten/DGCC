/**
 * \author Jessy Khafif
 * \file stackiterator.h
 */

#ifndef __STACK_ITERATOR_H__
#define __STACK_ITERATOR_H__


/**
 * \struct StackIterator
 * \brief Data structure for iterator of stack
 * \note The iterator is not valid if there
 * are mutations in the stack (push, pop...).
 * Use stackiterator_reset() after each mutation or
 * a set of mutations. If the stack is destroyed, the
 * stack iterator must be destroyed.
 */
typedef struct s_StackIterator* StackIterator;

#define stack_foreach(value,stack) \
for(StackIterator iter = stackiterator_new(stack); \
(stackiterator_hasnext(iter) && (value = stackiterator_value(iter))) || stackiterator_destruct(iter); \
stackiterator_next(iter)) \

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
 * \return NULL
 * \pre (iter != NULL)
 * \post (iter == NULL)
 */
void *stackiterator_destruct(StackIterator iter);


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