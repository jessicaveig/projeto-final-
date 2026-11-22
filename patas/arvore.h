//
// Created by jessi on 11/11/2026.
//

#ifndef PATAS_ARVORE_H
#define PATAS_ARVORE_H

#endif //PATAS_ARVORE_H
#include "cadastro.h"

typedef struct Noarv {
    cadastro animal;
    struct Noarv *esquerda;
    struct Noarv *direita;
    int altura;
}Noarv;

int altura(Noarv *raiz);
int fatorbalanceamento(Noarv *raiz);
Noarv *rotacaodir(Noarv *raiz);
Noarv *rotacaoesq(Noarv *raiz);
Noarv *rotacaoesdi(Noarv *raiz);
Noarv *rotacaodies(Noarv *raiz);
Noarv *balancear(Noarv *raiz);
Noarv *inserir(Noarv *raiz, cadastro animal);
void busca(Noarv *raiz,int idade);
Noarv *removermenor(Noarv *raiz);
Noarv *encontrarmenor(Noarv *raiz);
Noarv *remover(Noarv *raiz, int codigo);