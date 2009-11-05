/*
 * Menus.cpp
 *
 *  Created on: 01/11/2009
 *      Author: helioalb
 */
#include "Menus.h"
#include "Cliente.h"
#include "ClienteFuncoes.h"
#include "Financeiro.h"
#include "Fornecedores.h"
#include "Produtos.h"
#include "ProdutosFuncoes.h"

void Menus::principal()
{
    int op;

    do{
            system("cls");
            printf("--------------------SISTEMA DE CONTROLE DE RESTAURANTES--------------------\n\n\n\n");
            printf("Digite a opcao correspondente ao modulo desejado e pressione Enter\n\n\n");
            printf("( 1 ) Clientes\n");
            printf("( 2 ) Financeiro\n");
            printf("( 3 ) Fornecedores\n");
            printf("( 4 ) Produtos\n");
            printf("( 5 ) Sair\n");
            printf("\nOpcao => ");
            
            scanf("%d", &op);
    }while(op < 1 || op > 5);

    switch(op)
    {
    case 1:
            menuCliente();
            break;

    case 2:
            menuFinanceiro();
            break;

    case 3:
            menuFornecedores();
            break;

    case 4:
            menuProdutos();
            break;


    case 5:
            exit(1);
            break;


    }

}

void Menus::menuCliente()
{
   	ClienteFuncoes c;
	int opcao;
	do{
		system("cls");
		printf("---------------------------CADASTRO DE CLIENTES---------------------------\n\n\n\n");
		printf("Digite a opcao desejada e pressione Enter\n\n\n");
        printf("( 1 ) Para inserir cliente\n");
		printf("( 2 ) Para remover um cliente\n");
		printf("( 3 ) Para inserir ou vizualizar os pedidos de um cliente\n");
		printf("( 4 ) Para mostrar todos os clientes\n");
		printf("( 5 ) Para vizualizar um cliente\n");
		printf("( 6 ) Para sair\n");	
		printf("\nOpcao => ");
		
	
		fflush(stdin);
		scanf("%d",&opcao);
		
		if(opcao == 1)
			c.inserirCliente();
		if(opcao == 2)
			c.removerCliente();	
		if(opcao == 3)
			c.pedidos();
		if(opcao == 4)
			c.mostrarClientes();
		if(opcao ==5)
			c.vizualizarCliente();
			
	}while( opcao != 6);
	c.menu->principal();
     
}

void Menus::menuFinanceiro()
{

	int op;
	FinanceiroFuncoes f;

	do{
		system("cls");
		printf("------------------------MOVIMENTACOES FINANCEIRAS------------------------\n\n\n\n");
		printf("Digite a opcao desejada e pressione Enter\n\n\n");
		printf("( 1 ) Entrada\n");
		printf("( 2 ) Saida\n");
		printf("( 3 ) Agendar contas a pagar\n");
		printf("( 4 ) Agendar contas a receber(fiado)\n");
		printf("( 5 ) Historico de Entradas\n");
		printf("( 6 ) Historico de Saidas\n");
		printf("( 7 ) Voltar\n");
		printf("\nOpcao => ");

		scanf("%d", &op);
	}while(op < 1 || op > 7);

	switch(op)
	{
	case 1:
		f.entrada();
		break;

	case 2:
        f.saida();
		break;

	case 5:
		f.historicoEntrada();
		break;
		
	case 6:
		f.historicoSaida();
		break;
		

	case 7:
		f.menu->principal();
		break;

	}
}

void Menus::menuFornecedores()
{
   	Fornecedores teste;
	teste.graveFornecedor();
	teste.leiaFornecedor();
}

void Menus::menuProdutos()
{
   	ProdutosFuncoes p;
	int opcao;
	do{
		system("cls");
		printf("----------------------------CADASTRO DE PRODUTOS----------------------------\n\n\n\n");
		printf("Digite a opcao desejada e pressione Enter\n\n\n");
		printf("( 1 ) Para inserir produto\n");
		printf("( 2 ) Para remover um produto\n");
		printf("( 3 ) Para modificar um produto\n");
		printf("( 4 ) Para mostrar todos os produtos\n");
        printf("( 5 ) Para sair\n");
		printf("\nOpcao => ");
	
		fflush(stdin);
		scanf("%d",&opcao);
		
		if(opcao == 1)
			p.inserirProduto();
		if(opcao == 2)
			p.removerProduto();
		if(opcao == 3)
			p.modificarProduto();
		if(opcao == 4)
			p.mostrarProduto();

	}while( opcao != 5);
	p.menu->principal();
     
}
