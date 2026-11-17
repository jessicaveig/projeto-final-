
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
    x->direita= x;
    y->esquerda = temp;
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
    //  Verificar o balanceamento
    int fator = fatorbalanceamento(raiz);


    //  rotação à direita
    if (fator > 1 &&
        animal.idade < raiz->esquerda->animal.idade) {
        return rotacaodir(raiz);
        }


    //  rotação à esquerda
    if (fator < -1 &&
        animal.idade >= raiz->direita->animal.idade) {
        return rotacaoesq(raiz);
        }


    // rotação dupla esquerda-direita
    if (fator > 1 &&
        animal.idade >= raiz->esquerda->animal.idade) {
        return rotacaoesdi(raiz);
        }


    //  rotação dupla direita-esquerda
    if (fator < -1 &&
        animal.idade < raiz->direita->animal.idade) {
        return rotacaodies(raiz);
        }

    return raiz;
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
Noarv *buscacodigo(Noarv *raiz, int codigo) {
    if (raiz == NULL) {
        return NULL;
    }
    if (codigo == raiz->animal.codigo) {
        return raiz ;
    }
    Noarv *encontrado = buscacodigo(raiz->esquerda, codigo);
    if (encontrado != NULL) {
        return encontrado;
    }
    else{
        return buscacodigo(raiz->direita, codigo);
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
    // encontrou o animal
    if (raiz->animal.codigo == codigo) {

        // sem filhos
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }
        // somente 1 filho
        if (raiz->esquerda == NULL) {
            Noarv* auxiliar = raiz->direita;
            free (raiz);
            return auxiliar;
        }
        if (raiz->direita == NULL) {
            Noarv* auxiliar = raiz->esquerda;
            free (raiz);
            return auxiliar;
        }
        // 2 filhos
        Noarv* menor = encontrarmenor(raiz->direita);
        raiz->animal =  menor->animal;
        raiz->direita = removermenor(raiz->direita);
        return raiz;
    }
    // procura na esquerda
    raiz->esquerda = remover(raiz->esquerda, codigo);
    // procura na direita
    raiz->direita = remover(raiz->direita, codigo);
    return raiz;

}