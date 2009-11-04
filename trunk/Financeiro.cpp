/*
 * Financeiro.cpp
 *
 *  Created on: 01/11/2009
 *      Author: helioalb
 */
#include "Financeiro.h"


FinanceiroFuncoes::FinanceiroFuncoes()
{

}

FinanceiroFuncoes::~FinanceiroFuncoes()
{
	fclose(fin);
}

void FinanceiroFuncoes::entrada()
{
	int op, sn;
	struct Financeiro f;

	do{
		system("cls");
		printf("Escolha o tipo de entrada\n\n\n");
		printf("( 1 )Deposito\n");
		printf("( 2 )Vendas ao cliente\n");
		printf("( 3 )Voltar.\n\n");

		scanf("%d", &op);

	}while(op < 1 || op > 3);

	if(op == 1)
	{
		system("cls");

		printf("Digite o valor do deposito:  \n");
        
        scanf("%f", &f.entradav);

		printf("Faça uma breve descrição da operação:\n");
		scanf("%s", f.descricao);

		system("cls");

		printf("Confirma o deposito [1 - SIM/ 2 - NAO]:\n\n");
		scanf("%d", &sn);

		if(sn == 1)
		{

			if((fin = fopen("financeiro.fin", "ab")) == NULL)
			{
				printf("Erro ao abrir o arquivo financeiro.fin\n");
				exit(1);
			}


			fwrite(&f, sizeof(struct Financeiro), 1, fin);
			printf("Deposito realizado com sucesso.\n\n");
			fflush(fin);
			entrada();

		}
		else
		{
			entrada();
		}

	}
	else if(op == 2)
	{
		system("cls");

		printf("Digite o valor da venda:  \n");

		//Implementar cliente

		system("cls");

		printf("Confirma a venda [1 - SIM/ 2 - NAO]:\n\n");
		scanf("%d", &sn);

		if(sn == 1)
		{
			printf("Venda Realizada com sucesso.\n\n");
		}
		else
		{
			entrada();
		}

	}
	else if(op ==3)
	{
		menu->menuFinanceiro();
	}

}

void FinanceiroFuncoes::historicoEntrada()
{
    Financeiro f;
	if((fin = fopen("financeiro.fin", "rb")) == NULL)
	{
		printf("Erro ao abrir o arquivo financeiro.fin\n");
		exit(1);
	}

	rewind(fin);
/*	for(int i = 0; i != feof(fin); i++)
	{
		fread(&f, sizeof(struct Financeiro), 1, fin);
		printf("%f\t", f[1].entradav);
		printf("%s\n", f[1].descricao);

	}
*/
}
