#include "main.h"

int main()
{
    stack.size = 0; // Set the default size of the stack to zero

    // Get string from user as input
    int buffer_size = 128;
    uint8_t* user_input = (char *)malloc(buffer_size*sizeof(char)); // Allocate 128 characters to get user input
    printf("Please enter the string to check to parentheses balance (less than 128 characters):\n");
    getline(&user_input,&buffer_size,stdin);

    // Call the balancedParantheses function and print the result
    uint8_t* result = balancedParantheses(user_input);
    printf("%s",result);

    // End the script
    return 0;
}

uint8_t* balancedParantheses(uint8_t* expression){
    for(int i = 0; i < strlen(expression); i++){ // Loop over all character in string expression

        if(expression[i]=='{'||expression[i]=='('){ // If an opening bracket, add it to the stack
            push(expression[i]);
        }else if(expression[i]=='}'||expression[i]==')'){ // If a closing bracket
            uint8_t last_bracket = pull(); // Get last element added to the stack
            if(last_bracket+2!=expression[i]&&last_bracket+1!=expression[i]){ // If popped bracket is not the same type as the losing bracket => return "Not balanced"
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
