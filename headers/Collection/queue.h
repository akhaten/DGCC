/**
 * \author Jessy Khafif
 * \file queue.h
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "includes.h"


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
void queue_destruct(Queue s);


/**
 * \brief Get the size of queue
 * \param[in,out] q : queue
 * \pre (q != NULL)
 * \return size of queue
 */
int queue_size(const Queue s);


/**
 * \brief Know if the queue is empty
 * \param[in,out] q : queue
 * \pre (q != NULL)
 * \return Queue is empty ?
 */
bool queue_isEmpty(const Queue s);


/**
 * \brief Get the element from the top of queue
 * \param[in,out] q : queue
 * \pre (q != NULL) && (queue_isEmpty(q) == false)
 * \return the top element of queue
 */
void* queue_top(const Queue s);


/**
 * \brief Add element in queue
 * \param[in,out] q : queue
 * \param[in] e : generic element
 * \pre (q != NULL) && (e != NULL)
 * \return queue modified
 */
Queue queue_push(Queue s, void *e);


/**
 * \brief Remove element in queue
 * \param[in,out] q : queue
 * \pre (q != NULL) && (queue_isEmpty(q) == 0)
 * \return queue modified
 */
Queue queue_pop(Queue s);


/**
 * \brief Apply a function on elements of the queue
 * \param[in,out] q : queue
 * \param[in] f : function
 * \pre (q != NULL)
 */
void queue_map(Queue s, void* f(void *e));


/**
 * \struct QueueIterator
 * \brief Data structure for iterator of queue
 * \note The iterator is not valid if there
 * are mutations in the queue (push, pop...).
 * Use queueiterator_reset() after each mutation or
 * a set of mutations. If the queue is destroyed, the
 * queue iterator must be destroyed.
 */
typedef struct s_QueueIterator* QueueIterator;


/**
 * \brief Create a queue iterartor
 * \param[in] q : queue
 * \return an iterator on the queue
 * \pre (q != NULL)
 */
QueueIterator queueiterator_new(Queue q);


/**
 * \brief Destroy the iterator
 * \param[in,out] iter : queue iterator
 * \pre (iter != NULL)
 * \post (iter == NULL)
 */
void queueiterator_destruct(QueueIterator iter);


/**
 * \brief Reset the iterator
 * \param[in,out] iter : queue iterator
 * \return queue iterator
 * \pre (iter != NULL)
 */
QueueIterator queueiterator_reset(QueueIterator iter);


/**
 * \brief Check if there is a next element
 * \param[in,out] iter : queue iterator
 * \return true if the queue iterator can next
 * \pre (iter != NULL)
 * \warning The queue of iterator must be valid.
 */
bool queueiterator_hasnext(QueueIterator iter);


/**
 * \brief Move queue iterator to next
 * \param[in,out] iter : queue iterator
 * \return queue iterator
 * \pre (iter != NULL)
 * \warning The queue of iterator must be valid.
 */
QueueIterator queueiterator_next(QueueIterator iter);


/**
 * \brief Move queue iterator to previous
 * \param[in,out] iter : queue iterator
 * \return queue iterator
 * \pre (iter != NULL)
 * \warning The queue of iterator must be valid.
 */
QueueIterator queueiterator_previous(QueueIterator iter);


/**
 * \brief Get the value of queue iterator
 * \param[in] iter : queue iterator
 * \return the value of queue iterator
 * \pre (iter != NULL)
 * \warning The queue of iterator must be valid.
 * \note queueiterator_value(queueiterator_new(Queue q)) == NULL
 */
void *queueiterator_value(QueueIterator iter);


#endif