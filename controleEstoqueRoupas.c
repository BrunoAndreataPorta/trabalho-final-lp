#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "controleEstoqueRoupas.h"

void inicializar(){
    for (int i=0; i < MAX; i++){
        v[i] = NULL;
    }
}

void listarUnicoItem(int id){
    printf("ID [%d] - Categoria: %s\n", v[id]->id, v[id]->categoria);
    printf("Descricao: %s\n", v[id]->descricao);
    printf("Tamanho: %c\n", v[id]->tamanho);
    printf("Total de itens: %d\n", v[id]->quantidade);
}

void registrarTamanhoRoupa(int id){
    int tam;
        //Loop para garantir que o tamanho informado está correto
    do{
        char resposta[10] = ""; //Char usado para verificar se a resposta do usúario é númerica
        printf("Informe o tamanho:\n");
        printf("Digite 1 - [P]\n");
        printf("Digite 2 - [M]\n");
        printf("Digite 3 - [G]\n");
        scanf("%s", resposta);
        fflush(stdin);
        //Convertendo a string para um número inteiro
        tam = atoi(resposta);

        if (tam == 1){
            v[id]->tamanho = 'P';
        }else if(tam == 2){
            v[id]->tamanho = 'M';
        }else if(tam == 3){
            v[id]->tamanho = 'G';
        }else{
            printf("\nTamanho invalido\n");
            printf("Tente novamente\n\n");
            tam = 0;
        }
    }while(tam == 0);
}

void adicionarNovoItem(int id){
    if (v[id]==NULL){
        int qtd = -1;
        char resposta[10] = "";
        /**
         * Alocando mémoria de maneira dinâmica para um novo struct no array 'v'
         */
        v[id] =  (p_vestuario)malloc(sizeof(vestuario));

        v[id]->id = id;

        fflush(stdin);
        printf("Informe a categoria do produto:\n");
        gets(v[id]->categoria);

        //Loop para verificar se valor informado para quantidade de roupas é valido
        do{
            fflush(stdin);
            printf("Informe a quantidade de roupas: \n");
            scanf("%s", resposta);

            for (int i = 0; resposta[i] != '\0'; i++) {
                if (!isdigit(resposta[i])) {
                    strcpy(resposta, ""); //limpando o conteudo
                    break;
                }else{
                    qtd = atoi(resposta);
                }
            }

            if(qtd >= 0){
                v[id]->quantidade = qtd;
            }else{
                printf("Valor informado invalido!\n");
                printf("Tente novamente\n\n");
                qtd = -1;
            }
        }while(qtd < 0);

        registrarTamanhoRoupa(id);

        fflush(stdin);
        printf("Informe a descricao: \n");
        gets(v[id]->descricao);
    }
    printf("Produto cadastrado com sucesso\n\n");
}

void atualizarEstoque(int pos){
    char resposta[10] = "";
    int newQtd;
    char *fimResp; //Ponteiro para o ultimo caractere após a conversão com strtol
    if (v[pos] == NULL){
        printf("Nao existe nenhum produto cadastrado nesse ID\n\n");
    }else {
        listarUnicoItem(pos);
        printf("Digite o novo total de itens do produto ou algum numero negativo para cancelar a acao:\n");
        scanf("%s", &resposta);

        //Convertendo a resposta para inteiro
        newQtd = strtol(resposta, &fimResp, 10);

        if (*fimResp != '\0' && *fimResp != '\n') {
            //Caso o usuario tenha escrito letras a resposta não é valida
            printf("Entrada invalida. Acao cancelada.\n\n");
        }else if (newQtd >= 0){
            v[pos]->quantidade = newQtd;
            printf("Valor atualizado com sucesso!\n\n");
        }else if(newQtd < 0){
            printf("Acao cancelada.\n\n");
        }
    }
}

void listarItens(int id){
    for(int i = 0; i < id; i++){
        if (v[i] != NULL){
            listarUnicoItem(i);
            printf("\n");
        }
    }
}

void listarPorCategoria(char categoria[30], int id){
    int buscar = 0;
    printf("Resultado da busca:\n");
    for(int i = 0; i < id; i++){
        if (strcmp(v[i]->categoria, categoria) == 0){
            buscar++;
            listarUnicoItem(i);
            printf("\n");
        }
    }
    if (buscar == 0){
        printf("Nenhum resultado para a categoria '%s' encontrado\n\n", categoria);
    }
}

void alterarProduto(int pos){
    if (v[pos] == NULL){
        printf("Nao existe nenhum produto cadastrado nesse ID\n\n");
    }else{
        int opcao = 0;
        do{
            printf("Produto a ser alterado:\n");
            listarUnicoItem(pos);
            printf("\n");
            printf("1 - Categoria\n");
            printf("2 - Tamanho\n");
            printf("3 - Descricao\n");
            printf("Digite a opcao que deseja alterar ou [0] para finalizar a acao\n");
            scanf("%d",&opcao);
            if (opcao == 1){
                strcpy(v[pos]->categoria, ""); //limpando o conteudo anterior
                fflush(stdin);
                printf("Informe a nova categoria do produto:\n");
                gets(v[pos]->categoria);
            }else if(opcao == 2){
                v[pos]->tamanho = '\0'; //limpando o conteudo anterior
                registrarTamanhoRoupa(pos);
            }else if(opcao == 3){
                strcpy(v[pos]->descricao, ""); //limpando o conteudo anterior
                fflush(stdin);
                printf("Informe a descricao: \n");
                gets(v[pos]->descricao);
            }else if(opcao == 0){
                printf("Fim da acao.\n\n");
            }else{
                printf("Opcao invalida.\n\n");
            }
        }while(opcao != 0);
    }
}