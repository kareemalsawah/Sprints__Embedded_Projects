#include <stdio.h>
#include "typedefs.h"

/*
@desc: Perform binary search for an element in an array including sorting if needed

@param: uint32_t *arr, the array to search in
@param: uint8_t size, size of the array to search in
@param: uint32_t number, the value to search for

@return: uint8_t, index of the value if found and NULL if not found
*/
int binarySearch(uint32_t *arr, uint8_t size, uint32_t number);

/*
@desc: Sort a given array from the smallest to largest values using bubble sort

@param: uint32_t *arr, the array to sort
@param: uint8_t size, size of the array to sort

@return: uint32_t*, an indices array to shows the indices of the sorted elements in the original unsorted array (argsort)
*/
uint32_t* bubble_sort(uint32_t *arr, uint8_t size);

/*
@desc: Swap two elements in memory

@param: uint32_t *element1, pointer to first element
@param: uint32_t *element2, pointer to second element
*/
void swap(uint32_t *element1, uint32_t *element2);

/*
@desc: prints an array for debugging purposes

@param: uint32_t *arr, the array to print
@param: uint8_t size, size of the array to print
*/
void print_array(uint32_t *arr, uint8_t size);
