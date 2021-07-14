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
 * \typedef define a generic element type
 */
typedef void* GenericElement;


/**
 * \typedef a map function type
 */
typedef GenericElement (*FunctionMap)(GenericElement);


/**
 * \typedef reduce function type
 */
typedef void (*FunctionReduce)(GenericElement, GenericElement);


/**
 * \typedef denfine a function to compare two generic elements e1 and e2 
 * \return
 * e1 == e2 -> (= 0) \
 * e1 < e2  -> (< 0) \
 * e1 > e2  -> (> 0) \
 */
typedef int (*FunctionCompare)(const void*, const void*);


/**
 * \typedef predicate function type
 * \return true if the predicate is checked, else false
 */
typedef bool (*Predicate)(GenericElement);


#endif