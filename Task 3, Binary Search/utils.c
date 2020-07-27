#include "utils.h"

uint8_t binarySearch(uint32_t *arr, uint8_t size, uint32_t number){
    // Sort array and get indices to get the position in the original unsorted array
    uint32_t *indices_arr = bubble_sort(arr,size);

    uint8_t low = 0, top = size-1, mid;

    while(top >= low){
        mid = (low+top)/2; // Mid index

        if(arr[mid]==number){
            uint8_t to_return = indices_arr[mid]; // Found number, get its index in the original unsorted array
            free(indices_arr); // Free memory from indices array
            return to_return; // Return result
        }

        // Change upper or lower bounds for search
        if(arr[mid]>number){
            top = mid-1;
        }else{
            low = mid+1;
        }

    }
    return NULL; // Didn't find the number in the array
}

uint32_t* bubble_sort(uint32_t *arr, uint8_t size){
    // Allocate an array that will have the indices of the sorted elements (to get locations of unsorted array later)
    uint32_t *indices_arr = (uint32_t*)calloc(size,sizeof(uint32_t));

    // Initialize indices array
    for(uint32_t i = 0; i < size; i++){
        indices_arr[i] = i;
    }

    // Bubble sort
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-1-i; j++){
            if(arr[j] > arr[j+1]){ // Left larger than right element => swap them
                swap(&arr[j],&arr[j+1]);
                swap(&indices_arr[j],&indices_arr[j+1]);
            }
        }
    }
    re
    turn indices_arr;
}

void swap(uint32_t *element1, uint32_t *element2){
    uint32_t temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

void print_array(uint32_t *arr, uint8_t size){
    printf("{");
    for(int i = 0; i < size-1; i++){
        printf("%d, ",arr[i]);
    }
    printf("%d}\n",arr[size-1]);
}
