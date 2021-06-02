#ifndef __QUEUE_ITERATOR_H__
#define __QUEUE_ITERATOR_H__


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

#define queue_foreach(value,queue) \
for(QueueIterator iter = queueiterator_new(queue); \
(queueiterator_hasnext(iter) && (value = queueiterator_value(iter))) || queueiterator_destruct(iter); \
queueiterator_next(iter)) \

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
void *queueiterator_destruct(QueueIterator iter);


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