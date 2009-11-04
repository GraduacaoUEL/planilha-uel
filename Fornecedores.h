 /*
 * Fornecedores.h
 *
 *  Created on: 01/11/2009
 *      Author: Hayato
 */
#ifndef FORNECEDORES_H_
#define FORNECEDORES_H_

#include "Cabecalhos.h"
#include "Data.h"

typedef struct Fornecedores
{
	char nome[100];
	char cnpj[20];
	char endereco[100];
	char cidade[50];
	char estado[5];
	char telefone[20];

	Data compra, previsao, entrega;
	bool comprou, entregue;

	void graveFornecedor();
	void leiaFornecedor();
	void atualizaFornecedor();
	void mostreStatus();
	void atualizaStatus();
};
#endif /* FINANCEIRO_H_ */
