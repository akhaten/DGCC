/**
 * \author Jessy Khafif
 * \file queue.h
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__


#include "includes.h"

/**
 * \section Queue
 */

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
 * \param[in,out] s : queue
 * \pre (s != NULL)
 * \post (s == NULL)
 */
void queue_destruct(Queue s);

/**
 * \brief Get the size of queue
 * \param[in,out] s : queue
 * \pre (s != NULL)
 * \return size of queue
 */
int queue_size(const Queue s);

/**
 * \brief Know if the queue is empty
 * \param[in,out] s : queue
 * \pre (s != NULL)
 * \return Queue is empty ?
 */
bool queue_isEmpty(const Queue s);

/**
 * \brief Get the element from the top of queue
 * \param[in,out] s : queue
 * \pre (s != NULL) && (queue_isEmpty(s) == 0)
 * \return the top element of queue
 */
void* queue_top(const Queue s);


/**
 * \brief Add element in queue
 * \param[in,out] s : queue
 * \param[in] e : generic element
 * \pre (s != NULL) && (e != NULL)
 * \return queue modified
 */
Queue queue_push(Queue s, void *e);

/**
 * \brief Remove element in queue
 * \param[in,out] s : queue
 * \pre (s != NULL) && (queue_isEmpty(s) == 0)
 * \return queue modified
 */
Queue queue_pop(Queue s);

/**
 * \brief Apply the function f on elements of the queue
 * \param[in,out] s : queue
 * \param[in] f : function
 * \pre (s != NULL)
 */
void queue_map(Queue s, void* f(void *e));

#endif