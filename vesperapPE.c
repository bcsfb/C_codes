/*(1) Inserir o elemento (x - 1) antes e o elemento (x + 1) depois de cada ocorrência de x em uma string de resposta.
Se sua string original for formada pelos elementos {'1','3','1','5','1','\0'}, e se x for igual a '1', 
sua string de resposta será {'0','1','2','3','0','1','2','5','0','1','2','\0'}. 
O protótipo dessa função é o seguinte: char* ins_antes_depois_x(char* str, char x).*/

#include <stdio.h>
#include <stdlib.h>

char* insere_antes_depois(char* str, char x){
    int cont = 0;
    int rep = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == x)  {rep++;}
        cont ++;}
    
    int novo_tamanho = cont + (2*rep) + 1;
    str = (char *) realloc(str,novo_tamanho * sizeof(char));

    for(int k = 0; k < cont; k++){
        if(str[k] == x){
            for(int j = cont ; j >= k; j--) {str[j+2] = str[j];}
        
        str[k] = x-1;
        str[k+1] = x;
        str[k+2] = x+1;
    
        cont += 2;
        k += 2;
        }
    }
    return str;
}

int main(){
    int Tstr;
    printf("Quantos elementos tera a String? ");
    scanf("%d",&Tstr);

    char *str = (char *) malloc((Tstr +1) * sizeof(char));
    printf("Incira os elementos da String: ");
    for(int i = 0; i < Tstr; i++)   {scanf(" %c",&str[i]);}
    str[Tstr] = '\0';

    char x;
    printf("Incira o numero que sofrera a funcao: ");
    scanf(" %c",&x);

    str = insere_antes_depois(str, x);
    printf("%s",str);

    free(str);
    return 0;
}