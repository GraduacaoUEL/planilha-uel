#include "ProdutosFuncoes.h"

void ProdutosFuncoes::inserirProduto()
{
	Produtos p;
	char esc;
	int localParaInserir,saida;

	fflush(stdin);
	printf("Nome do produto => ");
	gets(p.nomedoproduto);

	fflush(stdin);
	printf("\nCodigo => ");
	gets(p.codigo);

	fflush(stdin);
	printf("\nFabricante => ");
	gets(p.fabricante);

	fflush(stdin);
	printf("\nValidade => ");
	gets(p.validade);

	fflush(stdin);
	printf("\nPreco => ");
	gets(p.preco);

	fflush(stdin);
	printf("\nQuantidade em estoque => ");
	gets(p.quantidade);

	p.status = '1';

	localParaInserir = achaInsere(p.nomedoproduto );

	fseek(arq, (localParaInserir)*sizeof(Produtos), 0);
	fwrite(&p, sizeof(Produtos), 1, arq);

	fflush(stdin);
	printf("\n\nProduto inserido!\n");
	getchar();

	quantidadeDeProdutos++;	
	fflush(arq);
}

int ProdutosFuncoes::achaProduto (char produtoParaAchar[100])
{
	Produtos *p, pro;
	int local;
	int i;

	p = new Produtos[quantidadeDeProdutos];
	i = 0;

	fseek(arq, 0, SEEK_SET);
	fflush(arq);
	fflush(stdin);
 	fflush(stdout);
 
	while ((fread(&p[i],sizeof(Produtos),1,arq)) == 1)
		i++;

	local = busca(p,produtoParaAchar,0,0);

	delete(p);
	return local;
}

int ProdutosFuncoes::achaInsere (char produtoParaAchar[100])
{
	Produtos *p, pro;
	int local;
	int i;
	int contador;

	p = new Produtos[quantidadeDeProdutos+2];
	i = 0;

	fseek(arq, 0, 0);
	fflush(arq);
	fflush(stdin);
	fflush(stdout);

	while ((fread(&p[i], sizeof(Produtos), 1, arq)) == 1)
		i++;


	local = busca(p,produtoParaAchar, 0, 0);

	contador = quantidadeDeProdutos;

	while (contador > local)
	{
		p[contador] = p[contador-1];
		contador--;
	}

	fseek(arq, local*sizeof(Produtos) ,0);

	for (i = local; i <= quantidadeDeProdutos; i++)
		fwrite(&p[i], sizeof(Produtos), 1, arq);

	delete(p);
	return local;
} 

int ProdutosFuncoes::busca (Produtos *p, char produtoParaAchar[100], int inicio, int posicao)
{
	if (quantidadeDeProdutos !=0)
		while (p[inicio].nomedoproduto[posicao] < produtoParaAchar[posicao] && inicio < quantidadeDeProdutos )
			inicio++;

	if(p[inicio].nomedoproduto[posicao] == produtoParaAchar[posicao])
		return busca(p, produtoParaAchar, inicio, posicao+1);

	return inicio;
}

void ProdutosFuncoes::removerProduto()
{
	Produtos p; 
	int localParaRemover;
	char opcao, produtoParaRemover[100];

	printf("Digite o nome do produto que sera removido => ");
	fflush(stdin);
	gets(produtoParaRemover);

	localParaRemover = achaProduto(produtoParaRemover);

	fseek(arq, (localParaRemover) * sizeof(Produtos), 0);
	fread(&p, sizeof(Produtos), 1, arq);
  
	if (strcmp(produtoParaRemover, p.nomedoproduto) != 0)
	{
		printf("O produto %s nao foi encontrado.",produtoParaRemover);
		getchar();
		return;
	}

	printf("Nome do produto => %s\n", p.nomedoproduto);
	printf("Codigo do produto => %s\n", p.codigo);

	do {
		printf("\nTem certeza que deseja excluir? [S]im [N]ao => ");
		fflush(stdin);
		opcao = getchar();

		if (opcao == 's')
		{
			p.status = '0';
			p.nomedoproduto[0] = '\0';
			printf("\nProduto removido!");
		}
	} while (opcao !='s' && opcao !='n') ;

	fseek(arq, (localParaRemover) * sizeof(Produtos), 0);
	fwrite(&p, sizeof(Produtos), 1, arq);
}

void ProdutosFuncoes::mostrarProduto()
{
	Produtos p;
	int cont;

	cont = 0;
	fseek( arq, 0, 0 );
	fflush(arq);
	fflush(stdin);
	fflush(stdout);

	while ((fread(&p, sizeof(Produtos), 1, arq)) == 1)
	{
		if(p.status!='0')
		{
			printf("\nNome => %s ",p.nomedoproduto);
			printf("\nCodigo => %s ",p.codigo);	
			printf("\nFabricante => %s ",p.fabricante);
			printf("\nValidade => %s ",p.validade);
			printf("\nQuantidade => %s ",p.quantidade);
			printf("\nPreco => %s \n",p.preco);
			cont++;
		}
	}

	if (cont == 0)
		printf("\nNenhum produto encontrado!");

	 getchar();
}

ProdutosFuncoes::ProdutosFuncoes()
{
	Produtos p;

	quantidadeDeProdutos = 0;

	if ((arq = fopen("produtos.pro", "rb+")) == NULL)
		if ((arq = fopen("produtos.pro", "wb+")) == NULL) {
			printf("\nERRO");
			exit(1);
		}

	else {
		while (fread(&p, sizeof(Produtos), 1, arq) == 1)
			quantidadeDeProdutos++;
		fseek(arq, 0, 0);
	}
 }
 
ProdutosFuncoes::~ProdutosFuncoes()
{
	fclose(arq);
}
