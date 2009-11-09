/*
 * Financeiro.h
 *
 *  Created on: 01/11/2009
 *      Author: Helio
 */
#ifndef FINANCEIRO_H_
#define FINANCEIRO_H_

#include "Cabecalhos.h"

struct Financeiro
{
	float saldo;
	float entradav;
	float saidav;
	char descricao[30];
	char nome[30];
};

#endif /* FINANCEIRO_H_ */
