#include <stdio.h>
#include "utils.h"

int main()
{
    uint32_t arr[10] = {1,2,3,9,4,3,5,8,0,1};

    uint8_t index = binarySearch(arr,10,10);

    // Not found vs found condition and print
    if(index==NULL){
        printf("Not found");
    }else{
        printf("%d", index);
    }
    return 0;
}
