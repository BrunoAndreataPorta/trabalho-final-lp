#include <stdio.h>
#include "controleEstoqueRoupas.h"

p_vestuario v[MAX];

int main() {
    inicializar();
    int id = 0;
    int opcao = 0;
    int pos = 0;
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
                printf("Informe o ID do produto que deseja alterar o estoque:\n");
                scanf("%d", &pos);
                atualizarEstoque(pos);
                break;
            case 3:
                listarItens(id);
                break;
            case 4:
                printf("Deseja procurar itens de qual categoria?\n");
                scanf("%s", categoria);
                listarPorCategoria(categoria, id);
                break;
            case 5:
                printf("Informe o ID do produto que deseja alterar as informacoes:\n");
                scanf("%d", &pos);
                alterarProduto(pos);
                break;
            default:
                printf("Opcao invalida\n\n");
        }
    }while(opcao != 0);
}