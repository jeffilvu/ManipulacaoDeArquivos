#include <stdio.h>
#include <stdlib.h>

/*Este código em C implementa um sistema básico de gerenciamento de produtos que permite adicionar, listar, pesquisar, alterar e excluir informações sobre até três produtos.*/

char produto1[20], produto2[20], produto3[20];
int qtd1, qtd2, qtd3,opcao=0;

int compara_palavras(const char *a, const char *b) 
{
    int cont = 0;
    while (a[cont] == b[cont]) {
        if (a[cont] == '\0' || b[cont] == '\0')
            break;
        cont++;
    }

    if (a[cont] == '\0' && b[cont] == '\0')
        return 0;
    else
        return -1;
}
void cria_arquivo()
{
    FILE *arquivo = fopen("dados.txt", "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", "dados.txt");
        exit(1);
    }

    fwrite(produto1, sizeof(char), 20, arquivo);
    fwrite(&qtd1, sizeof(int), 1, arquivo);
    fwrite(produto2, sizeof(char), 20, arquivo);
    fwrite(&qtd2, sizeof(int), 1, arquivo);
    fwrite(produto3, sizeof(char), 20, arquivo);
    fwrite(&qtd3, sizeof(int), 1, arquivo);

    fclose(arquivo);

}
void carrega_dados() 
{
    FILE *arquivo = fopen("dados.txt", "rb");

    if (arquivo == NULL) {
        printf("Arquivo %s não encontrado. Criando um novo arquivo.\n", "dados.txt");
        cria_arquivo();
    }
        

        arquivo = fopen("dados.txt", "rb"); // Tenta abrir novamente

    fread(produto1, sizeof(char), 20, arquivo);
    fread(&qtd1, sizeof(int), 1, arquivo);
    fread(produto2, sizeof(char), 20, arquivo);
    fread(&qtd2, sizeof(int), 1, arquivo);
    fread(produto3, sizeof(char), 20, arquivo);
    fread(&qtd3, sizeof(int), 1, arquivo);

    fclose(arquivo);
}
void entrada_dados()
{
 
 
    printf("Digite o nome do primeiro produto:\n");
    scanf("%s",produto1);
    printf("Digite a quantidade:\n");
    scanf("%d",&qtd1);
    printf("Digite o nome do segundo produto:\n");
    scanf("%s",produto2);
    printf("Digite a quantidade:\n");
    scanf("%d",&qtd2);
    printf("Digite o nome do terceiro produto:\n");
    scanf("%s",produto3);
    printf("Digite a quantidade:\n");
    scanf("%d",&qtd3);

    cria_arquivo();
 
}
void listar_produtos()
{
    printf("Produto:%s | Quantidade: %d\n",produto1,qtd1);
    printf("Produto:%s | Quantidade: %d\n",produto2,qtd2);
    printf("Produto:%s | Quantidade: %d\n",produto3,qtd3);
}
void pesquisa_nome_inteiro()
{
    char produto_recebido[20];
    printf("Digite o nome do produto: ");
    scanf("%s",produto_recebido);
 
    if (compara_palavras(produto_recebido, produto1) == 0)
    {
        printf("Produto:%s | Quantidade:%d", produto1, qtd1);
    }
    else if(compara_palavras(produto_recebido, produto2) == 0)
    {
        printf("Produto:%s | Quantidade:%d", produto2, qtd2);
    }
    else if(compara_palavras(produto_recebido, produto3) == 0)
    {
        printf("Produto:%s | Quantidade:%d", produto3, qtd3);
    }
    else
    {
        printf("Produto não encontrado!\n");
    }
 
}
void pesquisa_primeira_letra()

{
    char letra_recebida;
    printf("Digite a Letra: ");
    scanf(" %c", &letra_recebida);
 
    if(letra_recebida == produto1[0])
    {
        printf("%s\n", produto1);
    }
    if(letra_recebida == produto2[0])
    {
        printf("%s\n", produto2);
    }
    if(letra_recebida == produto3[0])
    {
        printf("%s\n", produto3);
    }
 
    if(letra_recebida != produto1[0] && letra_recebida != produto2[0] && letra_recebida != produto3[0])
    {
        printf("Nenhum produto encontrado\n");
    }
 
}
void altera_dados()
{
    char produto_recebido[20];
 
    printf("Digite o nome completo do produto: ");
    scanf("%s", produto_recebido);
 
    if (compara_palavras(produto_recebido, produto1) == 0)
    {
        printf("Produto:%s | Quantidade:%d\n", produto1, qtd1);
 
        printf("Novo nome:\n ");
        scanf("%s",produto1);
 
        printf("Nova quantidade:\n ");
        scanf("%d", &qtd1);
 
    }
    else if(compara_palavras(produto_recebido, produto2) == 0)
    {
        printf("Produto:%s | Quantidade:%d\n", produto2, qtd2);
 
 
        printf("Novo nome:\n ");
        scanf("%s",produto2);
 
        printf("Nova quantidade:\n ");
        scanf("%d", &qtd2);
    }
    else if(compara_palavras(produto_recebido, produto3) == 0)
    {
        printf("Produto:%s | Quantidade:%d\n", produto3, qtd3);
        printf("Novo nome:\n ");
        scanf("%s",produto3);
 
        printf("Nova quantidade:\n ");
        scanf("%d", &qtd3);
    }
    else
    {
        printf("Produto não encontrado!\n");
    }
    cria_arquivo();
}
void exclui_dados()
{
    int cont=0;
    char produto_recebido[20];
 
    printf("Digite o nome completo do produto: ");
    scanf("%s", produto_recebido);
 
    if (compara_palavras(produto_recebido, produto1) == 0)
    {
        for (cont = 0; cont < 20; cont++)
            produto1[cont] = NULL;
            qtd1 = 0;
    }
 
    else if(compara_palavras(produto_recebido, produto2) == 0)
    {
        for (cont = 0; cont < 20; cont++)
            produto2[cont] = NULL;
            qtd2 = 0;
    }
    else if(compara_palavras(produto_recebido, produto3) == 0)
    {
        for (cont = 0; cont < 20; cont++)
            produto3[cont] = NULL;
            qtd3 = 0;
    }
    else
    {
        printf("Produto não encontrado!\n");
    }
    cria_arquivo();
} 
int main()
{
    carrega_dados();
    while (1)
    {
        printf("\nEscolha uma opcao do menu: \n");
        printf("[1] - Inserir produtos \n");
        printf("[2] - Listar produtos \n");
        printf("[3] - Pesquisar produto pelo nome inteiro\n");
        printf("[4] - Pesquisar produto pela primeira letra\n");
        printf("[5] - Altera dados\n");
        printf("[6] - Exclui dados\n");
        printf("[7] - Sair do menu\n");
 
        scanf("%d",&opcao);
 
        switch (opcao)
        {
        case 1:
            entrada_dados();
            break;
        case 2:
            listar_produtos();
            break;
 
        case 3:
            pesquisa_nome_inteiro();
            break;
 
        case 4:
            pesquisa_primeira_letra();
            break;
 
        case 5:
            altera_dados();
            break;
 
        case 6:
            exclui_dados();
            break;
 
        default:
            if(opcao != 7)
            {
                printf("Nenhuma opcao selecionada\n");
            }
 
            break;
        }
 
        if(opcao == 7)
        {
            break;
        }
 
    }
    cria_arquivo();

}