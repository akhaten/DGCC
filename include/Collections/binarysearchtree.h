#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__


#include "types.h"


typedef struct s_BSTree* BSTree;

/**
 * \brief Create a new binary seach tree
 * \param[in] fcmp : a function to compare elements
 * \return a binary search tree
 * \post bstree_isEmpty(bstree_new(_)) == true
 */
BSTree bstree_new(FunctionCompare fcmp);

/**
 * \brief Destroy a binary search tree
 * \param[in,out] bst : a binary search tree
 * \pre (bst != NULL)
 * \post (bst == NULL)
 */
void bstree_destroy(BSTree bst);

/**
 * \brief Know if a binary search tree is empty
 * \param[in] bst : binary search tree
 * \return true if it is empty, else false 
 * \pre (bst != NULL)
 */
bool bstree_isEmpty(const BSTree bst);

/**
 * Add a value in binary search tree
 * \param[in,out] bst   : binary search tree
 * \param[in] value : generic element
 * \pre (bst != NULL) && (value != NULL)
 */
void bstree_add(BSTree bst, const GenericElement value);

/**
 * Know if an element is in the binary search tree
 * \param[in] bst   : binary search tree
 * \param[in] value : generic element
 * \return true if it is in binary search tree, else false 
 * \pre (bst != NULL) && (value != NULL)
 */
bool bstree_search(const BSTree bst, const GenericElement value);



#endif