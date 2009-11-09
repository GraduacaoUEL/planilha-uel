/*
 * Cliente.h
 *
 *  Created on: 03/11/2009
 *      Author: helioalb
 */
#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Cabecalhos.h"

struct Cliente {
	char cpf[20];
	char nome[100];
   
	char telefoneResidencial[20];
	char telefoneCelular[20];
	char cidade[100];
	char cep[20];
	char rua[100];
	char complemento[100];
	char numero[100];
	char nascimento[10];
	char bairro[100];
	char pedido[100];
	char data[100];	
};

#endif /* CLIENTE_H_ */
