#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int maxSubmatriz (int L, int C,int M, int N, int **matriz){
    if(L % M != 0 || C % N != 0)    {return -1;}

    int  MaiorSubMat = 0;

    for(int lin=0; lin<L; lin+=M){
        for(int col=0; col<C; col+=N){
        int sumAux = 0;

        for(int slin=0; slin<M; slin++){
            for(int scol=0; scol<N; scol++){
                sumAux += matriz[lin + slin][col + scol];}
        }
        if(sumAux > MaiorSubMat)    {MaiorSubMat = sumAux;}
        }
    }

    return MaiorSubMat;
}

int main(){

int linhas = 6;
int colunas = 6;
int sublin = 2;
int subcol = 2;

int** matriz = (int**) malloc(linhas * sizeof(int*));
for(int i=0;i<linhas;i++)  {matriz[i] = (int*) malloc(colunas * sizeof(int));}
    int dados[6][6] ={
        {1, 2, 3, 4, 5, 1},
        {2, 3, 4, 5, 2, 2},
        {2, 2, 9, 9, 8, 3},
        {5, 4, 3, 2, 1, 4},
        {1, 1, 1, 1, 1, 5},
        {2, 2, 2, 2, 2, 6}
    };
    for(int m = 0; m<linhas;m++){
        for(int n = 0;n<colunas;n++){
        matriz[m][n] = dados[m][n];}}

int somaMaxMat = maxSubmatriz(linhas,colunas,sublin,subcol,matriz);
printf("A maior SubMatriz %d x %d tem soma igual a %d\n",sublin,subcol,somaMaxMat);

return 0;
}