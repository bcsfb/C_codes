#include <stdio.h>
#include <stdlib.h>
/*int main(){
    int elem;
    printf("%d \n",&elem);
    elem = 1001;
    int* pont;
    printf("%d \n",pont);
    pont = &elem;
    printf("elem[%d] &elem[%d] pont[%d] &pont[%d] *pont[%d]\n",elem,&elem,pont,&pont,*pont);
    *pont = 67;
    printf("elem[%d] &elem[%d] pont[%d] &pont[%d] *pont[%d]\n",elem,&elem,pont,&pont,*pont);
} */

void print_mat_transposta(int l,int c, int matriz[l][c], int transposta[c][l]){

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++)  {transposta[j][i] = matriz[i][j];}
    }
    for(int linha = 0; linha < c; linha++){
        for(int coluna = 0; coluna < l; coluna ++){
        printf("%d ",transposta[linha][coluna]);}
        printf("\n");
    }
}

int mult_mat(int l, int c, int matriz1[l][c], int matriz2[c][l]){
    int mat_prod[l][c];
    for(int i = 0; i < l; i ++){
        int mat_lc = 0;
        for(int j = 0; j < c; j ++){
            mat_lc += matriz1[l][]
        }
    }
}

int main(){
    int l,c;
    printf("Insira o numero de Linhas e Colunas: ");
    scanf("%d %d",&l,&c);

    int matriz[l][c];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("Valor em Linha %d , Coluna %d: ",i,j);
            scanf("%d",&matriz[i][j]);}
        }
        
    for(int linha = 0; linha < l; linha++){
        for(int coluna = 0; coluna < c; coluna ++){
        printf("%d ",matriz[linha][coluna]);
        if (coluna == c-1) {printf("\n");}}
    }
    int transposta[c][l];
    printf("\n");

    print_mat_transposta(l,c,matriz,transposta);
}




