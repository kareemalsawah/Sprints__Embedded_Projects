#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <stdio.h>

typedef unsigned char uint8_t;


typedef enum EN_transStat_t{
    DECLINED,
    APPROVED
}EN_transStat_t;

// Card data
typedef struct ST_cardData_t{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
}ST_cardData_t;

// Terminal data
typedef struct ST_terminalData_t{
    float transAmount;
    float maxTransAmount; // Constant 5000
    uint8_t transactionDate[11];
}ST_terminalData_t;

// Transaction data
typedef struct ST_transaction_t{
    ST_cardData_t cardHolderData;
    ST_terminalData_t transData;
    EN_transStat_t transStat;
}ST_transaction_t;

// Server account data
typedef struct ST_accountBalance_t{
    float balance;
    uint8_t primaryAccountNumber[20];
}ST_accountBalance_t;

#endif
