#include "Fornecedor.h"

void Fornecedor::leiaFornecedor()
{
	printf("Razao Social: %s", nome);
	printf("CNPJ: %s", cnpj);
	printf("Endereco: %s", endereco);
	printf("Cidade: %s", cidade);
	printf("Estado: %s", estado);
	printf("Telefone: %s", telefone);
}

void Fornecedor::mostreStatus()
{
	if (comprou)
	{
		printf("Data da ultima compra: ");
		compra.mostre();
		printf("\n");
			if (entregue)
			{
				printf("Pedido entregue em: ");
				entrega.mostre();
				printf("\n");
			}
			else
			{
				printf("Data prevista para chegada em: ");
				previsao.mostre();
				printf("\n");
			}
	}
	else
		printf("Nada foi comprado deste fornecedor.\n");

}
