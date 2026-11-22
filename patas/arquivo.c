//
// Created by jessi on 22/11/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"


void salvar_arquivo(No *lista) {

    FILE *arquivo = fopen("../dados/animais.txt", "w");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            return;
        }

        while (lista != NULL) {

            cadastro animal = lista->animal;

            fprintf(arquivo, "%d;%s;%s;%s;%d;%s;%s;%s;%s;%s;%s\n",
                    animal.codigo,
                    animal.especie,
                    animal.nome,
                    animal.raca,
                    animal.idade,
                    animal.sexo,
                    animal.porte,
                    animal.vacinado,
                    animal.castrado,
                    animal.personalidade,
                    animal.foto);

            lista = lista->prox;
        }

        fclose(arquivo);

        printf("Cadastros salvos com sucesso!\n");
    }

void carregar_arquivo(No **lista, Noarv **raiz) {

    FILE *arquivo = fopen("../dados/animais.txt", "r");

        if (arquivo == NULL) {
            printf("Nenhum arquivo de cadastro encontrado.\n");
            return;
        }

        cadastro animal;

        while (fscanf(arquivo,
                      "%d;%19[^;];%29[^;];%29[^;];%d;%19[^;];%19[^;];%9[^;];%9[^;];%59[^;];%29[^\n]\n",
                      &animal.codigo,
                      animal.especie,
                      animal.nome,
                      animal.raca,
                      &animal.idade,
                      animal.sexo,
                      animal.porte,
                      animal.vacinado,
                      animal.castrado,
                      animal.personalidade,
                      animal.foto) == 11) {

            *lista = inserir_ficha(*lista, animal);

            *raiz = inserir(*raiz, animal);
                      }

        fclose(arquivo);

        printf("Cadastros carregados com sucesso!\n");

 }
