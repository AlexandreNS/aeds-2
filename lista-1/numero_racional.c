#include <stdio.h>
#include <stdlib.h>
/* includes */
typedef struct RacionalTag{
    int numerador;
    int denominador;
} Racional;

Racional* cria_racional();
int alterar_racional(Racional*, int, int);
Racional soma_racional(Racional*, Racional*);
Racional multiplica_racional(Racional*, Racional*);
int compara_racional(Racional*, Racional*);
int mdc(int, int);
void simplifica_racional(Racional*);

int main(int argc, char const *argv[]){

    return 0;
}
Racional* cria_racional(){
  Racional *r;
  r = (Racional*)malloc(sizeof(Racional));
  r->numerador = 0;
  r->denominador = 1;
  return r;
}
int alterar_racional(Racional* r, int n, int d){
  if (d == 0) return 0;
  else{
    r->numerador = n;
    r->denominador = d;
    return 1;
  }
}
Racional soma_racional(Racional* r1, Racional* r2){}
Racional multiplica_racional(Racional*, Racional*);
int compara_racional(Racional* r1, Racional* r2){
  int num1 = r1->numerador * r2->denominador;
  int num2 = r2->numerador * r1->denominador;
  if (num1 == num2) return 0;
  if (num1 > num2)  return 1;
  if (num1 < num2)  return -1;
}
int mdc(int a, int b){
  if (a == 0 || b == 0) return (a == 0 ? b : a);
  if (a > b) return mdc(a%b, b);
  if (a < b) return mdc(a, b%a);
  if (a == b) return a;
}
void simplifica_racional(Racional* r){
  int mdc = mdc(r->numerador, r->denominador);
  r->numerador /= mdc;
  r->denominador /= mdc;
}
