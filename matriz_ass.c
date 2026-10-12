#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int SomarTamanhosRec(char **tabela, int total){
    if(total <= 0)   {return 0;}
    total --;
    return strlen(tabela[total]) + SomarTamanhosRec(tabela, total);
}

int SomarTamanhosRecPont(char **tabela, int total) {
    if (total == 0)     {return 0;}
    return strlen(*tabela) + SomarTamanhosRecPont(tabela + 1, total - 1);
}

int ContarMatriz2DRec(int **matriz, int linhas, int cols, int r, int c, int alvo){
    if(c >= cols)   {c = 0; r++;} 
    if(r >= linhas)    {return 0;}

    int aux = matriz[r][c];

    if(aux == alvo) {return 1 + ContarMatriz2DRec(matriz,linhas,cols,r, c+1 ,alvo);}
    else {return ContarMatriz2DRec(matriz,linhas,cols,r, c+1 ,alvo);}
}

char** CriarFiltroTamanhoRec(char** origem, int total, int tamMin, int* qtdNovas){
    if(total == 0)  {return;}
    if(strlen(origem[total]) < tamMin)  {CriarFiltroTamanhoRec(origem, total-1, tamMin, qtdNovas);}
    (*qtdNovas)++;

    char** matcar = (char**) malloc (strlen(origem[total]) * sizeof(char*));

}

int main(){
    
    //char* palavras[] ={"oi","teste","comecando","estudos","para","nao","rodar"};
    //int nPalavras = 7; 
    //printf("Total de Caracteres: %d \n",SomarTamanhosRec(palavras, nPalavras));

    //int lin = 4;
    //int col = 5;
    //int alvo = 2;
    //int **matriz; 
    //matriz = (int**) malloc(lin * sizeof(int *));
    //for(int i = 0; i < lin; i++)    {matriz[i] = (int *) malloc(col * sizeof(int));}
    //int dados[4][5] ={{1,2,3,4,5},
    //                  {2,3,4,5,2},
    //                  {2,2,0,9,8},
    //                  {5,4,3,2,1}};
    //for(int m = 0; m<lin;m++){
    //    for(int n = 0;n<col;n++){
    //        matriz[m][n] = dados[m][n];}
    //}
    //printf("O numero [%d] aparece [%d] vezes.\n",alvo,ContarMatriz2DRec(matriz,lin,col,0,0,alvo));
    //for(int i = 0; i<lin; i++) {free(matriz[i]);}
    //free(matriz);

    char* palavras[] ={"fazendo","bah","rendendo","oi","teste","comecando","estudos","para","nao","rodar"};
    int nPalavras = 9;
    int tamMin = 4; 
    char **resultado = CriarFiltroTamanhoRec(palavras, nPalavras, tamMin, 0);

    return 0;
}