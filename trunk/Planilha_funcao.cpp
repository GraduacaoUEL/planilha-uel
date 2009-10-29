#include <stdio.h>
#include <stdlib.h>
#include <iostream>


float somatorio(int numerdoDeCedulas, int *linha, int *coluna ){

   float numeros[10][10];
   numeros[1][1]=1;
   numeros[1][4]=1;
   numeros[1][3]=1;
   numeros[1][2]=1;
   float soma;
   soma = 0.0;
   
   linha[1] =1;
   for( int i = 0; i < numerdoDeCedulas; i++)
      soma =soma + numeros[linha[1]][coluna[1]];
   
   delete(linha);
   delete(coluna);  
   return soma;
  
}


int main(){
   
   int *linha;
   int *coluna;
   linha = new int [4];
   coluna = new int [4];
   linha[0] = 1;
   linha[1] = 1;
   linha[2] = 1;
   linha[3] = 1;
   coluna [0]= 1;
   coluna [1]= 2;
   coluna [2]= 3;
   coluna [3]= 4;
   
   int tam =4;
   printf("%f",somatorio(tam,linha,coluna));
   system("pause");
   return 0;
}  
   
   
   
   
   
















