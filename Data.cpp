#include "Data.h"

bool Data::verificaAnoBissexto()
{
	bool divQuatro, divCem;

	divQuatro = ano % 4;
	divCem = ano % 100;

	// se o ano for divis�vel por 4 mas n�o for por 100, ano � bissexto
	if (divQuatro && !divCem)
		return true;
	// se for divis�vel por 400 (ou seja, por 4 e por 100), ent�o tamb�m � bissexto
	else if (divQuatro && divCem)
		return true;
	// caso n�o for nem divisivel por 4 nem por 100, ent�o � ano normal
	else
		return false;
		
}

int Data::forneceDiasMes ()
{
	// se m�s for menor que 8, m�s par tem 30 dias
	if (mes < 8 && mes != 2)
		if (mes % 2)
			return 30;
		else
			return 31;

	// se m�s for maior que 7, m�s par tem 31 dias
	else if (mes > 7)
		if (mes % 2)
			return 31;
		else
			return 30;

	// se for fevereiro
	else if (mes == 2)
		if (verificaAnoBissexto())
			return 29;
		else
			return 28;
}

bool Data::valida()
{
	if (mes < 1 || mes > 12)
		return false;

	if (dia < 1 || dia > forneceDiasMes())
		return false;

	return true;
}

void Data::grave()
{
	char buffer[5];

	printf("Entre o dia > ");
	fgets(buffer, sizeof(buffer), stdin);
	dia = atoi(buffer);

	printf("Entre o mes > ");
	fgets(buffer, sizeof(buffer), stdin);
	mes = atoi(buffer);

	printf("Entre o ano > ");
	fgets(buffer, sizeof(buffer), stdin);
	ano = atoi(buffer);

	while (!valida()) {
		printf("Data invalida! Entre o dia > ");
		fgets(buffer, sizeof(buffer), stdin);
		dia = atoi(buffer);
	
		printf("Entre o mes > ");
		fgets(buffer, sizeof(buffer), stdin);
		mes = atoi(buffer);
	
		printf("Entre o ano > ");
		fgets(buffer, sizeof(buffer), stdin);
		ano = atoi(buffer);
	}
}

void Data::mostre()
{
	printf("%d/%d/%d", dia, mes, ano);
}
