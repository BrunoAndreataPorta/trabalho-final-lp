#ifndef TRABALHOFINALLP_CONTROLEESTOQUEROUPAS_H
#define TRABALHOFINALLP_CONTROLEESTOQUEROUPAS_H
#define MAX 100

typedef struct {
    int id;
    char descricao[100];
    int quantidade;
    char tamanho;
    char categoria[30];
}vestuario;

// Definição de um ponteiro para a estrutura 'vestuario'
typedef vestuario *p_vestuario;

/**
 * Declaração externa de um array do struct
 */
extern p_vestuario v[MAX];

/**
 * Função responsável por limpar a memória alocada
 */
void inicializar();

/**
 * Função que registra o tamanho de uma roupa (P, M, G, etc...)
 */
void registrarTamanhoRoupa(int id);

/**
 * Função responsável por adicionar novos itens(roupas) ao estoque
 *
 * @param id - O identificador único do novo item
 */
void adicionarNovoItem(int id);

/**
 * Função responsável por atualizar um item previamente cadastrado no estoque
 *
 * @param pos - É o ID do produto que vai ser atualizado o estoque
 */
void atualizarEstoque(int pos);

/**
 * Função usada para imprimir um produto especifico baseado no ID
 *
 * @param id - identificador do produto a ser impresso na tela
 */
void listarUnicoItem(int id);

/**
 * Função mostra todos os produtos que estão cadastrados
 *
 * @param id - Utilizado para percorrer apenas os espaços já cadastrados
 */
void listarItens(int id);

/**
 * Função filtra os itens a serem listados de acordo com a categoria especificada pelo úsuario
 *
 * @param categoria - Utilizado para comparar com os produtos que já estão cadastrados
 * @param id - Utilizado para percorrer apenas os espaços já cadastrados
 */
void listarPorCategoria(char categoria[30], int id);

/**
 * Função permite alterar dados cadastrados no produto, como categoria, tamanho e descrição
 *
 * @param pos - Utilizado para saber o ID do produto que é desejado alterar
 */
void alterarProduto(int pos);

#endif //TRABALHOFINALLP_CONTROLEESTOQUEROUPAS_H
