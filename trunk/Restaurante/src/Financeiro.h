/*
 * Financeiro.h
 *
 *  Created on: 01/11/2009
 *      Author: helioalb
 */
#ifndef FINANCEIRO_H_
#define FINANCEIRO_H_

#include "Cabecalhos.h"

#include "Menus.h"

struct Menus;

struct Financeiro
{
	double saldo;
	char nome[30];

	struct Menus *menu;

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

#endif /* FINANCEIRO_H_ */
