#include <stdio.h>
#include "hmi.h"

int menu() {
    int operation;
    printf("Escolha uma operacaoo:\n");
    printf("teste teste:\n");
    printf("1 - Soma\n");
    printf("2 - Calculo do Determinante\n");
    printf("0 - Sair\n");
    printf("Digite a opcao: ");
    scanf("%d", &operation);
    return operation;
}
