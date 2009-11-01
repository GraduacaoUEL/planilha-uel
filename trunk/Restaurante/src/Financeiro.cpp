/*
 * Financeiro.cpp
 *
 *  Created on: 01/11/2009
 *      Author: helioalb
 */
#include "Financeiro.h"
Financeiro::Financeiro(char *nomeConta)
{
	strcpy(nome, nomeConta);
}
void Financeiro::entrada(Financeiro f)
{
	int op, sn;
	float  ent;

	do{
		printf("Escolha o tipo de entrada\n\n\n");
		printf("( 1 )Deposito\n");
		printf("( 2 )Vendas ao cliente\n");
		printf("( 3 )Voltar.\n\n");

		scanf("%d", &op);

	}while(op < 1 || op > 3);

	if(op == 1)
	{
		system("clear");

		printf("Digite o valor do deposito:  \n");
		scanf("%f", &ent);

		system("clear");

		printf("Confirma o deposito [1 - SIM/ 2 - NAO]:\n\n");
		scanf("%d", &sn);

		if(sn == 1)
		{
			printf("Deposito realizado com sucesso.\n\n");
		}
		else
		{
			entrada(f);
		}

	}
	else if(op == 2)
	{
        system("clear");

        printf("Digite o valor da venda:  \n");
        scanf("%f", &ent);

//Implementar cliente

        system("clear");

        printf("Confirma a venda [1 - SIM/ 2 - NAO]:\n\n");
        scanf("%d", &sn);

        if(sn == 1)
        {
                printf("Venda Realizada com sucesso.\n\n");
        }
        else
        {
                entrada(f);
        }

	}
	else if(op ==3)
	{
		menu->menuFinanceiro(f);
	}

}


void Financeiro::saida()
{

}

