
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int altura (Noarv *raiz) {
    if (raiz == NULL){
       return -1;
    }
    int alturaesq =altura(raiz->esquerda);
    int alturadir = altura(raiz->direita);

    if (alturaesq > alturadir) {
        return alturaesq + 1;
    }
    else {
        return alturadir+1;
    }
};
Noarv * raiz = NULL;
int fatorbalanceamento(Noarv * raiz) {
    if (raiz == NULL) {
        return 0;
    }
        return altura(raiz->esquerda) - altura(raiz->direita);
    int fatorbalanceamento;

    if (fatorbalanceamento == -1 || fatorbalanceamento == 0|| fatorbalanceamento == 1) {
        printf ("equilibrado");
        return fatorbalanceamento ;
    }
    printf("arvore desequilibrada");
    return fatorbalanceamento;
};

Noarv *rotacaoesq(Noarv *y) {
    Noarv *x = y->esquerda;
    Noarv *temp = x->direita;
    x->direita= y;
    y->esquerda = temp;
    return x;
}
// *x
Noarv *rotacaodir(Noarv *x) {
    Noarv *y = x->direita;
    Noarv *temp = y->esquerda;
    x->esquerda= x;
    y->direita = temp;
    return y;
}
Noarv *rotacaoesdi(Noarv *raiz) {
    raiz->esquerda = rotacaoesq(raiz->esquerda);
    return rotacaodir(raiz);
}
Noarv *rotacaodies(Noarv *raiz) {
    raiz->direita = rotacaodir(raiz->direita);
    return rotacaoesq(raiz);
}
Noarv *inserir(Noarv *raiz) {

}