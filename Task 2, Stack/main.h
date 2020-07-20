#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8_t;

/*
Stack struct contains data (dynamic array) and size of the stack
*/
struct Stack{
    uint8_t* data;
    int size;
};


/*
@desc: pushes a new element in the global variable stack declared.
Preferable to have had the function take the stack as an input as well to allow for using multiple stacks.

@param u8_data: the element to add to the global stack.
*/
void push(uint8_t u8_data);


/*
@desc: pop the last element added to the stack (returns it and removes it from the stack).
Preferable to have had the function take the stack as an input as well to allow for using multiple stacks.

@return uint8_t: the last character added to the stack
*/
uint8_t pull();


/*
@desc: prints the content of the global stack
Preferable to have had the function take the stack as an input as well to allow for using multiple stacks.
*/
void printStack();


/*
@desc: determines where a gives string has balanced parentheses or not (allowing checking '{','}','(',and')'  )

@param expression: the string to check if paraentheses are balanced

@return uint8_t*: a string saying either "Balanced" or "Not balanced".
Sould have prefered to return 1 or 0 to easily use the result in other functions
*/
uint8_t* balancedParantheses(uint8_t* expression);
