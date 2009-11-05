/*
 * Produtos.h
 *
 *  Created on: 04/11/2009
 *      Author: Luiz
 */
#ifndef PRODUTOS_H_
#define PRODUTOS_H_

#include "Cabecalhos.h"

struct Produtos{
  
   char codigo[20];
   char nomedoproduto[100];
   char fabricante[20];
   char validade[20];
   char quantidade[20];
   char preco[20];
	
};


#endif /* PRODUTOS_H_ */
