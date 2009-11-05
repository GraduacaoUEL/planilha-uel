#include "FornecedorFuncoes.h"

FornecedorFuncoes::FornecedorFuncoes()
{
	FILE* arq;
	Fornecedor temp;
	int conta;
	int statusLeitura;

	arq = fopen("fornecedor.frn", "rb");
	qteFornecedores = 0;

	if (arq == NULL) {
//		printf("Arquivo fornecedor.frn nao carregado.\nSera criado um ao final da execucao.\n\n");
		fornece = new Fornecedor[100];

	}
	else
	{
		// vê quantas entradas tem no arq.
		while (fread(&temp, sizeof(Fornecedor), 1, arq) == 1)
			qteFornecedores++;

		// volta pro começo do arquivo
		fseek(arq, 0, SEEK_SET);

		// alocação "dinâmica"
		fornece = new Fornecedor[qteFornecedores+100];

		if (fornece == NULL)
			printf("ERRO! Nao ha memoria suficiente para ler o arquivo!\n\n");
		else {
			statusLeitura = 0;

			for (conta = 0; conta < qteFornecedores; conta++)
				statusLeitura += fread(&fornece[conta], sizeof(Fornecedor), 1, arq);

			if (statusLeitura != qteFornecedores)
				printf("ERRO! Houve um erro de leitura do arquivo ja existente!\n\n");

//			printf("Debug: %d lidos / %ld total\n\n", statusLeitura, qteFornecedores);
			fclose(arq);
		}
	}
}

FornecedorFuncoes::~FornecedorFuncoes()
{
	FILE* arq;
	Fornecedor temp;
	int conta;

	arq = fopen("fornecedor.frn", "wb");

	if (arq == NULL)
		printf("Falha ao criar arquivo.\n");
	else
		for (conta = 0; conta < qteFornecedores; conta++)
			if (!fornece[conta].apagar)
				fwrite(&fornece[conta], sizeof(Fornecedor), 1, arq);

	fclose(arq);
	delete(fornece);
}

void FornecedorFuncoes::graveFornecedor() {
	char buffer[5];
	Fornecedor temp;
	int gravar;
	int cpnjRepetido;

	printf("CADASTRO DE FORNECEDORES\n\n");

	printf("Entre o nome do fornecedor > ");
	fgets(temp.nome, sizeof(temp.nome), stdin);

	printf("Entre o CNPJ (com pontos, barras e hifens) > ");
	fgets(temp.cnpj, sizeof(temp.cnpj), stdin);

	while (verificaCNPJ(temp.cnpj) != -1) {
		printf("Atencao! O CNPJ deve ser unico para cada empresa!\n");
		printf("Entre o CNPJ (com pontos, barras e hifens) > ");
		fgets(temp.cnpj, sizeof(temp.cnpj), stdin);
	}

	printf("Entre o endereco > ");
	fgets(temp.endereco, sizeof(temp.endereco), stdin);

	printf("Entre a cidade > ");
	fgets(temp.cidade, sizeof(temp.cidade), stdin);

	printf("Entre o estado (2 letras) > ");
	fgets(temp.estado, sizeof(temp.estado), stdin);

	printf("Entre o telefone > ");
	fgets(temp.telefone, sizeof(temp.telefone), stdin);
	
	temp.apagar = false;
	temp.comprou = false;
	temp.entregue = false;

	printf("\nCONFIRME OS DADOS\n");
	temp.leiaFornecedor();

	printf("\nEstao corretos? (1)Sim (2)Nao > ");
	fgets(buffer, 2, stdin);
	gravar = atoi(buffer);

	if (gravar == 2)
	{
		printf("Cancelando...\nPor favor efetue novamente o cadastro.\n\n");
	}
	else if (gravar == 1)
	{
		fornece[qteFornecedores] = temp;
//		temp.leiaFornecedor();
//		printf("No. de Registro: %d\n", qteFornecedores);
		qteFornecedores++;
		printf("Cadastrado com sucesso!\nCaso queira atualizar ou corrigir os dados, utilize a opcao Atualizar.\n\n");
	}
}

