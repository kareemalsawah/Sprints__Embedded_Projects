#include "terminal.h"

int check_date_format(char *to_check, char* format){
    if(strlen(to_check)!=strlen(format)){
        return 0;
    }

    for(int i = 0; i < strlen(format); i++){
        if(format[i]=='/'&&to_check[i]!='/'){
            return 0;
        }
    }
    return 1;
}

ST_cardData_t getCardData(){
    ST_cardData_t card_data;

    printf("Please Enter Card Data:\n");
    printf("Please Enter the Card Holder Name:\n");
    scanf(" %[^\n]%*c",&card_data.cardHolderName);

    printf("Please Enter the Primary Account Number:\n");
    scanf("%s",&card_data.primaryAccountNumber);

    printf("Please card Expiry Date (MM/YY):\n");
    int correct_format;
    do{
        scanf("%s",&card_data.cardExpirationDate);
        correct_format = check_date_format(card_data.cardExpirationDate,"MM/YY");
        if(correct_format!=1){
            printf("Please enter the date in the correct format (MM/YY):\n");
        }
    }while(correct_format!=1);

    return card_data;
}

ST_terminalData_t getTerminalData(){
    ST_terminalData_t terminal_data;

    printf("Please Enter Terminal Data:\n");
    printf("Please Enter the transaction Amount:\n");
    scanf(" %f",&terminal_data.transAmount);

    printf("Please Enter transaction Date (DD/MM/YYYY):\n");

    int correct_format;
    do{
        scanf("%s",&terminal_data.transactionDate);
        correct_format = check_date_format(terminal_data.transactionDate,"DD/MM/YYYY");
        if(correct_format!=1){
            printf("Please enter the date in the correct format (DD/MM/YYYY):\n");
        }
    }while(correct_format!=1);
    terminal_data.maxTransAmount = max_transaction_amount;
    return terminal_data;
}

ST_transaction_t getTransactionData(){
    ST_transaction_t transaction;
    transaction.cardHolderData = getCardData();
    transaction.transData = getTerminalData();

    return transaction;
}
