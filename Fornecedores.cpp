#include "Fornecedores.h"

// usar construtor/destrutor aqui preferencialmente
void Fornecedores::graveFornecedor() {
	char buffer[31];
	Fornecedores temp;
	int gravar;

	printf("CADASTRO DE FORNECEDORES\n");

	printf("Entre o nome do fornecedor > ");
	fgets(temp.nome, sizeof(temp.nome), stdin);

	printf("Entre o CNPJ (com pontos, barras e hifens) > ");
	fgets(temp.cnpj, sizeof(temp.cnpj), stdin);

	printf("Entre o endereco > ");
	fgets(temp.endereco, sizeof(temp.endereco), stdin);

	printf("Entre a cidade > ");
	fgets(temp.cidade, sizeof(temp.cidade), stdin);

	printf("Entre o estado (2 letras) > ");
	fgets(temp.estado, sizeof(temp.estado), stdin);

	printf("Entre o telefone > ");
	fgets(temp.telefone, sizeof(temp.telefone), stdin);

	printf("\nCONFIRME OS DADOS\n");
	temp.leiaFornecedor();

	printf("\n\nEstao corretos? (1)Sim (2)Nao > ");
	fgets(buffer, 2, stdin);
	gravar = atoi(buffer);

	if (gravar == 2)
	{
		printf("Cancelando...\nPor favor efetue novamente o cadastro.\n\n");
	}
	else if (gravar == 1)
	{
		strcpy(nome, temp.nome);
		strcpy(cnpj, temp.cnpj);
		strcpy(endereco, temp.endereco);
		strcpy(cidade, temp.cidade);
		strcpy(estado, temp.estado);
		strcpy(telefone, temp.telefone);
		printf("Cadastrado com sucesso!\nCaso queira atualizar os dados, utilize a opcao disponivel no menu.\n");
	}
}

void Fornecedores::leiaFornecedor()
{
	printf("Razao Social: %s", nome);
	printf("CNPJ: %s", cnpj);
	printf("Endereco: %s", endereco);
	printf("Cidade: %s", cidade);
	printf("Estado: %s", estado);
	printf("Telefone: %s", telefone);
}

void Fornecedores::atualizaFornecedor () {
}

void Fornecedores::atualizaStatus() {
}

void Fornecedores::mostreStatus()
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
