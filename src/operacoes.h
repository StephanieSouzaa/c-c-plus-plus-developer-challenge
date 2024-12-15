#ifndef OPERACOES_H 
#define OPERACOES_H 

typedef void (*Operacao)(void); 

typedef struct TipoOperacao { 
char nome[50]; 
Operacao funcao;
} TipoOperacao; 

void addValues();
void determinant_solver();
void executeOperation(int operation);
void addOperation(const char *nome, Operacao operacao);
void initializeOperations(); 
void executeOperation(int operacao); 

#endif