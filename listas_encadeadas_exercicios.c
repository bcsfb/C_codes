#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PROD{
    char misc[51];
    float preco;
}PROD;

void imprime(PROD* l, int n){
    for(int i=0; i<n; i++){
        printf("Data: %.8s ; Nome : [%-20s] ; Preco : [%.2f]\n",l[i].misc ,l[i].misc ,l[i].preco);
    }
}

void ordena_a(PROD *vet, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            int trocar = 0;
            // > 0 se o primeiro vem depois do segundo alfabeticamente
            // < 0 se o primeiro vem antes do segundo alfabeticamente
            int res_nome = strcmp(vet[j].misc + 8, vet[j+1].misc + 8);
            if(res_nome > 0)    {trocar = 1;}

            //empate no nome vai pra data   
            else if(res_nome == 0){//o 4 no final é para contar so 4 digitos
                int res_ano = strncmp(vet[j].misc + 4, vet[j + 1].misc + 4, 4);
                if (res_ano > 0)    {trocar = 1;}
            
                else if(res_ano == 0)   {
                    int res_mes = strncmp(vet[j].misc + 2, vet[j+1].misc + 2, 2);
                    if (res_mes > 0)    {trocar = 1;}

                    else if(res_mes == 0)   {
                        int res_dia = strncmp(vet[j].misc, vet[j+1].misc, 2);
                        if (res_dia > 0)    {trocar = 1;}

                        //empate data vai pro preço
                        else if(res_dia == 0)   {
                            if(vet[j].preco < vet[j+1].preco)   {trocar = 1;}
                        }
                    }
                }
            }
            if(trocar == 1) {
                PROD aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

int main(){
    int resposta;
    printf("Deseja adicionar quantos produtos? ");
    scanf(" %d",&resposta);

    PROD* lista_prod = (PROD*) malloc(resposta* sizeof(PROD));

    for(int i=0; i<resposta; i++){
        printf("Insira [DDMMAAAA][NOME] : ");
        scanf(" %50s",&lista_prod[i].misc);

        printf("Insira o preco [FLOAT] : ");
        scanf(" %f",&lista_prod[i].preco);
    }
    printf("\nSEM ORDENACAO\n");
    imprime(lista_prod, resposta);

    ordena_a(lista_prod, resposta);

    printf("\nCOM ORDENACAO\n");
    imprime(lista_prod, resposta);

    free(lista_prod);

return 0;
}