void FornecedorFuncoes::leiaFornecedores ()
{
	int conta;
	
	printf("EXIBIR TODOS OS FORNECEDORES\n\n");
	if (!qteFornecedores)
		printf("Nenhum fornecedor cadastrado!\n");
	else
		for (conta = 0; conta < qteFornecedores; conta++) {
			if (!fornece[conta].apagar) {
				fornece[conta].leiaFornecedor();
				fornece[conta].mostreStatus();
				printf("\n\n");
			}
		}
}

int FornecedorFuncoes::verificaCNPJ (char* cnpj) {
	int resultado;
	int conta;

	resultado = -1;
	
	for (conta = 0; conta < qteFornecedores; conta++) {
		if (strcmp(cnpj, fornece[conta].cnpj) == 0) {
			resultado = conta;
			break;
		}
	}
	return resultado;
}

int FornecedorFuncoes::buscaFornecedor ()
{
	int numero;
	int conta;
	char cnpj[30];
	
	numero = -1;
	
	printf("Entre o CNPJ (incluindo pontos, barras e hifens) > ");
	fgets(cnpj, sizeof(cnpj), stdin);
		
	for (conta = 0; conta < qteFornecedores; conta++)
		if (strcmp(cnpj, fornece[conta].cnpj) == 0) {
			numero = conta;
//			printf("ID: %d\n", numero);
			break;	
		}
	return numero;
}

void FornecedorFuncoes::leiaFornecedorUnico (int numRegistro)
{

	if (numRegistro >= 0 && !fornece[numRegistro].apagar)
	{
		fornece[numRegistro].leiaFornecedor();
		fornece[numRegistro].mostreStatus();
		printf("\n\n");
	}
	else {
//		printf("ID: %d\n", numRegistro);
		printf("CNPJ invalido ou nao cadastrado\n\n");
	}
}


void FornecedorFuncoes::mostreStatus (int numRegistro)
{
	if (numRegistro >= 0 && !fornece[numRegistro].apagar)
	{
		fornece[numRegistro].mostreStatus();
		printf("\n\n");
	 } else
		printf("CNPJ invalido ou nao cadastrado\n\n");

}

void FornecedorFuncoes::atualizaFornecedor (int numRegistro)
{
	char buffer[5];
	Fornecedor temp;
	int gravar;

	if (numRegistro >= 0 && !fornece[numRegistro].apagar)
	{
		printf("Atulizar fornecedor %s", fornece[numRegistro].nome);
		strcpy(temp.nome, fornece[numRegistro].nome);

		printf("CNPJ: %s", fornece[numRegistro].cnpj);
		strcpy(temp.cnpj, fornece[numRegistro].cnpj);

		printf("\nCaso nao queira alterar um campo, aperte somente Enter.\n\n");
	
		printf("Endereco atual: %s", fornece[numRegistro].endereco);
		printf("Entre o novo endereco > ");
		fgets(temp.endereco, sizeof(temp.endereco), stdin);
		
		if (strlen(temp.endereco) == 1)
			strcpy(temp.endereco, fornece[numRegistro].endereco);
	
		printf("Cidade atual: %s", fornece[numRegistro].cidade);
		printf("Entre a nova cidade > ");
		fgets(temp.cidade, sizeof(temp.cidade), stdin);
		
		if (strlen(temp.cidade) == 1)
			strcpy(temp.cidade, fornece[numRegistro].cidade);
	
		printf("Estado atual: %s", fornece[numRegistro].estado);
		printf("Entre o novo estado (2 letras) > ");
		fgets(temp.estado, sizeof(temp.estado), stdin);
		
		if (strlen(temp.estado) == 1)
			strcpy(temp.estado, fornece[numRegistro].estado);
	
		printf("Telefone atual: %s", fornece[numRegistro].telefone);
		printf("Entre o novo telefone > ");
		fgets(temp.telefone, sizeof(temp.telefone), stdin);
		
		if (strlen(temp.telefone) == 1)
			strcpy(temp.telefone, fornece[numRegistro].telefone);
	
		temp.apagar = false;
		temp.comprou = fornece[numRegistro].comprou;
		temp.previsao = fornece[numRegistro].previsao;
		temp.entregue = fornece[numRegistro].entregue;
		temp.entrega = fornece[numRegistro].entrega;

		printf("\nCONFIRME OS DADOS\n");
		temp.leiaFornecedor();

		do {
			printf("\nEstao corretos? (1)Sim (2)Nao > ");
			fgets(buffer, 2, stdin);
			gravar = atoi(buffer);
		} while (gravar != 1 && gravar != 2);
	
		if (gravar == 2)
		{
			printf("Cancelando atualizacao...\n\n");
		}
		else if (gravar == 1)
		{
			fornece[numRegistro] = temp;
			printf("Atualizacao efetuada com sucesso!\n\n");
		}
	}
	else
		printf("CNPJ invalido ou nao cadastrado\n\n");
}

