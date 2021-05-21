/**
 * \file include.h
 */

#ifndef __INCLUDES__H__
#define __INCLUDES__H__



/**
 * \include library C
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/**
 * \def error constants
 */

#define STACK_INIT 100
#define CONS_ELMT 99


#define LIST_INIT 100
#define SENTINEL_INIT 99
#define ELEMENT_INIT 98
#define LIST_ITERATOR_INIT 97


/**
 * \typedef define a generic element
 */
typedef void* GenericElement;

#endif