/**
 * \file list.h
 */

#ifndef __LIST_H__
#define __LIST_H__

/**
 * \typedef data structure of a list
 * \note 0 is the first element
 */
typedef struct s_List* List;
//typedef struct s_ListIterator* ListIterator;

/**
 * \brief Create a list empty
 * \return a list l 
 * \post list_isEmpty(l) == 1
 */
List list_new(void);

/**
 * \brief Destruct the list
 * \pre l != NULL
 * \param[in,out] l : a list
 * \post l == NULL
 */
void list_destruct(List l);

/**
 * \brief Get the lenght of the list
 * \pre l != NULL
 * \param[in] l : list
 * \return the lenght of list
 */
unsigned int list_size(const List l);

/**
 * \brief List is empty ?
 * \pre l != NULL
 * \param[in] l : list
 * \return list_isEmpty(l) == 1 
 */
int list_isEmpty(const List l);

/**
 * \brief Add an element in the list
 * \pre (l != NULL) and (e != NULL) 
 * \param[in,out] l : list
 * \param[in] e : generic element
 * \return list modified
 */
List list_add(List l, void *e);

/**
 * \brief Remove element from the list
 * \pre (l != NULL) && (index < list_size(l))
 * \param[in,out] l : list
 * \param[in] index : index of element
 * \return list modified
 */
List list_remove(List l, const unsigned int index);

/**
 * \brief Insert an element at index in list.
 * \note list_add(l,e) <=> list_insert(l,list_size(l),e)
 * \pre (l != NULL) && (e != NULL) && index < list_size(l)
 * \param[in,out] l : list
 * \param[in] index : position
 * \param[in] e : generic element
 * \return list modified
 */
List list_insert(List l, const unsigned int index, void *e);

/**
 * \brief Obtain element at index from list
 * \pre (l != NULL) && (e != NULL) && (index <= list_size(l))
 * \param[in] l : list
 * \param[in] index : position
 * \return : element
 */
void *list_get(const List l, const unsigned int index);

/**
 * \brief Apply the function f on the list
 * \pre l != NULL
 * \param[in,out] l : list
 * \param[in] f : function aaplied on the elements
 * \return list modified by f
 */
List list_map(List l, void* f(void *e));

/**
 * \brief Create a view/sublist with a list
 * \pre (l != NULL) && (0 <= index1) && (index1 <= index2) && (index2 < list_size(l))
 * \param[in] l : list
 * \param[in] index1 : the first position
 * \param[in] index2 : the second position
 * \return the sublist
 */
List list_sublist(const List l, const unsigned int index1, const unsigned int index2);

/**
 * \brief Check if it exists an element checking a predicate
 * \param[in] l : list
 * \param[in] predicate : predicate returning 0 if false
 * \return 0 if it doesn't exist an element e such as predicate(e) == 0
 */
int list_exists(const List l, int predicate(void *e));

/**
 * \brief Check if all elements check the predicat
 * \param[in] l : list
 * \param[in] predicate : predicate returning 0 if false
 * \return 0 if it exists an element e such as predicate(e) == 0
 */
int list_forall(const List l, int predicate(void *e));

/*List list_reverse(List l);
List list_copy(List l);*/

/**
 * ITERATOR
 */

/*



ListIterator list_iterator(const List list);

int list_iter_hasnext(const ListIterator iter);

void *list_iter_value(const ListIterator iter);

ListIterator list_iter_next(ListIterator iter);

ListIterator list_iter_previous(ListIterator iter);

*/
#endif


