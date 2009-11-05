 /*
 *  Fornecedor.h
 *
 *  Created on: 04/11/2009
 *      Author: Hayato
 */
#ifndef FORNECEDOR_H_
#define FORNECEDOR_H_

#include "Cabecalhos.h"
#include "Data.h"

typedef struct Fornecedor
{
	char nome[100];
	char cnpj[20];
	char endereco[100];
	char cidade[50];
	char estado[5];
	char telefone[20];

	Data compra, previsao, entrega;
	bool comprou, entregue;
	
	bool apagar;
	
	void leiaFornecedor();
	void mostreStatus();
};

#endif /* FORNECEDOR_H_ */
