#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE* arquivo = fopen("manipulacao_arc_c.txt", "r");
    if (arquivo == NULL)    {printf("ERRO"); return 1;}

    char palavras[100][50];
    int quantidades[100];

    int total = 0;
    char buffer[50];

    while(fscanf(arquivo, "%s", buffer) != EOF){
        int achou = 0;

        for(int i = 0; i < total; i++){
            if (strcmp(palavras[i], buffer) == 0){
                quantidades[i]++;
                achou = 1;
                break;
            }
        }

        if (achou == 0){
            strcpy(palavras[total],buffer);
            quantidades[total] = 1;
            total++;
        }
    }

    fclose(arquivo);

    printf("\n--- CONTAGEM DE PALAVRAS ---\n");
    for (int i = 0; i < total; i++) {printf("%s: %d\n", palavras[i], quantidades[i]);}
    
    return 0;
}