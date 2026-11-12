//
// Created by jessi on 11/11/2026.
//

#ifndef PATAS_ARVORE_H
#define PATAS_ARVORE_H

#endif //PATAS_ARVORE_H
#include "cadastro.h"

typedef struct No {
    cadastro animal;
    struct No *esquerda;
    struct No *direita;
    int altura;
}No;