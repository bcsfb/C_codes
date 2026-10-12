/* (Q1) Desenvolva um procedimento que receba o nome de um arquivo texto e retire deste texto
palavras consecutivas repetidas. O seu programa deve retornar, no arquivo de saída, informado
como parâmetro dessa função, a resposta desta questão. Por exemplo, se o conteúdo de um arquivo
texto for: "Isto e um texto texto repetido repetido repetido . Com as repeticoes
repeticoes fica fica sem sem sentido . Sem elas elas elas melhora melhora um um
pouco .", a saída do seu programa será um arquivo com o seguinte texto: "Isto e um texto
repetido . Com as repeticoes fica sem sentido . Sem elas melhora um um pouco ."
- void RetRepet(char *ArqEnt, char *ArqSaida). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RetRepet(char *ArqEnt, char *ArqSaida){
    FILE *arqLer = fopen(ArqEnt,"r");
    FILE *arqEscrever = fopen(ArqSaida,"a");

    if (arqLer == NULL || arqEscrever == NULL)    {printf("ERRO"); return;}

    char inicial[25];
    fscanf(arqLer, "%s", inicial);
    char temp[25];

    while(fscanf(arqLer, "%s", temp) != EOF){
        if(strcmp(inicial,temp) != 0){
            strcpy(inicial, temp);
            fprintf(arqEscrever,"%s ", temp);
        }
    }

    fclose(arqLer);
    fclose(arqEscrever);
}

int ContadorPalavras(char *NomeArq){
    FILE *arquivo = fopen(NomeArq, "r");
    if (arquivo == NULL)    {return -1;}
    int contador = 0;

    while(fscanf(arquivo,"%*s") != EOF)  {contador ++;}

    fclose(arquivo);
    return contador;
}

int BuscarPalavra(char *NomeArq, char *palavraAlvo){
    FILE* arquivo = fopen(NomeArq,"r");
    if(arquivo == NULL) {return -1;}
    
    int RepPalavra = 0;
    char temp[25];

    while(fscanf(arquivo,"%s",temp) != EOF){
        if(strcmp(temp, palavraAlvo) == 0)  {RepPalavra ++;}
    }

    fclose(arquivo);
    return RepPalavra;
}

int FiltrarPorTamanho(char *ArqEnt, char *ArqSaida, int tamMinimo){
    FILE *entrada = fopen(ArqEnt,"r");
    FILE *saida = fopen(ArqSaida, "w");
    if(entrada == NULL || saida == NULL)    {return -1;}
    int PAbarrado = 0;

    char temp[25];
    while(fscanf(entrada,"%s",temp) != EOF){
        if (strlen(temp) >= tamMinimo)  {fprintf(saida,"%s ",temp);}
        else {PAbarrado ++;}
    }

    fclose(entrada);
    fclose(saida);
    return PAbarrado;
}

void OrdenarArquivo(char *ArqEnt, char *ArqSaida){
    FILE *entrada = fopen(ArqEnt,"r");
    FILE *saida = fopen(ArqSaida,"w");

    char palavras[100][50];
    char temp[50];
    int i = 0;

    while(fscanf(entrada,"%s",temp) != EOF){
        strcpy(palavras[i],temp);
        i++;}

    for(int m = 0 ;m<i; m++){

    }

}

int main(){

    RetRepet("manipulacao_arc_c.txt", "manipulacao_arc_c2.txt");
    printf("%d\n",ContadorPalavras("manipulacao_arc_c.txt"));
    printf("Encontramos a Palavra %d vezes\n",BuscarPalavra("manipulacao_arc_c.txt","teste"));
    printf("%d palavras foram barradas\n",FiltrarPorTamanho("manipulacao_arc_c.txt", "manipulacao_arc_c2.txt",3));



return 0;
}