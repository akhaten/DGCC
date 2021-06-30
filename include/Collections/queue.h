/**
 * \author Jessy Khafif
 * \file queue.h
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__


#include "types.h"


/**
 * \struct Queue
 * \brief Data structure for Lifo In First Out (LIFO)
 */
typedef struct s_Queue* Queue;

/**
 * \brief Create new queue
 * \post queue_isEmpty(queue_new()) == true
 * \return queue
 */
Queue queue_new(void);


/**
 * \brief Delete the queue
 * \param[in,out] q : queue
 * \pre (q != NULL)
 * \post (q == NULL)
 */
GenericElement queue_destruct(Queue q);


/**
 * \brief Get the size of queue
 * \param[in,out] q : queue
 * \pre (q != NULL)
 * \return size of queue
 */
unsigned int queue_size(const Queue q);


/**
 * \brief Know if the queue is empty
 * \param[in,out] q : queue
 * \pre (q != NULL)
 * \return Queue is empty ?
 */
bool queue_isEmpty(const Queue q);


/**
 * \brief Get the element from the top of queue
 * \param[in,out] q : queue
 * \pre (q != NULL) && (queue_isEmpty(q) == false)
 * \return the top element of queue
 */
GenericElement queue_top(const Queue q);


/**
 * \brief Add element in queue
 * \param[in,out] q : queue
 * \param[in] e : generic element
 * \pre (q != NULL) && (e != NULL)
 * \return queue modified
 */
Queue queue_push(Queue q, const GenericElement e);


/**
 * \brief Remove element in queue
 * \param[in,out] q : queue
 * \pre (q != NULL) && (queue_isEmpty(q) == 0)
 * \return queue modified
 */
Queue queue_pop(Queue q);


/**
 * \brief Apply a function on elements of the queue
 * \param[in,out] q : queue
 * \param[in] f : function
 * \pre (q != NULL)
 */
void queue_map(Queue q, FunctionMap f);


#endif