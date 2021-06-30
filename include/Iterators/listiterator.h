/**
 * \author Jessy Khafif
 * \file listiterator.h
 */

#ifndef __LIST_ITERATOR_H__
#define __LIST_ITERATOR_H__


/**
 * \struct ListIterator
 * \brief Data structure for iterator of list
 * \note The iterator is not valid if there
 * are mutations in the list (add, remove...).
 * Use listiterator_reset() after each mutation or
 * a set of mutations. If the list is destroyed, the
 * list iterator must be destroyed.
 */
typedef struct s_ListIterator* ListIterator;

#define list_foreach(value,list) \
for(ListIterator iter = listiterator_new(list); \
(listiterator_hasnext(iter) && (value = listiterator_value(iter))) || listiterator_destruct(iter); \
listiterator_next(iter)) \

/**
 * \brief Create a list iterartor
 * \param[in] l : list
 * \return an iterator on the list
 * \pre (l != NULL)
 */
ListIterator listiterator_new(const List l);


/**
 * \brief Destroy the iterator
 * \param[in,out] iter : list iterator
 * \return NULL
 * \pre (iter != NULL)
 * \post (iter == NULL)
 */
void *listiterator_destruct(ListIterator iter);


/**
 * \brief Reset the iterator
 * \param[in,out] iter : list iterator
 * \return list iterator
 * \pre (iter != NULL)
 */
ListIterator listiterator_reset(ListIterator iter);


/**
 * \brief Check if there is a next element
 * \param[in,out] iter : list iterator
 * \return true if the list iterator can next
 * \pre (iter != NULL)
 * \warning The list of iterator must be valid.
 */
bool listiterator_hasnext(const ListIterator iter);


/**
 * \brief Move list iterator to next
 * \param[in,out] iter : list iterator
 * \return list iterator
 * \pre (iter != NULL)
 * \warning The list of iterator must be valid.
 */
ListIterator listiterator_next(ListIterator iter);


/**
 * \brief Move list iterator to previous
 * \param[in,out] iter : list iterator
 * \return list iterator
 * \pre (iter != NULL)
 * \warning The list of iterator must be valid.
 */
ListIterator listiterator_previous(ListIterator iter);


/**
 * \brief Get the value of list iterator
 * \param[in] iter : list iterator
 * \return the value of list iterator
 * \pre (iter != NULL)
 * \warning The list of iterator must be valid.
 * \note listiterator_value(listiterator_new(List l)) == NULL
 */
void *listiterator_value(const ListIterator iter);

#endif