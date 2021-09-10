/**
 * \author Jessy Khafif
 * \file array.h
 */


#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "types.h"


/**
 * \struct Array
 * \brief Data structure for collection of element
 * \note 0 is the first element
 */
typedef struct s_Array* Array;


/**
 * \brief Create a new array
 * \return an array empty
 * \post (array_isEmpty(array_new()) == true)
 */
Array array_new(void);


/**
 * \brief Destroy an array
 * \param[in,out] a : an array
 * \pre (a != NULL)
 */
void array_destruct(Array a);


/**
 * \brief Check if an array is empty
 * \param[in] a : an array
 * \return true if array is empty, else false
 * \pre (a != NULL)
 */
bool array_isEmpty(const Array a);


/**
 * \brief Get the size of an array
 * \param[in] a : an array
 * \return the size of array
 * \pre (a != NULL)
 */
unsigned int array_size(const Array a);


/**
 * \brief Add a genneric element in an array (to end)
 * \param[in,out] a : array
 * \param[in] e : generic element
 * \return the array with the new element
 * \pre (a != NULL) && (e != NULL)
 */
Array array_add(Array a, const GenericElement e);


/**
 * \brief Insert a generic element in array
 * \param[in,out] a : array
 * \param[in] index : position of insertion
 * \param[in] e : generic element
 * \return the array with the new element
 * \pre (a != NULL) && (index < array_size(a)) && (e != NULL)
 */
Array array_insert(Array a, const unsigned int index, const GenericElement e);


/**
 * \brief Remove an element in array
 * \param[in,out] a : array
 * \param[in] index : position of element
 * \return the array modified
 * \pre (a != NULL) && (index < array_size(a))
 */
Array array_remove(Array a, const unsigned int index);


/**
 * \brief Get the element in array with an index
 * \param[in] a : array
 * \param[in] index : position of element
 * \return the element
 * \pre (a != NULL) && (index < array_size(a))
 */
GenericElement array_get(const Array a, const unsigned int index);


/**
 * \brief Apply a map function on the elements of array
 * \param[in] a : array
 * \param[in] f : function applied
 * \return the array modified
 * \pre (a != NULL)
 */
Array array_map(Array a, FunctionMap f);


GenericElement array_reduce(Array a, FunctionReduce f, GenericElement data);


/**
 * \brief Check if it exists an element checking the predicate
 * \param[in] a : array
 * \param[in] predicate : predicate returning 0 if false
 * \return 0 if it doesn't exist an element e such as predicate(e) == 0
 */
bool array_exist(const Array a, Predicate p);


/**
 * \brief Check if all elements check the predicate
 * \param[in] a : array
 * \param[in] predicate : predicate returning 0 if false
 * \return 0 if it exists an element e such as predicate(e) == 0
 */
bool array_forall(const Array a, Predicate p);


#endif