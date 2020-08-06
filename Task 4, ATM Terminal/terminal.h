#include <stdio.h>
#include "typedefs.h"
#include <string.h>

static float max_transaction_amount = 5000.0;

int check_date_format(char *to_check, char* format);

ST_cardData_t getCardData();

ST_terminalData_t getTerminalData();

ST_transaction_t getTransactionData();
