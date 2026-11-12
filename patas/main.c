#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"
#include "lista.h"


int main(void) {
    int codigo;
    No *lista = NULL;
    cadastro animal;
    int opcao;

    do {
        printf("\n ================MENU=====================\n");
        printf("1 - ==========cadastrar animal =============\n");
        printf("2- ===========apresentar animais ===========\n");
        printf("3- ============buscar animal ===============\n");
        printf("4- ============remover animal===============\n");
        printf("0- sair\n");
        printf("digite sua opcao:\n ");
        scanf("%d", &opcao);


        // cadastro do animal
        switch (opcao) {
            case 1: {
                animal = cadastrar_ficha();
                lista = inserir_ficha(lista, animal);
                // apresentação da ficha
                apresentar_ficha(animal);

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
                printf("digite o codigo que voce quer remover\n:");
                scanf("%d", &codigo);
                remover_ficha(&lista,codigo);
                break;


            default:
                printf("opcao invalida!\n");
        }

    } while (opcao!=0);

    return 0;
}