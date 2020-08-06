#include "server.h"

// Define default values for global array
void initialize_server(){
    srand(time(0));
    for(int i = 0; i < 10; i++){
        server_accounts[i].balance = rand()%20000;
        for(int j = 0; j < 5; j++){
            server_accounts[i].primaryAccountNumber[j] = '0' + rand()%10;
        }
        server_accounts[i].primaryAccountNumber[5] = '\0';
    }
}

void print_server_data(){
    for(int i = 0; i < 10; i++){
        printf("Account %d:\nAccount Number: %s\nBalance: %f\n\n",i,server_accounts[i].primaryAccountNumber,server_accounts[i].balance);
    }
}

int check_transaction(ST_transaction_t transaction){
    for(int i = 0; i < 10; i++){
        if(strcmp(transaction.cardHolderData.primaryAccountNumber,server_accounts[i].primaryAccountNumber) == 0){
            if(transaction.transData.transAmount > server_accounts[i].balance){
                transaction.transStat = DECLINED;
                return 1;
            }else if(compare_dates(transaction.cardHolderData.cardExpirationDate,transaction.transData.transactionDate)<0){
                transaction.transStat = DECLINED;
                return 2;
            }else if(transaction.transData.transAmount > transaction.transData.maxTransAmount) {
                transaction.transStat = DECLINED;
                return 3;
            }else{
                transaction.transStat = APPROVED;
                return 4;
            }
        }
    }
    transaction.transStat = DECLINED;
    return 0;
}

int compare_dates(char expiration_date[5], char transaction_date[11]){
    int year_diff = (expiration_date[3] - transaction_date[8])*10 + (expiration_date[4] - transaction_date[9]);
    int month_diff = (expiration_date[0] - transaction_date[3])*10 + (expiration_date[1] - transaction_date[4]);
    int total_diff = year_diff*1000 + month_diff;
    return total_diff;
}
