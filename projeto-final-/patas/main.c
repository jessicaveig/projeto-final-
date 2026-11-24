#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"
#include "cadastro.h"
#include "lista.h"
#include "arvore.h"

int main(void) {
    Noarv *raiz = NULL;
    No *lista = NULL;
    carregar_arquivo(&lista,&raiz);
    cadastro animal;
    int codigo;
    int opcao;
    int idade;



    do {
        printf("\n ================MENU=====================\n");
        printf("1 - ==========cadastrar animal =============\n");
        printf("2- ===========apresentar animais ===========\n");
        printf("3- ======buscar animal pelo codigo==========\n");
        printf("4- ============remover animal===============\n");
        printf("5- ========buscar animal pela idade ========\n");
        printf("0- sair\n");
        printf("digite sua opcao:\n ");
        scanf("%d", &opcao);


        // cadastro do animal
        switch (opcao) {
            case 0: {
                break;
            }
            case 1: {
                animal = cadastrar_ficha();
                lista = inserir_ficha(lista, animal);
                // apresentação da ficha
                apresentar_ficha(animal);
                // inserir na arvore
               raiz = inserir(raiz, animal);
                // salvar arquivo
                salvar_arquivo(lista);

                break;
            }

            case 2:
                // apresentar os animais cadastrados
                listar_ficha(lista);
                break;

            case 3:

                // buscar o endereço de uma ficha
                printf("digite o codigo que voce procura:\n");
                scanf("%d", &codigo);
                No* encontrado= buscar_ficha(lista, codigo);

                if (encontrado !=NULL) {
                    listar_ficha(encontrado);
                }
                else {
                    printf("animal não encontrado!\n");
                }
                break;

            case 4:
                // remover animal
                printf("digite o codigo que voce quer remover:\n");
                scanf("%d", &codigo);
                remover_ficha(&lista,codigo);
                // remover da arvore
                raiz = remover(raiz,codigo);
                salvar_arquivo(lista);
                break;

            case 5:
                printf("digite  a idade que voce procura:\n");
                scanf("%d", &idade);
                busca(raiz,idade);
                break;

            default:
                printf("opcao invalida!\n");
        }

    } while (opcao!=0);

    return 0;
}


