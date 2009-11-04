/*
 * Financeiro.h
 *
 *  Created on: 01/11/2009
 *      Author: Hayto
 */
#ifndef DATA_H_
#define DATA_H_

#include "Cabecalhos.h"

typedef struct Data
{
	int dia;
	int mes;
	int ano;

	void grave();
	void mostre();

	// fun��es auxiliares
	// c�digo de valida��o copiado-colado de outro projeto
	bool verificaAnoBissexto();
	int forneceDiasMes();
	bool valida();
};

#endif /* DATA_H_ */
