/*
 * Menus.cpp
 *
 *  Created on: 01/11/2009
 *      Author: helioalb
 */
#include "Menus.h"

void Menus::principal(Financeiro caixa, Financeiro banco)
{
    int op;

    do{
            system("clear");
            printf("--------------------SISTEMA DE CONTROLE DE RESTAURANTES--------------------\n\n\n\n");
            printf("Digite a opcao correspondente ao modulo desejado e pressione Enter\n\n\n");
            printf("( 1 ) Clientes\n");
            printf("( 2 ) Financeiro(%s)\n", caixa.nome);
            printf("( 3 ) Financeiro(%s)\n", banco.nome);
            printf("( 4 ) Fornecedores\n");
            printf("( 5 ) Produtos\n");
            printf("( 6 ) Sair\n");

            scanf("%d", &op);
    }while(op < 1 || op > 6);

    switch(op)
    {
    case 1:

            break;

    case 2:
            menuFinanceiro(caixa);
            break;

    case 3:
            menuFinanceiro(banco);
            break;

    }

}
void Menus::menuFinanceiro(Financeiro f)
{

	int op;

	do{
		system("clear");
		printf("--------------------MOVIMENTACOES FINANCEIRAS (%s)--------------------\n\n\n\n", f.nome);
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
		f.entrada(f);
		break;

	case 2:
		f.saida();
		break;

	case 7:
		f.menu->principal(f,f); //Isso gera um pequeno bug, tem que arrumar
		break;

	}
}

