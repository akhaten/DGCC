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
#define LIST_INIT 99
#define QUEUE_INIT 98
#define ORDEREDLIST_INIT 97
#define PRIORITYQUEUE_INIT 96


#define SENTINEL_INIT 89
#define ELEMENT_INIT 88



/**
 * \typedef define a generic element
 */
typedef void* GenericElement;

#endif