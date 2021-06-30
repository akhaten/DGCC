#ifndef __TYPES_H__
#define __TYPES_H__

/**
 * \include library C
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/**
 * \typedef define a generic element
 */
typedef void* GenericElement;

typedef GenericElement (*FunctionMap)(GenericElement);

typedef void (*FunctionReduce)(GenericElement, GenericElement);

typedef int (*FunctionCompare)(GenericElement, GenericElement);

typedef bool (*Predicate)(GenericElement);

typedef unsigned int Index;

#endif