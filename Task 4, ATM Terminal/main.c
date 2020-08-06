#include <stdio.h>
#include "server.h"
#include "terminal.h"


int main()
{
    initialize_server();
    print_server_data();

    while(1){
        ST_transaction_t transaction_data = getTransactionData();

        printf("Verifying Data from the server...\n");


        int result = check_transaction(transaction_data);
        if(result==0){
            printf("Declined! Primary Card Number not found!\n");
        }else if(result==1){
            printf("Declined! Balance not enough!\n");
        }else if(result==2){
            printf("Declined! Card has expired!\n");
        }else if(result==3){
            printf("Declined! Transaction exceeded maximum allowed value!\n");
        }else{
            printf("Accepted!\n");
        }



        printf("Do you want to continue (y/n)?\n");
        char is_continue;
        scanf(" %c",&is_continue);
        if(is_continue!='y'){
            break;
        }
    }
    return 0;
}
