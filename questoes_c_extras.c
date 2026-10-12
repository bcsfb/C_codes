#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int ContarVogaisRec(char *str) {
    // 1. Caso Base: final da string
    if (*str == '\0')   {return 0;}

    // 2. Verifica se o caractere atual eh uma vogal
    char c = *str;
    int ehVogal = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    // 3. Passo Recursivo: soma 1 (se for vogal) ou 0 + a contagem do resto da string
    return ehVogal + ContarVogaisRec(str + 1);
}

int ContarPalavraRec(FILE *f, char *palavraAlvo){
    if (f == NULL) {return 0;}
    
    char temp[50];
    if (fscanf(f,"%s",temp) == EOF) {return 0;};

    int igualdade = (strcmp(temp, palavraAlvo) == 0);
    //nao precisa escrever nadad sobre onde a leitura do arq deve comecar
    //pq o "cursor" interno do file ja avança sozinho a cada fscanf
    return igualdade + ContarPalavraRec(f, palavraAlvo);
}

void InverterArquivoRec(FILE *in, FILE *out){
    char temp[50];
    if(fscanf(in,"%s",temp) == EOF) {return;}

    InverterArquivoRec(in, out);

    fprintf(out,"%s ",temp);
}

int SomarComprimentoRec(FILE *f){
    char temp;
    if(f == NULL)   {return -1;}
    if(fscanf(f,"%c",&temp) == EOF) {return 0;}
    int aux = (temp != ' ' && temp != '\n');
    
    return aux + SomarComprimentoRec(f);
}

void MaiorPalavraRec(FILE *f, char*maior){
    if(f == NULL)   {return;}

    char temp[25];
    if (fscanf(f,"%s",temp) == EOF) {return;};

    if(strlen(temp) > strlen(maior))   {strcpy(maior, temp);}

    MaiorPalavraRec(f, maior); 
}

void ImprimirMaiores(char *vetor[], int total, int tamMinimo){
    for(int i = 0; i < total; i++){
        if (strlen(vetor[i]) > tamMinimo)   {printf("[%s]",vetor[i]);}
    }
}

void OrdenarPonteiros(char *vetor[], int total){
    char* temp;
    for(int i=0;i<total;i++){
        for(int j=0;j<total -1;j++){
            if(strcmp(vetor[j],vetor[j+1]) > 0){
                temp = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

int main(){

//char frase[] = "vamos ver se eu mato essa no peito da recursao";
//printf(" %d",ContarVogaisRec(frase));

//FILE *arquivo = fopen("manipulacao_arc_c.txt","r");
//printf(" %d",ContarPalavraRec(arquivo,"teste"));
//fclose(arquivo);

//FILE *entrada = fopen("manipulacao_arc_c.txt","r");
//FILE *saida = fopen("manipulacao_arc_c2.txt","w");
//if(entrada != NULL && saida != NULL)    {InverterArquivoRec(entrada, saida);}
//fclose(entrada);
//fclose(saida);

//FILE *arquivo = fopen("manipulacao_arc_c.txt","r");
//printf(" %d ",SomarComprimentoRec(arquivo));
//fclose(arquivo);

//char palavra[25];
//FILE *arquivo = fopen("manipulacao_arc_c.txt","r");
//MaiorPalavraRec(arquivo, palavra);
//printf("%s ",palavra);
//fclose(arquivo);

//int TamVet = 9;
//char *vetfrase[9] = {"duvido","meu","Deus","dessa","vez","eu","vou","apanhar","apanharei"};
//int TamMin = 4;
//ImprimirMaiores(vetfrase, TamVet, TamMin);

int TamVet = 9;
char *vetfrase[9] = {"duvido","meu","Deus","dessa","vez","eu","vou","apanhar","apanharei"};
for(int i=0;i<TamVet;i++)   {printf("%s ",vetfrase[i]);}
OrdenarPonteiros(vetfrase, TamVet);
printf("\n");
for(int i=0;i<TamVet;i++)   {printf("%s ",vetfrase[i]);}

return 0;
}