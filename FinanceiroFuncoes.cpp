/*
 * Financeiro.cpp
 *
 *  Created on: 01/11/2009
 *	  Author: helioalb
 */
#include "FinanceiroFuncoes.h"

FinanceiroFuncoes::FinanceiroFuncoes()
{

}
/*
FinanceiroFuncoes::~FinanceiroFuncoes()
{
	fclose(fin);
}
*/

void FinanceiroFuncoes::entrada()
{
	int op, sn;
	char descricao[30];
	float valor;
	struct Financeiro f;

	do {
		system("cls");
		printf("Escolha o tipo de entrada\n\n\n");
		printf("( 1 ) Deposito\n");
		printf("( 2 ) Vendas ao cliente\n");
		printf("( 3 ) Voltar\n\n");

		fflush(stdin);
		scanf("%d", &op);
	} while (op < 1 || op > 3);

	if (op == 1)
	{
		system("cls");
		printf("Digite o valor do deposito => ");
		fflush(stdin);
		scanf("%f", &f.entradav);

		printf("Faca uma breve descricao da operacao => ");
		fflush(stdin);
		gets(f.descricao);

		system("cls");

		printf("Confirma o deposito? (1)Sim (2)Nao => ");
		fflush(stdin);
		scanf("%d", &sn);

		if (sn == 1)
		{
			if ((sld = fopen("saldo.fin", "rb")) == NULL)
			{
				sld = fopen("saldo.fin", "wb");
				valor = 0.0;
			}

			if((fin = fopen("fin_in.fin", "ab")) == NULL)
			{
				printf("Erro ao abrir o arquivo fin_in.fin\n");
				exit(1);
			}

			fwrite(&f, sizeof(struct Financeiro), 1, fin);
			fflush(fin);

			getchar();
			entrada();
		}
		else
		{
			entrada();
		}

	}
	else if (op == 2)
	{
		system("cls");
		printf("Digite o valor da venda => ");

		//Implementar cliente

		system("cls");
		printf("Confirma a venda? (1)Sim (2)Nao => ");
		fflush(stdin);
		scanf("%d", &sn);

		if(sn == 1)
		{
			printf("Venda realizada com sucesso.\n\n");
		}
		else
		{
			entrada();
		}

	}

}

void FinanceiroFuncoes::historicoEntrada()
{
	Financeiro f;

	if((fin = fopen("fin_in.fin", "rb")) == NULL)
	{
		printf("Não existem registros\n");

		if((fin = fopen("fin_in.fin", "wb")) == NULL)
		{
			printf("Erro ao criar arquivo\n");
			exit(1);
		}
	}


	fseek(fin, 0, SEEK_SET);
	fflush(fin);
	fflush(stdin);
	fflush(stdout);

	system("cls");

	printf("\t\tDeposito\t\tDescricao\t\t");

	while ((fread(&f, sizeof(Financeiro), 1, fin)) == 1)
	{
		printf("\n\t\t%f\t\t ", f.entradav);
		printf("%s\n", f.descricao);
	}
	getchar(); 
}

void FinanceiroFuncoes::saida()
{
	int sn;
	char descricao[30];
	struct Financeiro f;

	system("cls");

	printf("Digite o valor da saida => ");
	fflush(stdin);
	scanf("%f", &f.saidav);

	printf("Faca uma breve descricao da operacao => ");
	fflush(stdin);
	gets(f.descricao);

	system("cls");

	printf("Confirma a saida? (1)Sim / (2)Nao => ");
	fflush(stdin);
	scanf("%d", &sn);

	if(sn == 1)
	{

		if((fin = fopen("fin_out.fin", "ab")) == NULL)
		{
			printf("Erro ao abrir o arquivo financeiro.fin\n");
			exit(1);
		}

		fwrite(&f, sizeof(struct Financeiro), 1, fin);
		printf("Saida realizada com sucesso.\n\n");
		fflush(fin);
		getchar();

	}

}

void FinanceiroFuncoes::historicoSaida()
{
	Financeiro f;

	if((fin = fopen("fin_out.fin", "rb")) == NULL)
	{
		printf("Não existem registros\n");

		if((fin = fopen("fin_out.fin", "wb")) == NULL)
		{
			printf("Erro ao criar arquivo\n");
			exit(1);
		}
	}

	fseek(fin, 0, SEEK_SET );
	fflush(fin);
	fflush(stdin);
	fflush(stdout);

	system("cls");

	printf("\t\tSaida\t\tDescricao\t\t");
	
	while ((fread(&f, sizeof(Financeiro), 1, fin)) == 1)
	{
		printf("\n\t\t%f\t\t ", f.saidav);
		printf("%s\n", f.descricao);
	}

	getchar(); 
}
