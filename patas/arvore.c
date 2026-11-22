
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int altura (Noarv *raiz) {
    if (raiz == NULL){
       return 0;
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
};

Noarv *rotacaoesq(Noarv *y) {
    Noarv *x = y->direita;
    Noarv *temp = x->esquerda;
    x->esquerda= y;
    y->direita = temp;
    return x;
}

Noarv *rotacaodir(Noarv *x) {
    Noarv *y = x->esquerda;
    Noarv *temp = y->direita;
    y->direita= x;
    x->esquerda = temp;
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
Noarv *balancear(Noarv *raiz) {

    int fator = fatorbalanceamento(raiz);

    // Pesado para a esquerda
    if (fator > 1) {

        if (fatorbalanceamento(raiz->esquerda) >= 0) {
            return rotacaodir(raiz);
        }
        else {
            return rotacaoesdi(raiz);
        }
    }

    // Pesado para a direita
    if (fator < -1) {

        if (fatorbalanceamento(raiz->direita) <= 0) {
            return rotacaoesq(raiz);
        }
        else {
            return rotacaodies(raiz);
        }
    }

    return raiz;
}

Noarv *inserir(Noarv *raiz, cadastro animal) {
    if (raiz == NULL) {
        Noarv* novo = malloc(sizeof(Noarv));
        novo->animal= animal;
        novo->esquerda= NULL;
        novo->direita= NULL;

        return novo;
    }
    if (animal.idade< raiz->animal.idade) {
        raiz->esquerda = inserir(raiz->esquerda, animal);
    }
    else {
        raiz->direita = inserir(raiz->direita, animal);
    }
    //  fazer o balanceamento
    return balancear(raiz);

}


void busca(Noarv *raiz, int idade) {
    if (raiz == NULL) {
        printf("nao encontrado");
        return ;
    }
    if (idade == raiz->animal.idade) {
        apresentar_ficha(raiz->animal);

    }
    if (idade <= raiz->animal.idade) {
        busca(raiz->esquerda, idade);
    }
    if (idade >= raiz->animal.idade) {
        busca(raiz->direita, idade);
    }
}
Noarv * encontrarmenor(Noarv *raiz) {
    while (raiz->esquerda !=NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}
Noarv *removermenor(Noarv *raiz) {
    if (raiz->esquerda ==NULL) {
        Noarv* direita = raiz->direita;
        free (raiz);
        return direita;
    }
    raiz->esquerda = removermenor(raiz->esquerda);
    return raiz;
}

    Noarv *remover(Noarv *raiz, int codigo) {

        if (raiz == NULL) {
            return NULL;
        }

        if (raiz->animal.codigo == codigo) {

            // Sem filhos
            if (raiz->esquerda == NULL &&
                raiz->direita == NULL) {
                free(raiz);
                return NULL;
                }

            // Somente filho direito
            if (raiz->esquerda == NULL) {
                Noarv *auxiliar = raiz->direita;
                free(raiz);
                return auxiliar;
            }

            // Somente filho esquerdo
            if (raiz->direita == NULL) {
                Noarv *auxiliar = raiz->esquerda;
                free(raiz);
                return auxiliar;
            }

            // Dois filhos
            Noarv *menor = encontrarmenor(raiz->direita);

            raiz->animal = menor->animal;

            raiz->direita = removermenor(raiz->direita);

        }
        else {
            raiz->esquerda = remover(raiz->esquerda, codigo);
            raiz->direita = remover(raiz->direita, codigo);
        }

        return balancear(raiz);
    }