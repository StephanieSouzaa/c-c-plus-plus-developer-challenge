#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacoes.h"

TipoOperacao operacoes[10]; 
int num_operacoes = 0; 

void addOperation(const char *nome, Operacao operacao) 
{ 
 strcpy(operacoes[num_operacoes].nome, nome);
 operacoes[num_operacoes].funcao = operacao; 
 num_operacoes++; 
 }

 void initializeOperations() 
{
   addOperation("Somar", addValues);
   addOperation("Calcular Determinante", determinant_solver); 
}

void addValues() {
    char entrada[100];

    printf("Digite os numeros para somar, separados por virgula: ");
    scanf("%s", entrada);

    char entrada_copia[100]; 
    strcpy(entrada_copia, entrada);
    int soma = 0;

    char *token = strtok(entrada, ",");
    while (token != NULL) {
        soma += atoi(token);
        token = strtok(NULL, ",");
    }
    printf("A soma e: %d\n", soma);

    for (int i = 0; entrada_copia[i] != '\0'; i++)
    {
        if (entrada_copia[i] == ',')
        {
            entrada_copia[i] = '+';
        }
    }
    FILE *log = fopen("log.txt", "a");
    if(log == NULL){
        printf("Falha ao abrir arquiv log");
        return;
    }
    fprintf(log, "Soma: %s = %d\n", entrada_copia, soma); 
    fclose(log);
}

void determinant_solver() {
    int n = 0;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Ordem da matriz invalida!\n");
        return;
    }

    float **matriz = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (float *)malloc(n * sizeof(float));
    }

    printf("Digite os elementos da matriz (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    // Exibe a matriz
    printf("\nMatriz digitada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    // Cálculo do determinante usando eliminação de Gauss
    float det = 1;
    for (int i = 0; i < n; i++) {
        if (matriz[i][i] == 0) {
            int trocou = 0;
            for (int k = i + 1; k < n; k++) {
                if (matriz[k][i] != 0) {
                    float *temp = matriz[i];
                    matriz[i] = matriz[k];
                    matriz[k] = temp;
                    det *= -1; 
                    trocou = 1;
                    break;
                }
            }
            if (!trocou) {
                det = 0; 
                break;
            }
        }

        for (int j = i + 1; j < n; j++) {
            float fator = matriz[j][i] / matriz[i][i];
            for (int k = i; k < n; k++) {
                matriz[j][k] -= fator * matriz[i][k];
            }
        }
        det *= matriz[i][i];
    }

    printf("\nO determinante da matriz: %.2f\n", det);
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    FILE *log = fopen("log.txt", "a");
    if(log == NULL){
        printf("Falha ao abrir arquiv log");
        return;
    }
    fprintf(log, "Determinante (%dx%d): %f\n", n, n, det); 
    fclose(log);
}

void executeOperation(int operacao)
{
    if (operacao > 0 && operacao <= num_operacoes)
    {
        operacoes[operacao - 1].funcao();
    }
    else
    {
        printf("Operação inválida!\n");
    }
}