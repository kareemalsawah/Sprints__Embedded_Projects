#include "main.h"

struct Stack stack; // Global variable stack

int main()
{
    stack.size = 0; // Set the default size of the stack to zero

    // Get string from user as input
    int buffer_size = 128;
    uint8_t* user_input = (char *)malloc(buffer_size*sizeof(char)); // Allocate 128 characters to get user input
    printf("Please enter the string to check to parentheses balance (less than 128 characters):\n");
    getline(&user_input,&buffer_size,stdin);

    // Call the balancedParantheses function and print the result
    uint8_t* result = balancedParantheses("(srgunsirugnsrg(srgiunsirgn){{}})");
    printf("%s",result);

    // End the script
    return 0;
}


void push(uint8_t u8_data){
    uint8_t* new_stack_data = calloc(stack.size+1,sizeof(uint8_t)); // Create a new array with a size larger by 1 than the stack

    // Add the data in the stack to the created array
    for(int i = 0; i < stack.size; i++){
        new_stack_data[i] = stack.data[i];
    }

    new_stack_data[stack.size] = u8_data; // Add the new data to the new array


    free(stack.data); // Remove previous array from memory

    // Set the stack data and size
    stack.data = t;
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
        printf("Warning: Underflow occured in the stack.");
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

uint8_t* balancedParantheses(uint8_t* expression){
    for(int i = 0; i < strlen(expression); i++){ // Loop over all character in string expression

        if(expression[i]=='{'||expression[i]=='('){ // If an opening bracket, add it to the stack
            push(expression[i]);
        }else if(expression[i]=='}'||expression[i]==')'){ // If a closing bracket
            uint8_t last_bracket = pull(); // Get last element added to the stack
            if(last_bracket-2!='{'||last_bracket-1!='('){ // If popped bracket is not the same type as the losing bracket => return "Not balanced"
                return "Not balanaced";
            }
        }

    }

    if(stack.size==0){ // if stack empty after looping all characters => "Balacned"
        return "Balanced";
    }else{ // Stack size > 0 => some brackets are left unclosed => "Not balanced"
        return "Not balanced";
    }
}
