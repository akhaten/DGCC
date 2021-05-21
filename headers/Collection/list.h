/**
 * \author Jessy Khafif
 * \file list.h
 */

#ifndef __LIST_H__
#define __LIST_H__

#include "includes.h"

/**
 * \struct List
 * \brief Data structure for collection of element
 * \note 0 is the first element
 */
typedef struct s_List* List;

/**
 * \brief Create a list empty
 * \return a list
 * \post (list_new() != NULL) && (list_isEmpty(list_new()) == 1)
 */
List list_new(void);

/**
 * \brief Destruct the list
 * \param[in,out] l : a list
 * \pre (l != NULL)
 * \post (l == NULL)
 */
void list_destruct(List l);

/**
 * \brief Get the size of the list
 * \param[in] l : list
 * \return the lenght of list
 * \pre (l != NULL)
 */
unsigned int list_size(const List l);

/**
 * \brief Know if a list is empty
 * \param[in] l : list
 * \return list_isEmpty(l) == 1 
 * \pre (l != NULL)
 */
bool list_isEmpty(const List l);

/**
 * \brief Add an element in the list
 * \param[in,out] l : list
 * \param[in] e : generic element
 * \return list modified
 * \pre (l != NULL) and (e != NULL) 
 */
List list_add(List l, void *e);

/**
 * \brief Remove element from the list
 * \param[in,out] l : list
 * \param[in] index : index of element
 * \return list modified
 * \pre (l != NULL) && (index < list_size(l))
 */
List list_remove(List l, const unsigned int index);

/**
 * \brief Insert an element at index in list.
 * \note list_add(l,e) <=> list_insert(l,list_size(l),e)
 * \param[in,out] l : list
 * \param[in] index : position
 * \param[in] e : generic element
 * \return list modified
 * \pre (l != NULL) && (e != NULL) && (index < list_size(l))
 */
List list_insert(List l, const unsigned int index, void *e);

/**
 * \brief Obtain element at index from list
 * \param[in] l : list
 * \param[in] index : position
 * \return : element
 * \pre (l != NULL) && (!list_isEmpty(l)) && (index < list_size(l))
 */
void *list_get(const List l, const unsigned int index);

/**
 * \brief Apply the function f on the list
 * \param[in,out] l : list
 * \param[in] f : function applied on the elements
 * \return list modified by f
 * \pre (l != NULL)
 */
List list_map(List l, void* f(void *e));

/**
 * \brief Create a view/sublist with a list
 * \param[in] l : list
 * \param[in] index1 : the first position
 * \param[in] index2 : the second position
 * \return the sublist
 * \pre (l != NULL) && (0 <= index1) && (index1 <= index2) && (index2 < list_size(l))
 */
List list_sublist(const List l, const unsigned int index1, const unsigned int index2);

/**
 * \brief Check if it exists an element checking a predicate
 * \param[in] l : list
 * \param[in] predicate : predicate returning 0 if false
 * \return 0 if it doesn't exist an element e such as predicate(e) == 0
 */
bool list_exists(const List l, bool predicate(void *e));

/**
 * \brief Check if all elements check the predicat
 * \param[in] l : list
 * \param[in] predicate : predicate returning 0 if false
 * \return 0 if it exists an element e such as predicate(e) == 0
 */
bool list_forall(const List l, bool predicate(void *e));

/**
 * \brief Copy a list
 * \param[in] l : list
 * \return list copied
 */
List list_copy(List l);

#endif


