#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct CadastrarProduto
{
    int codigo;
    char nome[91];
    char descricao[512];
    char lote[36];
    char valor[10];
};

int codigoNoEstoque()
{
    int codigo = 1;

    FILE *codigoEst;
    codigoEst = fopen("CODIGO_NO_ESTOQUE.txt", "r+");

    if(codigoEst != NULL)
    {
        int codgEst;
        fscanf(codigoEst, "%d", codgEst);
        codgEst++;
    }

    codigoEst = fopen("CODIGO_NO_ESTOQUE.txt", "w+");
    fprintf(codigoEst, "%d", codigo);
    fclose(codigoEst);

    return(codigo);
}

void cadastrarProduto()
{
    FILE *cadastrar = fopen("ESTOQUE.txt", "a+");

    struct CadastrarProduto produto;

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

    produto.codigo = codigoNoEstoque();

    fprintf(cadastrar, "%d\n", produto.codigo);
    fprintf(cadastrar, "%s\n", produto.nome);
    fprintf(cadastrar, "%s\n", produto.descricao);
    fprintf(cadastrar, "%s\n", produto.lote);
    fprintf(cadastrar, "%s\n\n", produto.valor);
    fclose(cadastrar);

    fclose(cadastrar);

    printf("\nO PRODUTO FOI CADASTRADO COM SUCESSO!\n\n");
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
}

int main(void)
{
    mkdir("REGISTROS");
    chdir("REGISTROS");
    system("cls");
    system("MODE con cols=109 lines=44");
    setlocale(LC_ALL, "Portuguese");

    int repetir = 1, opcao, cont;
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

