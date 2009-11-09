/*
 * Menus.cpp
 *
 *  Created on: 01/11/2009
 *	  Author: helioalb
 */

#include "Cabecalhos.h"
#include "Menus.h"
#include "ClienteFuncoes.h"
#include "FinanceiroFuncoes.h"
#include "FornecedorFuncoes.h"
#include "ProdutosFuncoes.h"

void Menus::principal()
{
	int op;

	do {
		system("cls");
		printf("------------------- SISTEMA DE CONTROLE DE RESTAURANTES -------------------\n\n\n\n");
		printf("Digite a opcao correspondente ao modulo desejado e pressione Enter\n\n\n");
		printf("( 1 ) Clientes\n");
		printf("( 2 ) Financeiro\n");
		printf("( 3 ) Fornecedores\n");
		printf("( 4 ) Produtos\n");
		printf("( 5 ) Sair\n");

		do {
			fflush(stdin);
			printf("\n\nSelecione a opcao desejada => ");
			scanf("%d", &op);
		} while (op < 1 || op > 5);

		if (op == 1)
			menuCliente();
		else if (op == 2)
			menuFinanceiro();
		else if (op == 3)
			menuFornecedores();
		else if (op == 4)
			menuProdutos();

	} while (op != 5);
}

void Menus::menuCliente()
{
	ClienteFuncoes c;
	int opcao;

	do {
		system("cls");
		printf("-------------------------- CADASTRO DE CLIENTES --------------------------\n\n\n\n");
		printf("Digite a opcao desejada e pressione Enter\n\n\n");
		printf("( 1 ) Inserir cliente\n");
		printf("( 2 ) Remover um cliente\n");
		printf("( 3 ) Inserir ou visualizar os pedidos de um cliente\n");
		printf("( 4 ) Mostrar todos os clientes\n");
		printf("( 5 ) Visualizar um cliente\n");
		printf("( 6 ) Sair\n");

		do {
			printf("\n\nSelecione a opcao desejada => ");
			fflush(stdin);
			scanf("%d", &opcao);
		} while (opcao < 1 || opcao > 6);

		if (opcao == 1)
			c.inserirCliente();
		if (opcao == 2)
			c.removerCliente();	
		if (opcao == 3)
			c.pedidos();
		if (opcao == 4)
			c.mostrarClientes();
		if (opcao == 5)
			c.vizualizarCliente();
	} while (opcao != 6);

}

void Menus::menuFinanceiro()
{
	int op;
	FinanceiroFuncoes f;

	do {
		system("cls");
		printf("----------------------- MOVIMENTACOES FINANCEIRAS -----------------------\n\n\n\n");
		printf("Digite a opcao desejada e pressione Enter\n\n\n");
		printf("( 1 ) Entrada\n");
		printf("( 2 ) Saida\n");
		printf("( 3 ) Historico de Entradas\n");
		printf("( 4 ) Historico de Saidas\n");
		printf("( 5 ) Voltar\n");

		do {
			printf("\n\nSelecione a opcao desejada => ");
			fflush(stdin);
			scanf("%d", &op);
		} while (op < 1 || op > 5);

		if (op == 1)
			f.entrada();
		if (op == 2)
			f.saida();
		if (op == 3)
			f.historicoEntrada();
		if (op == 4)
			f.historicoSaida();

	} while (op != 5);

}

void Menus::menuFornecedores()
{

	FornecedorFuncoes teste;
	char buffer[5];
	int op;

	do {
		system("cls");
		printf("----------------------- CADASTRO DE FORNECEDORES ------------------------\n\n\n\n");
		printf("Digite a opcao desejada e pressione Enter\n\n\n");

		printf("( 1 ) Registrar fornecedor\n");
		printf("( 2 ) Mostrar todos os fornecedores\n");
		printf("( 3 ) Mostrar um unico fornecedor\n");
		printf("( 4 ) Atualizar dados de um fornecedor\n");
		printf("( 5 ) Mostrar status de um fornecedor\n");
		printf("( 6 ) Atualizar status de um fornecedor\n");
		printf("( 7 ) Apagar fornecedor\n");
		printf("( 8 ) Voltar ao menu principal\n");

		do {
			printf("\n\nSelecione a opcao desejada => ");
			fflush(stdin);
			fgets(buffer, sizeof(buffer), stdin);
			op = atoi(buffer);
		} while (op < 1 || op > 8);

		system("cls");
		if (op == 1)
		{
			teste.graveFornecedor();
			system("pause");
		}
		else if (op == 2)
		{
			teste.leiaFornecedores();
			system("pause");
		}
		else if (op == 3)
		{
			printf("EXIBIR DADOS DE UM UNICO FORNECEDOR\n\n");
			teste.leiaFornecedorUnico(teste.buscaFornecedor());
			system("pause");
		}

		else if (op == 4)
		{
			printf("ATUALIZAR DADOS DE UM FORNECEDOR\n\n");
			teste.atualizaFornecedor(teste.buscaFornecedor());
			system("pause");
		}

		else if (op == 5)
		{
			printf("EXIBIR STATUS DE FORNECEDOR\n\n");
			teste.mostreStatus(teste.buscaFornecedor());
			system("pause");
		}

		else if (op == 6)
		{
			printf("ATUALIZAR STATUS DE UM FORNECEDOR\n\n");
			teste.atualizaStatus(teste.buscaFornecedor());
			system("pause");
		}

		else if (op == 7)
		{
			printf("APAGAR FORNECEDOR\n\n");
			teste.apagarFornecedor(teste.buscaFornecedor());
			system("pause");
		}

	} while (op != 8);

}

void Menus::menuProdutos()
{
	ProdutosFuncoes p;
	int opcao;

	do {
		system("cls");
		printf("--------------------------- CADASTRO DE PRODUTOS ---------------------------\n\n\n\n");
		printf("Digite a opcao desejada e pressione Enter\n\n\n");
		printf("( 1 ) Para inserir produto\n");
		printf("( 2 ) Para remover um produto\n");
		printf("( 3 ) Para mostrar todos os produtos\n");
		printf("( 4 ) Para sair\n");

		do {
			printf("\n\nSelecione a opcao desejada => ");
			fflush(stdin);
			scanf("%d", &opcao);
		} while (opcao < 1 || opcao > 4);

		if (opcao == 1)
			p.inserirProduto();
		if (opcao == 2)
			p.removerProduto();
		if (opcao == 3)
			p.mostrarProduto();

	} while (opcao != 4);
}
