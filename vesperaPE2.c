/*(3) Escreva um programa em C que receba, infinitamente, uma matriz "sem classificação", descubra a classe de cada
matriz e as imprima de acordo com a classe a que pertencem. As classes aceitas nesta questão são as seguintes:
-> Linha: formada por uma única linha;
-> Coluna: formada por uma única coluna;
-> Simétrica: ocorre quando o elemento da linha i e coluna j é igual ao elemento da linha j e coluna i, para todos os elementos dessa matriz;
-> Triangular: quando todos os elementos acima, ou abaixo da diagonal principal são iguais a zero (se uma matriz possuir todos os elementos iguais a zero, essa matriz será considerada simétrica);
-> Identidade: ocorre quando os elementos da diagonal principal são todos iguais a um e os demais elementos são iguais a zero;
-> NRA: sem nenhuma das classificações supracitadas. */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int ativo = 1;
    while(ativo == 1){
        //CRIANDO A MATRIZ
        int linhas;
        printf("Numero de Linhas da Matriz: ");
        scanf(" %d",&linhas);
        int colunas;
        printf("Numero de Colunas da Matriz: ");
        scanf(" %d",&colunas);
        
        printf("\n");

        int matriz[linhas][colunas];

        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                printf("Valor em Linha[%d] ; Coluna[%d] : ",i ,j);
                scanf(" %d",&matriz[i][j]);
            }
        }

        printf("\n");

        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++)    {printf("%d ", matriz[i][j]);}
            printf("\n");}

        //ANALIZANDO O TIPO
        int TipoLinha = 1, TipoColuna = 1, TipoSimetrica = 1, TipoTriangular = 1, TipoIdentidade = 1, TipoNRA = 1;

        if(linhas > 1){TipoLinha = 0;}
        if(colunas > 1){TipoColuna = 0;}

        for(int l = 0; l < linhas; l++){
            for(int c = 0; c < colunas; c++){
                if (linhas == colunas){
                if (matriz[l][c] != matriz[c][l])   {TipoSimetrica = 0;}}
                else { TipoSimetrica = 0;}

                if (l == c && matriz[l][c] != 1)    {TipoIdentidade = 0;}
                if (l != c && matriz[l][c] != 0)   {TipoIdentidade = 0;}
            }
        }

        int diagUp = 1;
        int diagDown = 1;

        for(int l = 0; l < linhas; l++){
            for(int c = 0; c < colunas; c++){
                if(c > l && matriz[l][c] != 0)  {diagDown = 0;}
                if(l > c && matriz[l][c] != 0)  {diagUp = 0;}
            }
        }

        if(diagDown == 0 && diagUp == 0)   {TipoTriangular = 0;}

        if(TipoLinha == 1){printf("Matriz Tipo Linha\n");}
        else if(TipoColuna == 1){printf("Matriz Tipo Coluna\n");}
        else if(TipoIdentidade == 1){printf("Matriz Tipo Identidade\n");}
        else if(TipoSimetrica == 1){printf("Matriz Tipo Simetrica\n");}
        else if(TipoTriangular == 1){printf("Matriz Tipo Triangular\n");}
        else {printf("Matriz NRA\n");}

        printf("----------------------------------------------\n");
}
    return 0;
}