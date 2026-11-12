//
// Created by jessi on 07/11/2026
#include <stdio.h>
#include "cadastro.h"
#include <stdio.h>

cadastrar_ficha (void) {
    cadastro animal;

    printf ("novo animal\n ");

    printf(" Codigo:\n");
    scanf("%d",&animal.codigo);


    printf("especie:\n");
    scanf("%s",animal.especie);


    printf("nome: \n");
    scanf("%s",animal.nome);


    printf("raca:\n");
    scanf("%s",animal.raca);


    printf("idade: \n");
    scanf("%s",&animal.idade);


    printf("sexo: \n");
    scanf("%s",animal.sexo);


    printf("porte:\n");
    scanf("%s",animal.porte);


    printf("vacinado: \n");
    scanf(" %s",animal.vacinado);


    printf("castrado: \n");
    scanf(" %s",animal.castrado);


    printf("personalidade: \n");
    scanf(" %s",animal.personalidade);


    printf("caminho da foto: \n");
    scanf(" %s",animal.foto);


    printf("cadastro realizado com sucesso!\n");


    return animal;
};
    void apresentar_ficha (cadastro animal) {
      printf("\n========= CADASTRO DO ANIMAL ===========\n");

    printf("codigo: %d\n",animal.codigo);
    printf("especie: %s\n",animal.especie);
    printf("nome: %s\n",animal.nome);
    printf("raca: %s\n",animal.raca);
    printf("idade: %d\n",animal.idade);
    printf("sexo: %s\n",animal.sexo);
    printf("porte: %s\n",animal.porte);
    printf("vacinado: %s\n",animal.vacinado);
    printf("castrado: %s\n",animal.castrado);
    printf("personalidade: %s\n",animal.personalidade);
    printf(" foto: %s\n",animal.foto);

    printf("============================================");
    };
