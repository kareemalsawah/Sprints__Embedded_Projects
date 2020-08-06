#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "typedefs.h"
#include <string.h>

// Global array of current accounts
ST_accountBalance_t server_accounts[10];


void initialize_server();

// Print server data
void print_server_data();

// Check transaction validity
int check_transaction(ST_transaction_t transaction);

// Compare dates
int compare_dates(char expiration_date[5], char transaction_date[11]);
