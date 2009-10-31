//============================================================================
// Name        : Restaurante.cpp
// Author      : UEL
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Financeiro
{
    double saldo;
    char nome[30];


    void entrada();
    void saida();
    void agendados();
    void historicoEntrada();
    void historicoSaida();
};

struct Menus
{
    void menuFinanceiro(Financeiro f);
};


void Financeiro::entrada()
{

	printf("Voce digitou 1\n");

}



void Financeiro::saida()
{
		printf("Voce digitou 2\n");
}

void Financeiro::agendados()
{
		printf("Voce digitou 3\n");
}

void Financeiro::historicoEntrada()
{
		printf("Voce digitou 4\n");
}

void Financeiro::historicoSaida()
{
		printf("Voce digitou 5\n");
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
       printf("( 4 ) Historico de Entradas\n");
       printf("( 5 ) Historico de Saidas\n");
       printf("( 6 ) Sair\n");

       scanf("%d", &op);
      }while(op < 1 && op > 6);

      switch(op)
      {
          case 1:
		f.entrada();
          break;

          case 2:
		f.saida();
          break;


          case 3:
		f.agendados();
          break;


          case 4:
		f.historicoEntrada();
          break;


          case 5:
		f.historicoSaida();

	  menuFinanceiro(f);


          break;


          case 6:
		printf("Voce digitou 6\n");
          break;

      }
}

int main(int argc, char *argv[])
{
    Financeiro caixa;
    strcpy(caixa.nome, "CAIXA"); //FAZER ESTA PARTE COM CONSTRUTOR

    Financeiro banco;
    strcpy(banco.nome, "BANCO"); //FAZER ESTA PARTE COM CONSTRUTOR

   struct Menus menu;

    menu.menuFinanceiro(banco);
}
