/*
 * ProdutosFuncoes.h
 *
 *  Created on: 04/11/2009
 *      Author: Luiz
 */
#ifndef PRODUTOSFUNCOES_H_
#define PRODUTOSFUNCOES_H_

#include "Cabecalhos.h"
#include "Produtos.h"

struct 	ProdutosFuncoes{
	FILE * arq;	
	Produtos p;
    int *produtosNaMemoria;
	int quantidadeDeProdutos;
    void inserirProduto();
    void removerProduto(); 
    void mostrarProduto();
    int achaProduto(char nomedoproduto[100]);
    int achaInsere(char nomedoproduto[100]);
   	int ProdutosFuncoes::busca(Produtos *p,char produtoParaAchar[100],int inicio, int posicao);
	ProdutosFuncoes();
	~ProdutosFuncoes();
    struct  Menus *menu;
//	void menu();
};

#endif /* PRODUTOSFUNCOES_H_ */