void FornecedorFuncoes::atualizaStatus (int numRegistro)
{
	Data temp[2];
	char buffer[5];
	int op;
	int grava;

	if (numRegistro >= 0 && !fornece[numRegistro].apagar)
	{
		printf("Fornecedor %s", fornece[numRegistro].nome);
		
		if (!fornece[numRegistro].comprou) {
			printf("\nNada foi comprado deste fornecedor.\n");
			
			do {
				printf("\nInserir data de compra e previsao de chegada? (1)Sim (2)Nao > ");
				fgets(buffer, sizeof(buffer), stdin);
				op = atoi(buffer);
			} while (op != 1 && op != 2);
		}
		else
		{
			if (fornece[numRegistro].entregue)
			{
				printf("A compra efetuada no dia");
				fornece[numRegistro].compra.mostre();
				printf("chegou.\n");
			}
			else
			{
				printf("Foi efetuada um compra em");
				fornece[numRegistro].compra.mostre();
				printf(".\nA previsao de chegada esta para o dia");
				fornece[numRegistro].previsao.mostre();
				printf(".\n");
			}	
			
			do {
				printf("Atualizar data de compra e previsao de chegada? (1)Sim (2)Nao > ");
				fgets(buffer, sizeof(buffer), stdin);
				op = atoi(buffer);
			} while (op != 1 && op != 2);
		}
		
		if (op == 1)
		{
			printf("Data de compra:\n");
			temp[0].grave();
			
			fflush(stdin);
			printf("\nData prevista de chegada:\n");
			temp[1].grave();
			fflush(stdin);
			
			printf("\n\nCONFIRME OS DADOS\n");
			printf("Data de compra: ");
			temp[0].mostre();
			printf("\nData prevista para chegada: ");
			temp[1].mostre();
			printf("\n\n");
			
			do {
				fflush(stdin);
				printf("Dados estao corretos? (1)Sim (2)Nao > ");
				fgets(buffer, sizeof(buffer), stdin);
				grava = atoi(buffer);
				fflush(stdin);
			} while (grava != 1 && grava != 2);
			
			if (grava == 1)
			{
				fornece[numRegistro].compra = temp[0];
				fornece[numRegistro].previsao = temp[1];
				fornece[numRegistro].comprou = true;
				fornece[numRegistro].entregue = false;
				printf("Status do fornecedor atulizados com sucesso!\n\n");
			}
			else if (grava == 2)
				printf("Cancelando alteracoes...");
			
		}
		else if (op == 2)
			printf("Cancelando alteracoes...\n\n");

	}
	else
		printf("CNPJ invalido ou nao cadastrado\n\n");
}

void FornecedorFuncoes::apagarFornecedor (int numRegistro)
{
	char buffer[5];
	int apaga;

	if (numRegistro >= 0 && !fornece[numRegistro].apagar)
	{
		leiaFornecedorUnico(numRegistro);
		
		do {
			printf("\n\nTem certeza que deseja apagar o fornecedor? (1)Nao (2)Sim > ");
			fgets(buffer, 2, stdin);
			apaga = atoi(buffer);
		} while (apaga != 1 && apaga != 2);

		if (apaga == 1)
		{
			printf("Cancelando descadastamento...\n\n");
		}
		else if (apaga == 2)
		{
			fornece[numRegistro].apagar = true;
			printf("Descadastramento efetuado com sucesso!\n\n");
		}
	}
	else
		printf("CNPJ invalido ou nao cadastrado\n\n");
}
