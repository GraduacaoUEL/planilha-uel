#include "ClienteFuncoes.h"

void ClienteFuncoes::inserirCliente()
{
	Cliente c;
	char esc;

	int localParaInserir, saida;

	fflush(stdin);
	printf("Nome do cliente => ");
	gets(c.nome);

	fflush(stdin);
	printf("\nCPF => ");
	gets(c.cpf);

	fflush(stdin);
	printf("\nData de nascimento => ");
	gets(c.nascimento);

	fflush(stdin);
	printf("\nTelefone Residencial =>");
	gets(c.telefoneResidencial);

	fflush(stdin);
	printf("\nTelefone Celular => ");
	gets(c.telefoneCelular);

	fflush(stdin);
	printf("\nCidade => ");
	gets(c.cidade);

	fflush(stdin);
	printf("\nBairro => ");
	gets(c.bairro);

	fflush(stdin); 
	printf("\nRua => ");
	gets(c.rua);

	fflush(stdin);
	printf("\nNumero => ");
	gets(c.numero);

	fflush(stdin);
	printf("\nCEP => ");
	gets(c.cep);

	localParaInserir = achaInsere(c.nome);

	fseek(arq, (localParaInserir)*sizeof(Cliente), 0);
	fwrite(&c, sizeof(Cliente), 1, arq);

	fflush(stdin);
	printf("\n\nCliente inserido!\n");
	getchar();
	fseek(arq, 0, 0);
	quantidadeDeClientes++;
	fflush(arq);
}

int ClienteFuncoes::achaCliente (char clienteParaAchar[100])
{
	Cliente *c, cli;
	int local;
	int i;

	c = new Cliente[quantidadeDeClientes+2];
	i = 0;

	fseek(arq, 0, 0 );
	fflush(arq);
	fflush(stdin);
	fflush(stdout);
 
	while ((fread(&c[i], sizeof(Cliente), 1, arq)) == 1)
		i++;


	local = busca(c, clienteParaAchar, 0, 0);

	delete(c);
	return local;
}

int ClienteFuncoes::achaInsere (char clienteParaAchar[100])
{
	Cliente *c,cli;
	int local;
	int i;
	int contador;

	c = new Cliente[quantidadeDeClientes+2];
	i = 0;

	fseek( arq, 0, 0 );
	fflush(arq);
	fflush(stdin);
	fflush(stdout);

 
	while ((fread(&c[i], sizeof(Cliente), 1, arq)) == 1)
		i++;

	local = busca(c,clienteParaAchar, 0, 0);

	contador = quantidadeDeClientes;

	while(contador > local)
	{
		c[contador] = c[contador-1];
		contador--;
	}

	fseek(arq, local*sizeof(Cliente), 0);
	for (i = local; i <= quantidadeDeClientes ;i++)
		fwrite(&c[i], sizeof(Cliente), 1, arq);

	delete(c);
	return local;
}

int ClienteFuncoes::busca (Cliente *c, char clienteParaAchar[100], int inicio, int posicao){
	bool verifica;

	if (quantidadeDeClientes != 0)
		while (c[inicio].nome[posicao] < clienteParaAchar[posicao] && inicio < quantidadeDeClientes)
		{
			if (posicao !=0 && c[inicio].nome[posicao-1] != clienteParaAchar[posicao-1])
				return inicio;
			else 
				verifica = true;
			inicio++;
		}

	if (c[inicio].nome[posicao] == clienteParaAchar[posicao])
		return busca(c,clienteParaAchar,inicio,posicao+1);

	return inicio;
} 
void ClienteFuncoes::removerCliente()
{
	Cliente c; 
	int localParaRemover;
	char opcao, clienteParaRemover[100];

	printf("Digite o nome do cliente que sera removido => ");
	fflush(stdin);
	gets(clienteParaRemover);

	localParaRemover = achaCliente(clienteParaRemover);

	fseek(arq, (localParaRemover)*sizeof(Cliente), 0);
	fread(&c, sizeof(Cliente), 1, arq);

	if (strcmp(clienteParaRemover, c.nome) !=0 )
	{
		printf("O cliente %s nao foi encontrado.", clienteParaRemover);
		getchar();
		return;
	}

	printf("Nome do Cliente => %s\n", c.nome);
	printf("CPF do Cliente => %s\n", c.cpf);

	do {
		printf("Tem certeza que deseja excluir? [S]im [N]ao => ");
		fflush(stdin);
		opcao = getchar();
		if (opcao == 's')
			c.nome[0]= '@';
	} while (opcao != 's' && opcao != 'n');

	fseek(arq, (localParaRemover)*sizeof(Cliente), 0);
	fwrite(&c, sizeof(Cliente), 1, arq);
}

