
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// inserir novo cadastro //
No *inserir_ficha(No *lista, cadastro animal) {
    // No* retorna um novo valor para o nó//
    // *lista indica o endereço do primeiro no da lista //
    // *novo guarda o endereço do novo nó//
    // todos os novos animais são inciados no começo da fila //

    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("erro ao alocar a memoria");
        return lista;
    }
    novo->animal=animal;
    novo->prox= lista;
    return novo;

}
// listar cada cadastro //
void listar_ficha(No *lista ) {
    No *atual = lista;
    while (atual != NULL) {
        apresentar_ficha(atual->animal);
        atual= atual->prox;
    }
};
// remover cadastro caso o animal seja adotado //
void remover_ficha(No **lista, int codigo) {
    if (*lista ==NULL) {
        printf("animal nao encontrado");
        return;
    }
    No *atual =*lista;
    No *anterior = NULL;

    while (atual != NULL && atual->animal.codigo != codigo ) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual  ==NULL) {
        printf("animal não encontrado\n");
        return;
    }
    // começo da lista //
    if (anterior ==  NULL) {
        *lista = atual->prox ;
    }
    // meio ou final da lista //
    // o anterior aponta para o próximo da fila ignorando o excluído//
    else {
        anterior->prox = atual->prox;
    }
    free(atual);
}
    No * buscar_ficha(No* lista , int codigo) {
    No *atual = lista;
    while (atual != NULL){
        if (atual->animal.codigo == codigo) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
};

