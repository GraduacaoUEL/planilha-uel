//============================================================================
// Name        : Restaurante.cpp
// Author      : UEL
// Version     :
// Copyright   : 
// Description :
//============================================================================
#include "Financeiro.h"
#include "Menus.h"

struct Financeiro;
struct Menus;

int main(int argc, char *argv[])
{
	Financeiro caixa("CAIXA"); //O nome do parametro eh o que aparece no menu do modulo financeiro
	Financeiro banco("BANCO");
	struct Menus menu;

	menu.principal(caixa, banco);
}
