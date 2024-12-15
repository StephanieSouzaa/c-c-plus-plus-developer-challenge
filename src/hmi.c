#include <stdio.h>
#include "hmi.h" 
#include "operacoes.h"   

extern TipoOperacao operacoes[]; 
extern int num_operacoes;

int menu() {
    int operation;
    printf("Escolha uma operacao:\n");
    for (int i = 0; i < num_operacoes; i++) 
    { 
    printf("%d - %s\n", i + 1, operacoes[i].nome);
    }
    //printf("1 - Soma\n");
   // printf("2 - Calculo do Determinante\n");
    printf("0 - Sair\n");
    printf("Digite a opcao: ");
    if (scanf("%d", &operation) != 1){
    printf("Entrada inválida!\n");
    while (getchar() != '\n');
    return -1;
    }
    return operation;
}
