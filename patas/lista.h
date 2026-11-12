//
// Created by jessi on 07/11/2026.
//

#ifndef PATAS_LISTA_H
#define PATAS_LISTA_H
#include "cadastro.h"

//*prox armazena o endereço do próximo nó//
typedef struct No {
    cadastro animal;
    struct No *prox;
}No;

No *inserir_ficha( No *lista, cadastro animal);
void listar_ficha(No *lista);
void remover_ficha(No **lista,int codigo);
No* buscar_ficha(No *lista, int codigo);
#endif //PATAS_LISTA_H