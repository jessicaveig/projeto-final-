//
// Created by jessi on 07/11/2026.
//

#ifndef PATAS_CADASTRO_H
#define PATAS_CADASTRO_H

typedef struct  cadastro {
    int codigo;
    char especie [20];
    char nome[30];
    char raca [30];int idade;
    char sexo[20];
    char porte[20];
    char vacinado [10];
    char castrado [10];
    char personalidade [60];
    char foto[30];

}cadastro;

cadastro cadastrar_ficha(void);
void  apresentar_ficha(cadastro animal);

#endif //PATAS_CADASTRO_H