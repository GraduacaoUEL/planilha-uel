 /*
 * Financeiro.h
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
	int id;

	char nome[101];
	int cnpj;
	char endereco[101];
	char cidade[51];
	char estado[3];
	int telefone[2];

	Data compra, previsao, entrega;
	bool comprou, entregue;

	void graveFornecedor();
	void leiaFornecedor();
	void atualizaFornecedor();
	void mostreStatus();
	void atualizaStatus();
};
#endif /* FINANCEIRO_H_ */
