#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"
#include "hmi.h"

int main() {
    initializeOperations();
    int operation;
    while (1) {

        operation = menu();

        if (operation == 0)
        {
         break;
        }
        executeOperation(operation);
    }
    return 0;
}