void ClienteFuncoes::pedidos()
{
	Cliente c;
	char nomeDoClientePedindo[100];
	int localCorrente,opcao;

	fflush(stdin);
	printf("Insira o nome do cliente => ");
	gets(nomeDoClientePedindo);

	localCorrente = achaCliente( nomeDoClientePedindo);
	fseek(arq, localCorrente * sizeof(Cliente), 0);
	fread(&c, sizeof(Cliente), 1, arq);
	
	if (strcmp(nomeDoClientePedindo,c.nome) != 0)
	{
		printf("O cliente %s nao foi encontrado.", nomeDoClientePedindo);
		getchar();
		return;
	}

	fflush(stdin);
	printf("Digite 1 para visualizar os pedidos e 2 para efetuar pedidos =>");
	scanf("%d",&opcao);

	if (opcao == 1)
	{
		printf("Pedidos do cliente %s \n",c.nome);
		printf("Dia %s \n",c.data);
		printf("Pedido %s \n",c.pedido);
		fflush(stdin);
		getchar();
	}

	else if (opcao == 2) {
		fflush(stdin);
		printf("Digite o pedido para o cliente %s => ", c.nome);
		gets(c.pedido);

		strcpy(c.data, __DATE__);
		fseek(arq, localCorrente * sizeof(Cliente), 0);
		fwrite(&c, sizeof(Cliente),1,arq);

		printf("Pedido %s para inserido em %s.\n", c.pedido, __DATE__);
		fflush(stdin);
		getchar();
	}

	fseek(arq, 0, 0);
}
void ClienteFuncoes::mostrarClientes()
{
	Cliente c;

	fseek(arq, 0, 0 );
	fflush(arq);
	fflush(stdin);
	fflush(stdout);

	while ((fread(&c, sizeof(Cliente),1 ,arq)) == 1)
		if (c.nome[0] != '@')
		{
			printf("\nNome => %s", c.nome);
			printf("\nCPF => %s", c.cpf);
			printf("\nNascimento => %s", c.nascimento);
			printf("\nTelefone Residencia => %s", c.telefoneResidencial);
			printf("\nTelefone Celular => %s", c.telefoneCelular);
			printf("\nCidade => %s", c.cidade);
			printf("\nBairro => %s", c.bairro);
			printf("\nRua => %s", c.rua);
			printf("\nNumero => %s\n", c.numero);
		}

	getchar();
}

ClienteFuncoes::ClienteFuncoes()
{
		Cliente c;
		quantidadeDeClientes = 0;

	if ((arq = fopen("cliente.cli","rb+")) == NULL)
		if ((arq = fopen("cliente.cli","wb+")) == NULL)
		{ 
			printf("\nERRO");
			exit(1);
		}

	else
		while (fread(&c, sizeof(Cliente), 1, arq) == 1)
			quantidadeDeClientes++;

	fseek(arq, 0, 0);
}
 
 
ClienteFuncoes::~ClienteFuncoes()
{
	fclose(arq);
}

void ClienteFuncoes::vizualizarCliente()
{

	Cliente c;
	char nomeDoClientePedindo[100];
	int localCorrente;

	fflush(stdin);
	printf("Insira o nome do cliente => ");
	gets(nomeDoClientePedindo);

	localCorrente = achaCliente(nomeDoClientePedindo);
	fseek(arq, localCorrente * sizeof(Cliente), 0);
	fread(&c, sizeof(Cliente), 1, arq);

	if (strcmp(nomeDoClientePedindo, c.nome) != 0)
	{
		printf("O cliente %s nao foi encontrado", nomeDoClientePedindo);
		getchar();
		return;
	}

	else
	{
		printf("\nNome => %s", c.nome);
		printf("\nCPF => %s", c.cpf);
		printf("\nNascimento => %s", c.nascimento);
		printf("\nTelefone Residencia => %s", c.telefoneResidencial);
		printf("\nTelefone Celular => %s", c.telefoneCelular);
		printf("\nCidade => %s", c.cidade);
		printf("\nBairro => %s", c.bairro);
		printf("\nRua => %s", c.rua);
		printf("\nNumero => %s\n", c.numero);
		printf("\nPedido => %s ",c.pedido);
		printf("\nData => %s \n",c.data);
	}

	getchar();
}
