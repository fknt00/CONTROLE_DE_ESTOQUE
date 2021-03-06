#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[91];
    char descricao[512];
    char lote[36];
    char valor[10];
} Produto;


int listarEstoque()
{
    FILE *arquivo = fopen("ESTOQUE.txt", "r");

    Produto produto;

    if(arquivo == NULL)
    {
        printf("\nNÃO HÁ PRODUTOS NO ESTOQUE.\n\n");
        return(0);
    }

    while(!feof(arquivo))
    {
        fscanf(arquivo, "%[^\n]\n", &produto.codigo);
        fscanf(arquivo, "%[^\n]\n", &produto.nome);
        fscanf(arquivo, "%[^\n]\n", &produto.descricao);
        fscanf(arquivo, "%[^\n]\n", &produto.lote);
        fscanf(arquivo, "%[^\n]\n\n", &produto.valor);

        printf("CÓDIGO:\tPROD%d\n", produto.codigo);
        printf("NOME:\t\t%s\n", produto.nome);
        printf("DESCRIÇÃO:\t%s\n", produto.descricao);
        printf("LOTE:\t\t%s\n", produto.lote);
        printf("VALOR:\t\tR$%s\n\n", produto.valor);
    }
    fclose(arquivo);

    return(0);
}

int codigoDoProduto()
{
    int codigo;

    FILE *arquivo = fopen("CODIGO_DO_PRODUTO.txt", "w+");

    if(arquivo == NULL)
    {
        codigo = 1;
    }
    else
    {
        fscanf(arquivo, "%d", &codigo);
        codigo++;
    }
    fprintf(arquivo, "%d\n", codigo);

    fclose(arquivo);

    return(codigo);
}

void cadastrarProduto()
{
    FILE *arquivo = fopen("ESTOQUE.txt", "a+");

    Produto produto;

    printf("\n\n\t\t\t\t\t[CADASTRAR PRODUTO]\n\n");
    fflush(stdin);

    printf("\nINFORME O NOME DO PRODUTO:\n");
    scanf("%[^\n]", produto.nome);
    fflush(stdin);
    while(strlen(produto.nome) == 0)
    {
        printf("O NOME DO PRODUTO NÃO FOI INFORMADO!\nINFORME O NOME:\n");
        scanf("%[^\n]", produto.nome);
        fflush(stdin);
    }

    printf("\nINFORME A DESCRIÇÃO DO PRODUTO:\n");
    scanf("%[^\n]", produto.descricao);
    fflush(stdin);
    while(strlen(produto.descricao) == 0) {
        printf("A DESCRIÇÃO DO PRODUTO NÃO FOI INFORMADA!\nINFORME A DESCRIÇÃO:\n");
        scanf("%[^\n]", produto.descricao);
        fflush(stdin);
    }

    printf("\nINFORME O LOTE DO PRODUTO:\n");
    scanf("%[^\n]", produto.lote);
    fflush(stdin);
    while(strlen(produto.lote) == 0)
    {
        printf("O LOTE DO PRODUTO NÃO FOI INFORMADO!\nINFORME O LOTE:\n");
        scanf("%[^\n]", produto.lote);
        fflush(stdin);
    }

    printf("\nINFORME O VALOR DO PRODUTO:\n");
    scanf("%[^\n]", produto.valor);
    fflush(stdin);
    while(strlen(produto.valor) == 0)
    {
        printf("\nO VALOR INFORMADO É INVÁLIDO!\nINFORME O VALOR NOVAMENTE:\n");
        scanf("%[^\n]", produto.valor);
        fflush(stdin);
    }

    produto.codigo = codigoDoProduto();

    fprintf(arquivo, "%d\n", produto.codigo);
    fprintf(arquivo, "%s\n", produto.nome);
    fprintf(arquivo, "%s\n", produto.descricao);
    fprintf(arquivo, "%s\n", produto.lote);
    fprintf(arquivo, "%s\n\n", produto.valor);

    fclose(arquivo);

    printf("\nO PRODUTO FOI CADASTRADO COM SUCESSO!\n\n");
    fflush(stdin);
}

int comandos(int opcao)
{
    switch(opcao)
   {
        FILE *arquivo;

        case 1:
                system("cls");
                cadastrarProduto();
                system("pause");
                system("cls");
                break;
        case 2:
                system("cls");
                listarEstoque();
                system("pause");
                system("cls");
                break;
        default:
                system("cls");
                printf("\nOPÇÃO INVÁLIDA!\n\n");
                system("pause");
                system("cls");
                break;
    }
}

void menu()
{
    printf("\n\n");
    printf("\t\t\t  ########################################################  \n");
    printf("\t\t\t  #\t\t\t\t\t\t\t #\n");
    printf("\t\t\t  #\t\t   1 - CADASTRAR PRODUTO \t\t #\n");
    printf("\t\t\t  #\t\t\t\t\t\t\t #\n");
    printf("\t\t\t  ########################################################  \n");
    printf("\t\t\t  #\t\t\t\t\t\t\t #\n");
    printf("\t\t\t  #\t\t     2 - EXIBIR ESTOQUE \t\t #\n");
    printf("\t\t\t  #\t\t\t\t\t\t\t #\n");
    printf("\t\t\t  ########################################################  \n");
}

int main(void)
{
    int repetir = 1, opcao;

    mkdir("REGISTROS");
    chdir("REGISTROS");
    system("cls");
    system("MODE con cols=109 lines=44");
    setlocale(LC_ALL, "Portuguese");

    do
    {
        menu();
        printf("\n\nDIGITE A OPÇÃO DESEJADA: ");
        scanf("%d", &opcao);
        system("cls");
        comandos(opcao);
    } while(repetir != 0);


    return(0);
}

