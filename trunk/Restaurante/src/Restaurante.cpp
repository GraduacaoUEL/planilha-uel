//============================================================================
// Name        : Restaurante.cpp
// Author      : UEL
// Version     :
// Copyright   : 
// Description :
//============================================================================
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Financeiro;
struct Menus;

struct Menus
{
	//Aqui eu quero colocar algo como: Financeiro algumaCoisa;
    void principal(Financeiro caixa, Financeiro banco);
	void menuFinanceiro(Financeiro f);
};

struct Financeiro
{
	double saldo;
	char nome[30];
	struct Menus menu;

	Financeiro(char* );
	void entrada(Financeiro f);
	void saida();
	void contasAPagar();
	void contasAReceber();
	void historicoEntrada();
	void historicoSaida();
	//void relatorioAPagar();
	//void relatorioAReceber();
};


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
		menu.menuFinanceiro(f);
	}

}


void Financeiro::saida()
{

}

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
		printf("( 7 ) Sair\n");

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
	}
}

int main(int argc, char *argv[])
{
	Financeiro caixa("CAIXA"); //O nome do parametro eh o que aparece no menu do modulo financeiro
	Financeiro banco("BANCO");
	struct Menus menu;

	menu.principal(caixa, banco);
}
