#include "ClienteFuncoes.h"

void ClienteFuncoes::inserirCliente(){
   
   Cliente c;
   char esc;
   
   int localParaInserir,saida;
      
   
   
	fflush(stdin);
   printf("Nome do cliente\t");
   gets(c.nome);
   
   fflush(stdin);
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
   
   
   
   localParaInserir = achaCliente(c.nome );
   
	printf("Local para inserir%d",localParaInserir);
   fwrite(&c,(quantidadeDeClientes+1)*sizeof(Cliente),1,arq);
	fflush(stdin);
   printf("\n\nCliente inserido\n");
   getchar();
   
	quantidadeDeClientes++;    
	//fflush(arq);
	
	
	
}

int ClienteFuncoes::achaCliente(char clienteParaAchar[100]){
   Cliente *c;
	
	c = new Cliente[quantidadeDeClientes];
	int i;
	i= 0;

	fseek(arq,0,0);
	while (fread(&c[i], sizeof(Cliente),1,arq)== 1)
   {
		printf("NOME %s e quantidade %d",c[i].nome,i);
   	i++;
   }
   for(int k =0 ; k< quantidadeDeClientes; k++)
   	if( clienteParaAchar[0] > c[k].nome[0])
			 
			 
   delete(c);
   
	
   
   
   
}         
void ClienteFuncoes::removerCliente(){
	Cliente c; 
	int localParaRemover;
   char opcao,clienteParaRemover;
   
     
	printf("Digite o nome do cliente que sera removido");
   scanf("%s",clienteParaRemover);
   localParaRemover = achaCliente(&clienteParaRemover);
   
   fseek(arq, localParaRemover * sizeof(Cliente), 0);
	fread(&c, sizeof(struct Cliente), 1, arq);

	printf("Nome do cliente => %s  ",c.nome);
   printf("CPF do Cliente => %s  ",c.cpf);
  	printf("Tem certeza que deseja excluir ? [s]im [n]");
  
   do{
  		fflush(stdin);
   	scanf("%c",&opcao);
	}while( opcao !='s' || opcao != 'n');
  
 	 c.cpf[0] = '-1';
 	 
 	 fwrite(&c,sizeof(Cliente),1,arq);
}	 
void ClienteFuncoes::pedidos(){
	
	Cliente c;
	char nomeDoClientePedindo[100];
	int localCorrente;
	
	
	printf("Insira o nome do cliente");
	scanf("&s",nomeDoClientePedindo);
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

    fseek( arq, 0, SEEK_SET );
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
		printf("%d",quantidadeDeClientes);
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
  clientesNaMemoria[quantidadeDeClientes];
 }
ClienteFuncoes::~ClienteFuncoes(){
               fclose(arq);
}




void ClienteFuncoes::menu(){
	system("pause");
}	
