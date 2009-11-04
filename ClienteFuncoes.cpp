#include "ClienteFuncoes.h"

void ClienteFuncoes::inserirCliente(){
   
   Cliente c;
   char esc;
   
   int localParaInserir,saida;
      
   
   
	fflush(stdin);
   printf("Nome do cliente\t");
   gets(c.nome);
   
 /*  fflush(stdin);
   printf("CPF\t");
   gets(c.cpf);
   
   fflush(stdin);
   printf("\nData de nascimento\t");
   gets(c.nascimento);
   
   fflush(stdin);
	printf("\nTelefone Residencial \t");
   gets(c.telefoneResidencial);
   
	fflush(stdin);
   printf("\nTelefone Celular\t");
   gets(c.telefoneCelular);
   
   fflush(stdin);
	printf("\nCidade\t");
   gets(c.cidade);
   
   fflush(stdin);
	printf("\nBairro\t");
   gets(c.bairro);
   
	fflush(stdin); 
   printf("\nRua\t");
   gets(c.rua);
   
   fflush(stdin);
	printf("\nNumero\t");
   gets(c.numero);
   
   fflush(stdin);
	printf("\nCEP\t");
   gets(c.cep);
   
  */ 
   
	localParaInserir = achaInsere(c.nome );
   
		
	
   fseek(arq,(localParaInserir)*sizeof(Cliente),0);
	fwrite(&c,sizeof(Cliente),1,arq);
	
	fflush(stdin);
   printf("\n\nCliente inserido\n");
   getchar();
   
	quantidadeDeClientes++;    
	fflush(arq);
	
	
	
}

int ClienteFuncoes::achaCliente(char clienteParaAchar[100]){
   Cliente *c,cli;
	int local;
	c = new Cliente[quantidadeDeClientes];
	int i;
	i = 0;
	
	fseek( arq, 0, SEEK_SET );
	fflush(arq);
	fflush(stdin);
   fflush(stdout);
	
 
    while ((fread(&c[i],sizeof(Cliente),1,arq))==1) 	
	 {
		i++;
	 }
	
   local = busca(c,clienteParaAchar,0,0);
	
	delete(c);
	return local;
}

int ClienteFuncoes::achaInsere(char clienteParaAchar[100]){
   Cliente *c,cli;
	int local;
	c = new Cliente[quantidadeDeClientes+2];
	int i;
	i = 0;
	
	fseek( arq, 0, 0 );
	fflush(arq);
	fflush(stdin);
   fflush(stdout);
	
 
    while ((fread(&c[i],sizeof(Cliente),1,arq))==1) 	
	 {
		i++;
	 }
	
   local = busca(c,clienteParaAchar,0,0);
	printf("local%d",local);
	int contador;
	contador = quantidadeDeClientes;
	
	while(contador > local)
		{
			c[contador] = c[contador-1];
			contador--;
	}
	
	fseek(arq,local*sizeof(Cliente),0);
	for(int i = local; i <= quantidadeDeClientes ;i++)
		fwrite(&c[i],sizeof(Cliente),1,arq);
	
	
	delete(c);
	return local;
} 
int ClienteFuncoes::busca(Cliente *c,char clienteParaAchar[100],int inicio,int posicao){
	

	while( inicio < quantidadeDeClientes && (clienteParaAchar[posicao] <= c[inicio].nome[posicao]  ))
		inicio++;
	if(clienteParaAchar[posicao] < c[inicio].nome[posicao])
		{
			if(quantidadeDeClientes ==0  )
				return inicio;
			else 
				return inicio;
	}else if (quantidadeDeClientes != inicio)
		return busca(c,clienteParaAchar,inicio,posicao+1);	
	else 
	return inicio;
}		
		
	
        
void ClienteFuncoes::removerCliente(){
	Cliente c; 
	int localParaRemover;
   char opcao,clienteParaRemover[100];
   
     
	printf("Digite o nome do cliente que sera removido\t");
   fflush(stdin);
	gets(clienteParaRemover);
   
	localParaRemover = achaCliente(clienteParaRemover);
   printf("Local para remover  => %d \n",localParaRemover);
   fseek(arq, (localParaRemover) * sizeof(Cliente), 0);
	fread(&c, sizeof( Cliente), 1, arq);

	printf("Nome do cliente => %s  ",c.nome);
   printf("CPF do Cliente => %s  ",c.cpf);
  	printf("Tem certeza que deseja excluir ? \n[s]im \tn[n]ao");
   getchar();
   
  	}	 
void ClienteFuncoes::pedidos(){
	
	Cliente c;
	char nomeDoClientePedindo[100];
	int localCorrente;
	
	
	printf("Insira o nome do cliente");
	gets(nomeDoClientePedindo);
	localCorrente = achaCliente( nomeDoClientePedindo);
	fseek(arq, localCorrente * sizeof(Cliente), 0);
	fread(&c, sizeof(struct Cliente), 1, arq);
	printf("Digite o pedido para o cliente %s e 0 para cancelar ",c.nome);
	int i =0;
	do{
		fflush(stdin);
		scanf("%s",c.pedido);
	}while(c.pedido[i][0] != '0');
	strcpy(c.data,__DATE__);

}
void ClienteFuncoes::mostrarClientes(){

    fseek( arq, 0, 0 );
	 fflush(arq);
	 fflush(stdin);
    fflush(stdout);
	 Cliente c;
    
    while ((fread(&c,sizeof(Cliente),1,arq))==1)
    {
	 	printf("\nNome => %s ",c.nome);
	 	printf("\nCPF => %s ",c.cpf);	
	 	printf("\nNascimento => %s ",c.nascimento);
		printf("\nTelefone Residencia => %s ",c.telefoneResidencial);
	 	printf("\nTelefone Celular => %s ",c.telefoneCelular);
	 	printf("\nCidade => %s ",c.cidade);
	 	printf("\nBairro => %s ",c.bairro);
	 	printf("\nRua => %s ",c.rua);
	 	printf("\nNumero => %s \n",c.numero);
	}
    getchar();
}

ClienteFuncoes::ClienteFuncoes()
{
  if ((arq = fopen("cliente.cli","rb+"))==NULL)
  {  if ((arq = fopen("cliente.cli","wb+"))==NULL)
     {  printf("\nERRO");
        exit(1);
     }
     quantidadeDeClientes = 0;
  }else{
	
       Cliente c;
       quantidadeDeClientes=0;
       while (fread(&c, sizeof(Cliente),1,arq)== 1)
       {
         quantidadeDeClientes++;
        }
  }
  fseek(arq,0,0);
 }
ClienteFuncoes::~ClienteFuncoes(){
               fclose(arq);
}




void ClienteFuncoes::menu(){
	ClienteFuncoes c;
	int opcao;
	do{
		system("cls");
		printf("\t[1] Para inserir cliente\n");
		printf("\t[2] Para remover um cliente\n");
		printf("\t[3] Para inserir um pedido em um cliente\n");
		printf("\t[4] Para mostrar todos os clientes\n");
		printf("\t[5] Para sair\n");
		
		fseek(arq,0,0);
	
		fflush(stdin);
		scanf("%d",&opcao);
		
		if(opcao == 1)
			c.inserirCliente();
		if(opcao == 2)
			c.removerCliente();
		if(opcao == 3)
			c.pedidos();
		if(opcao == 4)
			c.mostrarClientes();
	}while( opcao != 5);
	return;
	
}	
