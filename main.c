#include <stdio.h>
#include <string.h>
#include "controleEstoqueRoupas.h"

p_vestuario v[MAX];

int main() {
    inicializar();
    int id = 0;
    int opcao = 0;
    int pos = 0;
    int repeticao = 0;
    char categoria[30] = "";

    do{
        printf(" -- MENU PRINCIPAL --\n");
        printf("1 - Cadastrar novo produto\n");
        printf("2 - Atualizar estoque de um produto\n");
        printf("3 - Listar todos os itens\n");
        printf("4 - Listar todos os itens de uma categoria especifica\n");
        printf("5 - Alterar informacoes de um produto\n");
        printf("0 - SAIR\n");
        printf("Digite sua opcao:\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 0:
                printf("Fim do programa");
                break;
            case 1:
                adicionarNovoItem(id);
                id++;
                break;
            case 2:
                if (id == 0){
                    printf("Nenhum produto foi cadastrado ainda.\n");
                    printf("Cadastre algum item antes!\n\n");
                }else{
                    printf("Informe o ID do produto que deseja atualizar o estoque:\n");
                    scanf("%d", &pos);
                    atualizarEstoque(pos);
                }
                break;
            case 3:
                if (id == 0){
                    printf("Nenhum item foi cadastrado ainda.\n");
                    printf("Cadastre algum item antes!\n\n");
                }else{
                    listarItens(id);
                }
                break;
            case 4:
                printf("Deseja procurar qual das categorias de item?\n");
                if(id == 0){
                    printf("Nenhuma categoria cadastrada ainda.\n");
                    printf("Cadastre algum item antes!\n\n");
                    break;
                }else{
                    for(int i = 0; i<id; i++){
                        repeticao = 0;
                        if(i == 0){
                            printf("%s\n", v[i]->categoria);
                        }else{
                            for(int x = 0; x<i; x++){
                                if (strcmp(v[i]->categoria, v[x]->categoria) == 0){
                                    repeticao = 1;
                                    break;
                                }else{
                                    repeticao = 0;
                                }
                            }
                            if(repeticao == 0){
                                printf("%s\n", v[i]->categoria);
                            }
                        }
                    }
                    printf("\n");
                }
                scanf("%s", categoria);
                listarPorCategoria(categoria, id);
                break;
            case 5:
                if (id == 0){
                    printf("Nenhum produto foi cadastrado ainda.\n");
                    printf("Cadastre algum item antes!\n\n");
                }else{
                    printf("Informe o ID do produto que deseja alterar as informacoes:\n");
                    scanf("%d", &pos);
                    alterarProduto(pos);
                }
                break;
            default:
                printf("Opcao invalida\n\n");
        }
    }while(opcao != 0);
}