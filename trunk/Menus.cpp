/*
 * Menus.cpp
 *
 *  Created on: 01/11/2009
 *      Author: helioalb
 */
#include "Menus.h"

void Menus::principal()
{
    int op;

    do{
            system("clear");
            printf("--------------------SISTEMA DE CONTROLE DE RESTAURANTES--------------------\n\n\n\n");
            printf("Digite a opcao correspondente ao modulo desejado e pressione Enter\n\n\n");
            printf("( 1 ) Clientes\n");
            printf("( 2 ) Financeiro\n");
            printf("( 3 ) Fornecedores\n");
            printf("( 4 ) Produtos\n");
            printf("( 5 ) Sair\n");

            scanf("%d", &op);
    }while(op < 1 || op > 5);

    switch(op)
    {
    case 1:

            break;

    case 2:
            menuFinanceiro();
            break;

    }

}
void Menus::menuFinanceiro()
{

	int op;
	FinanceiroFuncoes f;

	do{
		system("clear");
		printf("--------------------MOVIMENTACOES FINANCEIRAS--------------------\n\n\n\n");
		printf("Digite a opcao desejada e pressione Enter\n\n\n");
		printf("( 1 ) Entrada\n");
		printf("( 2 ) Saida\n");
		printf("( 3 ) Agendar contas a pagar\n");
		printf("( 4 ) Agendar contas a receber(fiado)\n");
		printf("( 5 ) Historico de Entradas\n");
		printf("( 6 ) Historico de Saidas\n");
		printf("( 7 ) Voltar\n");

		scanf("%d", &op);
	}while(op < 1 || op > 7);

	switch(op)
	{
	case 1:
		f.entrada();
		break;

	case 2:

		break;

	case 5:
		f.historicoEntrada();
		break;

	case 7:
		f.menu->principal();
		break;

	}
}

