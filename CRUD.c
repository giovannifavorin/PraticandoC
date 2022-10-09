#include<stdio.h>
#include<stdlib.h>

typedef struct Cad{
    int idade;
} Cad;

typedef struct no{
    int dados;
    struct no *next;
} no;

int inserirNo(no **lista, int cadastro){
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    if (novoNo == NULL)//valida se houve erro na criaçao da struct
        return 0;

    novoNo->dados = cadastro;
    novoNo->next = NULL;//inicializa a struct

    if (*lista == NULL){//valida se é a primeira posicao ou n
        *lista = novoNo;
    } else{
        struct no *ultimo = *lista;// por seguranca, use uma copia para percorrer a lista, evitar danos a integridade do codigo
        while (ultimo->next != NULL){//percorre o codigo até achar o ultimo no
            ultimo = ultimo->next;
        }
        ultimo->next = novoNo;//quando acha, insere o valor
    }
    return 1;
}

void imprimir(no **comeco){
    struct no *noAtual = *comeco;
    while (noAtual != NULL){
        printf("ID: %d\n", noAtual->dados);
        noAtual = noAtual->next;
    }
    
}

int main(){
    struct no *ponteiro = NULL;
    inserirNo(&ponteiro, 1);
    inserirNo(&ponteiro, 2);
    inserirNo(&ponteiro, 3);
    imprimir(&ponteiro);
    return 0;
}