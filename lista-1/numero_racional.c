#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* includes */
typedef struct RacionalTag{
    int numerador;
    int denominador;
} Racional;

Racional* cria_racional();
int alterar_racional(Racional*, int, int);
Racional* soma_racional(Racional*, Racional*);
Racional* multiplica_racional(Racional*, Racional*);
int compara_racional(Racional*, Racional*);
int calcular_mdc(int, int);
void simplifica_racional(Racional*);
void exclui_racional(Racional*);

int main(int argc, char const *argv[]){
    Racional *num1, *num2, *soma, *produto;

    num1 = cria_racional();
    num2 = cria_racional();
    soma = cria_racional();
    produto = cria_racional();

    alterar_racional(num1, -9, 18);
    alterar_racional(num2, 18, 90);

    soma = soma_racional(num1, num2);
    produto = multiplica_racional(num1, num2);

    printf("%d\n", compara_racional(num1, num2));
    printf("A Soma é: %d/%d\n", soma->numerador, soma->denominador);
    printf("O Produto é: %d/%d\n", produto->numerador, produto->denominador);

    exclui_racional(soma);
    exclui_racional(produto);
    exclui_racional(num1);
    exclui_racional(num2);
    return 0;
}
Racional* cria_racional(){
    Racional *r;
    r = (Racional*)malloc(1*sizeof(Racional));
    r->numerador = 0;
    r->denominador = 1;
    return r;
}
int alterar_racional(Racional* r, int n, int d){
    if (d == 0) return 0;
    else{
        r->numerador = n;
        r->denominador = d;
        simplifica_racional(r);
        return 1;
    }
}
Racional* soma_racional(Racional* r1, Racional* r2){
    Racional* soma;
    soma = (Racional*)malloc(1*sizeof(Racional));
    soma->numerador = (r1->numerador * r2->denominador) + (r2->numerador * r1->denominador);
    soma->denominador = r1->denominador * r2->denominador;
    simplifica_racional(soma);
    return soma;
}
Racional* multiplica_racional(Racional* r1, Racional* r2){
    Racional* produto;
    produto = (Racional*)malloc(1*sizeof(Racional));
    produto->numerador = r1->numerador*r2->numerador;
    produto->denominador = r1->denominador*r2->denominador;
    return produto;
}
int compara_racional(Racional* r1, Racional* r2){
    int num1 = r1->numerador * r2->denominador;
    int num2 = r2->numerador * r1->denominador;
    if (num1 == num2) return 0;
    if (num1 > num2)  return 1;
    if (num1 < num2)  return -1;
}
int calcular_mdc(int a, int b){
    if (a == 0 || b == 0) return (a == 0 ? b : a);
    if (a > b) return calcular_mdc(a%b, b);
    if (a < b) return calcular_mdc(a, b%a);
    if (a == b) return a;
}
void simplifica_racional(Racional* r){
    int mdc = calcular_mdc(abs(r->numerador), abs(r->denominador));
    r->numerador /= mdc;
    r->denominador /= mdc;
}
void exclui_racional(Racional* r){
    free(r);
}
