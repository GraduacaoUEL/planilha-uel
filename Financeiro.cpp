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
	char descricao[30];
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
        fflush(stdin);
        scanf("%f", &f.entradav);

		printf("Faça uma breve descrição da operação:\n");
        fflush(stdin);
        gets(f.descricao);


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
		printf("N�o existem registros\n");

        if((fin = fopen("financeiro.fin", "wb")) == NULL)
        {
		    printf("Erro ao criar arquivo\n");
		    exit(1);
        }
	}

    fseek( fin, 0, SEEK_SET );
    fflush(fin);
    fflush(stdin);
    fflush(stdout);
    
    system("cls");
    
    printf("\t\tDeposito\t\tDescricao\t\t");
    
    while ((fread(&f, sizeof(Financeiro), 1, fin))==1)
    {
	 	printf("\n\t\t%f\t\t ", f.entradav);
	 	printf("%s\n", f.descricao);	
	}
    getchar(); 
    menu->menuFinanceiro();
}
