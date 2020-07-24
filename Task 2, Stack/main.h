#include "stack.h"

/*
@desc: determines where a gives string has balanced parentheses or not (allowing checking '{','}','(',and')'  )

@param expression: the string to check if paraentheses are balanced

@return uint8_t*: a string saying either "Balanced" or "Not balanced".
Sould have prefered to return 1 or 0 to easily use the result in other functions
*/
uint8_t* balancedParantheses(uint8_t* expression);
