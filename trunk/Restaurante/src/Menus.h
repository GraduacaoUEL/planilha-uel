/*
 * Menus.h
 *
 *  Created on: 01/11/2009
 *      Author: helioalb
 */
#ifndef MENUS_H_
#define MENUS_H_

#include "Cabecalhos.h"
#include "Financeiro.h"

struct Financeiro;

struct Menus
{
	void principal(Financeiro caixa, Financeiro banco);
	void menuFinanceiro(Financeiro f);
};


#endif /* MENUS_H_ */
