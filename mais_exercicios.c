/*(Q1) Implemente uma função em C que receba uma string como parâmetro e
 substitua todas as suas letras por predecessoras do alfabeto, trocando 
maiúsculas por minúsculas. Por exemplo, a string “Amor” seria alterada para
“zLNQ”. Esta função deve obedecer o seguinte protótipo: void shift_troca_string (char *str).
A letra ‘a’ deve ser substituída por ‘Z’ (e ‘A’ por ‘z’). Caracteres que não forem
letras devem ser substituídos por ‘!’. Sabe-se que A = 65, Z = 90, a = 97 e z = 122.*/

#include <stdio.h>

void shift_troca_string (char *str){
    int i = 0; // controla a posicao na string
    while(str[i] != '\0'){ // enqunato a string nao terminar
        if(str[i] >= 'A' && str[i] <= 'Z'){ // str maiuscula entre A e Z
            if(str[i] == 'A'){str[i] = 'z';}
            else{str[i] = str[i] -1 + 32;} // volta uma e +32 pra virar minuscula
        }
        else if(str[i] >= 'a' && str[i] <= 'z'){
            if(str[i] == 'a'){str[i] = 'Z';}
            else{str[i] = str[i] -1 -32;}
        }
        else {str[i] = '!';}

    i++;
    }
}

/*
int main(){
    char palavra[] = "Bernardo";

    shift_troca_string(palavra);
    printf("%s\n ",palavra);

    return 0;
}*/

char* codificar(char *str){
int posicao = 0;
    while(str[posicao] != '\0'){
        if(str[posicao] >= 97 && str[posicao] <= 122){
            str[posicao] = '?';}
    posicao ++;}
    return str;
}
/*
int main(){
    char frase[] = "Me Encontro A Julgar Ultrajantemente Demasia Agonia";
    codificar(frase);
    printf("%s",frase);

    return 0;
}*/


// funcao que ordena os caracteres de uma frase de acordo com a tabela ASCII 

void ordena_frase(char*frase){
    int i = 0;
    while(frase[i] != '\0') {i++;}

    for(int j = 0; j<i; j++){
        for(int k = 0; k<i; k++){
            if(frase[k] > frase[j]){
                char aux = frase[j];
                frase[j] = frase[k];
                frase[k] = aux;
            }
        }
    }
}
/*
int main(){
    char frase[] = "teste teste bom dia !! :)";
    printf("%s\n",frase);
    ordena_frase(frase);
    printf("%s\n",frase);

    return 0;
}*/

/*
(Q3) Escreva uma função que receba, como entrada, uma cadeia de caracteres
s e um inteiro n, e, em seguida, retire o "prefixo" da cadeia s de tamanho n 
(isto é, retire os n primeiros caracteres). Se a cadeia não tiver pelo menos 
n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se s = "abcdefghi" 
e n = 3, então a cadeia "defghi" deve ser impressa; com a mesma cadeia s e n = 17,
deve ser impresso "erro". O protótipo desta função é o seguinte: */

void retira_inicio_n(char *str, int n){
    int i = 0;
    while(str[i] != '\0'){i++;}

    int j = 0;
    for(j ; j < i-n ; j++)  {str[j] = str[j+n];}
    str[j] = '\0';

}

void retira_fim_n(char* str, int n){
    int i = 0;
    while(str[i] != '\0'){i++;}

    str[i-n] = '\0';
}
/*
int main(){
    int n = 13;
    char frase[] = "vamos ver se faco isso rapido";
    char frasec[] = "vamos ver se faco isso rapido";
    printf("%s\n", frase);

    retira_inicio_n(frase, n);
    printf("%s\n",frase);

    retira_fim_n(frasec, n);
    printf("%s\n",frasec);

return 0;
}*/

void quick_sort(int *vetor, int inicio, int fim){
    if(inicio >= fim){return;}

    int pivo = vetor[(inicio + fim)/2];
    int i = inicio; // esquerda --> direita
    int f = fim;    // direita --> esquerda

    while(i <= f){
        while (vetor[i] < pivo) {i++;}
        while (vetor[f] > pivo) {f--;}
        
        if(i <= f){
            int aux = vetor[i];
            vetor[i] = vetor[f];
            vetor[f] = aux;

            i++; f--;}
    }
    quick_sort(vetor, inicio, f);
    quick_sort(vetor,i,fim);
}

int main(){
    int n;
    printf("Digite quantos numeros tera o vetor: ");
    scanf("%d",&n);

    int vet[n];
    printf("Insira os numeros do vetor: ");
    for(int i = 0; i < n; i++)  {scanf("%d",&vet[i]);}

    printf("\n");
    for(int j = 0; j < n; j++)  {printf("%d ",vet[j]);}
    printf("\n");

    quick_sort(vet, 0, n-1);
    for(int j = 0; j < n; j++)  {printf("%d ",vet[j]);}

    return 0;
}