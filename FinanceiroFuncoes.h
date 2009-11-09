/*
 * FinanceiroFuncoes.h
 *
 *  Created on: 01/11/2009
 *      Author: Helio
 */
#ifndef FINANCEIROFUNCOES_H_
#define FINANCEIROFUNCOES_H_

#include "Cabecalhos.h"
#include "Financeiro.h"

struct FinanceiroFuncoes
{
	FILE *fin, *sld;
	struct Menus *menu;

	FinanceiroFuncoes();
//	~FinanceiroFuncoes();

	void entrada();
	void saida();
	//void contasAPagar();
	//void contasAReceber();
	void historicoEntrada();
	void historicoSaida();
	//void relatorioAPagar();
	//void relatorioAReceber();
};

#endif /* FINANCEIROFUNCOES_H_ */
