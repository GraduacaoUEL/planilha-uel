 /*
 * FornecedorFuncoes.h
 *
 *  Created on: 04/11/2009
 *      Author: Hayato
 */
#ifndef FORNECEDORFUNCOES_H_
#define FORNECEDORFUNCOES_H_

#include "Cabecalhos.h"
#include "Fornecedor.h"
#include "Menus.h"

typedef struct FornecedorFuncoes {
	Fornecedor* fornece;
	int qteFornecedores;
	
	// construtor e destrutor
	// construtor lê, destrutor escreve
	FornecedorFuncoes();
	~FornecedorFuncoes();

	// manipulacao de memoria
	void graveFornecedor();
	int verificaCNPJ (char* cnpj);
	void leiaFornecedores();
	
	int buscaFornecedor();

	void leiaFornecedorUnico (int numRegistro);
	void atualizaFornecedor (int numRegistro);

	void mostreStatus (int numRegistro);
	void atualizaStatus (int numRegistro);
	
	void apagarFornecedor (int numRegistro);
	

};
#endif /* FORNECEDORFUNCOES_H_ */
