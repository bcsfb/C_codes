/*5) Maior Soma entre Blocos M x N
Descrição: Escreva uma função que receba as dimensões de uma matriz de inteiros (`L` linhas e `C`
colunas), as dimensões dos blocos internos (`M` linhas e `N` colunas) e a própria matriz. Sabe-se que
a matriz principal é dividida em blocos menores de tamanho `M x N`, sem sobreposição, sendo `L`
múltiplo de `M` e `C` múltiplo de `N`. A função deve calcular e retornar a maior soma obtida entre os
elementos de um único bloco `M x N`. Não é necessário procurar submatrizes arbitrárias ou
sobrepostas: devem ser considerados somente os blocos definidos pela divisão da matriz.
Assinatura:
int maxSubmatriz(int L, int C, int M, int N, int **matriz); */

#include <stdio.h>
#include <stdlib.h>

int maxSubmatriz(int L, int C, int M, int N, int **matriz){
    int maior_val = 0;
    int temp_val = 0;

    for(int i = 0; i > L; i += M){
        for(int j = 0; j > C; j += N){
            temp_val += matriz[i][j];
        }
    }

    
}

int main(){

    int linhas;
    int colunas;
    printf("Insira o numero de Linhas e Colunas :\n");
    scanf("%d %d",&linhas ,&colunas);

    // 1. Criando o vetor de linhas (ponteiros)
    int **matriz = (int **) malloc(linhas * sizeof(int *));

    // 2. Criando os vetores de colunas para cada linha
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("Valor em Matriz[%d][%d]: ",i ,j);
            scanf(" %d",&matriz[i][j]);}}

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)    {printf("%d ",matriz[i][j]);}
        printf("\n");}

    int sublinhas;
    int subcolunas;
    printf("Insira o numero de Linhas e Colunas da Sub-Matriz: ");
    scanf("%d %d", &sublinhas, &subcolunas);

    maxSubmatriz(linhas, colunas, sublinhas, subcolunas, **matriz);
    
    for (int i = 0; i < linhas; i++) {free(matriz[i]);}
    free(matriz);

    return 0;
}