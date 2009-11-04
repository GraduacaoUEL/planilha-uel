#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct Data
{
	int dia;
	int mes;
	int ano;

	void grave();
	void mostre();

	// funções auxiliares
	// código de validação copiado-colado de outro projeto
	bool verificaAnoBissexto();
	int forneceDiasMes();
	bool valida();
};

bool Data::verificaAnoBissexto()
{
	bool divQuatro, divCem;

	divQuatro = ano % 4;
	divCem = ano % 100;

	// se o ano for divisível por 4 mas não for por 100, ano é bissexto
	if (divQuatro && !divCem)
		return true;
	// se for divisível por 400 (ou seja, por 4 e por 100), então também é bissexto
	else if (divQuatro && divCem)
		return true;
	// caso não for nem divisivel por 4 nem por 100, então é ano normal
	else
		return false;
}

int Data::forneceDiasMes ()
{
	// se mês for menor que 8, mês par tem 30 dias
	if (mes < 8 && mes != 2)
		if (mes % 2)
			return 30;
		else
			return 31;

	// se mês for maior que 7, mês par tem 31 dias
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
		ano = atoi(buffer)
	}
}

void Data::mostre()
{
	printf("%d/%d/%d", dia, mes, ano);
}

typedef struct Fornecedores
{
	int id;

	char nome[101];
	int cnpj;
	char endereco[101];
	char cidade[51];
	char estado[3];
	int telefone[2];

	Data compra, previsao, entrega;
	bool comprou, entregue;

	void graveFornecedor();
	void leiaFornecedor();
	void atualizaFornecedor();
	void mostreStatus();
	void atualizaStatus();
};

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

int main (void) {
	Fornecedores teste;
	teste.graveFornecedor();
	teste.leiaFornecedor();
	system("pause");
}
