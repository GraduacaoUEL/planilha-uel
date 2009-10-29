typedef struct Operacoes{
   
   void somatorio(int numerdoDeCedulas int *linha, int *coluna );
   void produtorio(int numerdoDeCedulas, int *linha, int *coluna );
   void medias (int numerdoDeCedulas, int *linha, int *coluna );
   void subtracoes (int numerdoDeCedulas, int *linha, int *coluna );
   void menor (int numerdoDeCedulas, int *linha, int *coluna );
   void maior (int numerdoDeCedulas, int *linha, int *coluna );
   void moda (int numerdoDeCedulas, int *linha, int *coluna );
   void desvioPadrao (int numerdoDeCedulas, int *linha, int *coluna );
   void mediaPonderada (int numerdoDeCedulas, int *linha, int *coluna );
   void modulo (int numerdoDeCedulas, int *linha, int *coluna );
   void raizQuadrada (int numerdoDeCedulas, int *linha, int *coluna );
   void ordenacao (int numerdoDeCedulas, int *linha, int *coluna );
   void divisao (int numerdoDeCedulas, int *linha, int *coluna );
}


void Operacoes::somatorio(int numeroDeCedulas, int *linha, int *coluna ){
   
   float soma;
   
   linha = new int linha[numeroDeCedulas];
   coluna = new int coluna[numeroDeCedulas];   
   
   soma = 0.0;
   
   for( int i = 0; i numeroDeCedulas; i++)
      soma += numeros[linha[i][coluna[i]]

   return soma;
   delete(linha);
   delete(coluna);
}

void Operacoes::produtorio(int numeroDeCedulas, int *linha, int *coluna ){
   
   float produto;
   
   linha = new int linha[numeroDeCedulas];
   coluna = new int coluna[numeroDeCedulas];   
   
   produto = 1;
   
   for( int i = 0; i numeroDeCedulas; i++)
      produto *= numeros[linha[i][coluna[i]]

   return soma;
   delete(linha);
   delete(coluna);
}

void Operacoes::medias(int numeroDeCedulas, int *linha, int *coluna ){
   
   float soma, media;
   
   linha = new int linha[numeroDeCedulas];
   coluna = new int coluna[numeroDeCedulas];   
   
   soma = 0.0;
   
   for( int i = 0; i numeroDeCedulas; i++)
      soma += numeros[linha[i][coluna[i]]
   
   media = soma / numeroDeCedulas;

   return soma;
   delete(linha);
   delete(coluna);
}

void Operacoes::subtracoes(int numeroDeCedulas, int *linha, int *coluna ){
   
   float ssubatracao;
   
   linha = new int linha[numeroDeCedulas];
   coluna = new int coluna[numeroDeCedulas];   
   
   soma = 0.0;
   
   for( int i = 0; i numeroDeCedulas; i++)
      subtracao += numeros[linha[i][coluna[i]]

   return soma;
   delete(linha);
   delete(coluna);
}

