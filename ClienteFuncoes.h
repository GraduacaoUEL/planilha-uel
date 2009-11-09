/*
 * Cliente.h
 *
 *  Created on: 03/11/2009
 *      Author: Vinicius
 */
#ifndef CLIENTEFUNCOES_H_
#define CLIENTEFUNCOES_H_

#include "Cabecalhos.h"
#include "Cliente.h"

struct 	ClienteFuncoes{
	FILE * arq;	
	Cliente c;
	int *clientesNaMemoria;
	int quantidadeDeClientes;

	void mostrarClientes();
	void vizualizarCliente(); 
    void inserirCliente();
    void removerCliente();
    void pedidos();
    int achaCliente(char nome[100]);
	int achaInsere(char nome[100]);
	int busca(Cliente *c,char clienteParaAchar[100],int inicio, int posicao);

	ClienteFuncoes();
	~ClienteFuncoes();


//	void menu();
};   

#endif /* CLIENTEFUNCOES_H_ */
