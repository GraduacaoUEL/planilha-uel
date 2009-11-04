#include "Fornecedores.h"
// usar construtor/destrutor aqui preferencialmente
void Fornecedores::graveFornecedor() {
	char buffer[31];
	Fornecedores temp;
	int gravar;
	

	printf("CADASTRO DE FORNECEDORES\n");

	printf("Entre o nome do fornecedor > ");
//	scanf("%[^\n]", temp.nome);
	fgets(temp.nome, sizeof(temp.nome), stdin);

	printf("Entre o CNPJ (somente numeros) > ");
	fgets(buffer, sizeof(buffer), stdin);
	temp.cnpj = atoi(buffer);

	printf("Entre o endereco > ");
//	scanf("%[^\n]", temp.endereco);
	fgets(temp.endereco, sizeof(temp.endereco), stdin);

	printf("Entre a cidade > ");
//	scanf("%[^\n]", temp.cidade);
	fgets(temp.cidade, sizeof(temp.cidade), stdin);

	printf("Entre o estado (2 letras) > ");
//	scanf("%[^\n]", temp.estado);
	fgets(temp.estado, sizeof(temp.estado), stdin);

	printf("Entre o DDD > ");
	fgets(buffer, sizeof(buffer), stdin);
	temp.telefone[0] = atoi(buffer);
	
	printf("Entre o telefone > ");
	fgets(buffer, sizeof(buffer), stdin);
	temp.telefone[1] = atoi(buffer);

	printf("\nConfirme os dados\n");
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
		cnpj = temp.cnpj;
		strcpy(endereco, temp.endereco);
		strcpy(cidade, temp.cidade);
		strcpy(estado, temp.estado);
		telefone[0] = temp.telefone[0];
		telefone[1] = temp.telefone[1];
		printf("Cadastrado com sucesso!\nCaso queira atualizar os dados, utilize a opcao disponivel no menu.\n");
	}
}

void Fornecedores::leiaFornecedor()
{
	printf("Razao Social: %s", nome);
	printf("CNPJ: %d\n", cnpj);
	printf("Endereco: %s", endereco);
	printf("Cidade: %s", cidade);
	printf("Estado: %s\n", estado);
	printf("Telefone: (%d) %d\n", telefone[0], telefone[1]);
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
