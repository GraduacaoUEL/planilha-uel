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
	fclose(sld);
}

void FinanceiroFuncoes::entrada()
{
	int op, sn;
	char descricao[30];
    struct Financeiro f, g;
    
 
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

		printf("Faca uma breve descricao da operacao:\n");
        fflush(stdin);
        gets(f.descricao);


		system("cls");

		printf("Confirma o deposito [1 - SIM/ 2 - NAO]:\n\n");
		scanf("%d", &sn);

		if(sn == 1)
		{
              
            if((sld = fopen("saldo.fin", "rb")) == NULL)
            {
                printf("\nNom abristes\n");
                g.saldo = 0.0;  
            }
            else
                fread(&g, sizeof(Financeiro), 1, sld);    
  
			if((fin = fopen("fin_in.fin", "ab")) == NULL)
			{
				printf("Erro ao abrir o arquivo fin_in.fin\n");
				exit(1);
			}

			if((fin = fopen("saldo.fin", "wb")) == NULL)
			{
				printf("Erro ao abrir o arquivo saldo.fin\n");
				exit(1);
			}



			fwrite(&f, sizeof(struct Financeiro), 1, fin);
			g.saldo += f.entradav;
			fwrite(&g, sizeof(struct Financeiro), 1, sld);
			printf("Deposito realizado com sucesso. O seu novo saldo e de: %f\n\n", f.saldo);
			fflush(fin);
			getchar();
			getchar();
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
	if((fin = fopen("fin_in.fin", "rb")) == NULL)
	{
		printf("Não existem registros\n");

        if((fin = fopen("fin_in.fin", "wb")) == NULL)
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

void FinanceiroFuncoes::saida()
{
	int sn;
	char descricao[30];
    struct Financeiro f;
    
		system("cls");

		printf("Digite o valor da saida:  \n");
        fflush(stdin);
        scanf("%f", &f.saidav);

		printf("Faca uma breve descricao da operacao:\n");
        fflush(stdin);
        gets(f.descricao);


		system("cls");

		printf("Confirma a saida [1 - SIM/ 2 - NAO]:\n\n");
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
			getchar();
			menu->menuFinanceiro();

		}
		else
		{
			menu->menuFinanceiro();
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


    fseek( fin, 0, SEEK_SET );
    fflush(fin);
    fflush(stdin);
    fflush(stdout);
    
    system("cls");
    
    printf("\t\tSaida\t\tDescricao\t\t");
    
    while ((fread(&f, sizeof(Financeiro), 1, fin))==1)
    {
	 	printf("\n\t\t%f\t\t ", f.saidav);
	 	printf("%s\n", f.descricao);	
	}
    getchar(); 
    menu->menuFinanceiro();
     
}
