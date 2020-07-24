#include "stack.h"

void push(uint8_t u8_data){
    uint8_t* new_stack_data = calloc(stack.size+1,sizeof(uint8_t)); // Create a new array with a size larger by 1 than the stack

    // Add the data in the stack to the created array
    for(int i = 0; i < stack.size; i++){
        new_stack_data[i] = stack.data[i];
    }

    new_stack_data[stack.size] = u8_data; // Add the new data to the new array


    free(stack.data); // Remove previous array from memory

    // Set the stack data and size
    stack.data = new_stack_data;
    stack.size++;
}

uint8_t pull(){
    if(stack.size > 0){ // Stack contains at least one element
        uint8_t to_return = stack.data[--stack.size];

        // Free memory from the popped element
        uint8_t* new_stack_data = realloc(stack.data, stack.size * sizeof(uint8_t));
        stack.data = new_stack_data;

        return to_return;

    }else{ // Stack is empty
        printf("Warning: Underflow occured in the stack.\n");
        return 0;
    }
}

void printStack(){
    printf("Printing Stack:\n");

    for(int i = 0; i < stack.size; i++){ // Loop over all elements
        printf("%c, ", stack.data[i]); // Print each element
    }

    printf("\n");
}
