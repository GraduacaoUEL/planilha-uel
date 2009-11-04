/*
 * Cliente.h
 *
 *  Created on: 03/11/2009
 *      Author: Vinicius
 */

#ifndef CLIENTEFUNCOES_H_
#define CLIENTEFUNCOES_H_

#include "Cabecalhos.h"

struct 	ClienteFuncoes{
	FILE * arq;	
	Cliente c;
	int *clientesNaMemoria;
	int quantidadeDeClientes;
	void mostrarClientes();   
    void inserirCliente();
    void removerCliente();
    void pedidos();
    int achaCliente(char nome[100]);
	ClienteFuncoes();
	~ClienteFuncoes();
	void menu();
};   


#endif /* CLIENTEFUNCOES_H_ */
