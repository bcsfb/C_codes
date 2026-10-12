#include <stdio.h>

int escrita(){
    FILE *arquivo = fopen("manipulacao_arc_c.txt","a");

    if (arquivo == NULL)    {printf("ERRO"); return 1;}
    
    int carac;
    printf("Quantos caracteres tera sua frase? ");
    scanf("%d",&carac);
    carac += 1;
    printf("\n");

    while(getchar() != '\n');

    char palavra[carac];
    printf("Escreva sua frase: ");
    for(int i = 0; i < carac - 1 ; i++) {scanf("%c",& palavra[i]);}
    palavra[carac - 1] = '\0';

    fprintf(arquivo, " %s\n", palavra);

    fclose(arquivo);
}

int leitura(){
    FILE *arquivo = fopen("manipulacao_arc_c.txt","r");

    if (arquivo == NULL)    {printf("ERRO"); return 1;}

    int resposta;
    printf("Escreva 0 para ler por LINHA e 1 para ler por PALAVRA: ");
    scanf("%d",&resposta);

    char buffer[256];

    if(resposta == 0){
        int linhas;
        printf("Quantas linhas serao lidas? ");
        scanf("%d",&linhas);

        for(int i = 0; i < linhas; i++){
            if (fgets(buffer, sizeof(buffer),arquivo) != NULL){
                printf("%s", buffer);}
            else {break;}
        }
    }

    else if(resposta == 1){
        int palavras;
        printf("Quantas palavras serao lidas? ");
        scanf("%d",&palavras);

        for(int i = 0; i < palavras; i++){
            if (fscanf(arquivo, "%s",buffer) != EOF){
                printf("%s\n", buffer);}
            else {break;}
        }
    }
    fclose(arquivo);
}

int main(){

    escrita();

    while(getchar() != '\n');

    leitura();

    return 0;
}