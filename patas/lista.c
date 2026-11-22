
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// inserir novo cadastro //
No *inserir_ficha(No *lista, cadastro animal) {

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

    No *atual =*lista;
    No *anterior = NULL;

    while (atual != NULL) {
        if (atual->animal.codigo == codigo) {
            if (anterior == NULL) {
                *lista = atual->prox;
            }
            else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("animal  removido\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("animal nao encontrado\n");

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

