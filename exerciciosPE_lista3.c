#include <stdio.h>
#include <stdlib.h>

/*Alguns números possuem uma propriedade interessante: se você recuperar seus dois
primeiros dı́gitos e seus dois últimos dı́gitos e elevar ao quadrado a soma deles, você obterá a
concatenação desses quatro dı́gitos. Por exemplo, o número 203125 possui essa propriedade,
pois (20 + 25)² = 2025. Por outro lado, o mesmo não é observado para 20326, pois (20 + 26)2
= 2116 2026 ≠ . Escreva uma função que informa se um número possui essa propriedade – int
teste(int n) – retornando UM se o número satisfaz a essa propriedade, e ZERO caso contrário.*/
/*
int main(){

    int n;
    int nfrente;
    int ntras;

    printf("Insira um numero para verificar a propriedade: ");
    scanf("%d", & n);

    ntras = n % 100;

    int ncopia = n;
    while(ncopia > 99) { ncopia /= 10; }
    nfrente = ncopia;

    int npontas = (nfrente*100 + ntras);

    printf("%d %d %d \n", nfrente, ntras, npontas);

    if((nfrente + ntras)*(nfrente + ntras) == npontas) {printf("1");}

    else {printf("0");}
} */
/*
Q3) Um número a é dito permutação de um número b se os dígitos de a formam uma permutação
dos dígitos de b. Exemplo: 5412434 é uma permutação de 4321445, mas não é uma permutação
de 4312455. Faça um programa que receba a e b e responda se a é permutação de b. Obs.:
Considere que o dígito 0 (zero) não deve aparecer nos números. */

int main(){
    int a;
    int b;

    printf("Insira A :");
    scanf("%d",&a);

    printf("Insira B :");
    scanf("%d",&b);

    int cont_dig_a = 0, cont_dig_b = 0;
    int a_copia = a, b_copia = b;

    while(a_copia > 0) {cont_dig_a ++; a_copia/=10;} // descobrir o numero de 
    while(b_copia > 0) {cont_dig_b ++; b_copia/=10;} // digitos de a e b

    if(cont_dig_a != cont_dig_b){
        printf("%d e %d [ NAO ] sao permutacoes",a,b);
        return 1;}

    int lista_a[cont_dig_a];
    int lista_b[cont_dig_b];

    a_copia = a, b_copia = b;

    for(int i = 0; i < cont_dig_a; i++){
        lista_a[i] = (a_copia % 10);
        lista_b[i] = (b_copia % 10);

        a_copia /= 10;
        b_copia /= 10;
    }

    int permutacoes = 0;

    for(int k = 0; k < cont_dig_a; k++){
        for(int j = 0; j < cont_dig_b; j++){
            if(lista_a[k] == lista_b[j]){permutacoes ++; lista_b[j] = 0; break;}
        }
    }

    if(permutacoes == cont_dig_a){printf("%d e permutacao de %d",a,b);}
    else {printf("%d e %d [ NAO ] sao permutacoes",a,b);}
    return 0;
}