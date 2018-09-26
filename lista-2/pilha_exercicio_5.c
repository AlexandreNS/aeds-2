#include <stdio.h>
#include <stdlib.h>
#include "libs/pilhaDinamica_int.c"

int pilha_cmp(Pilha*, Pilha*);

int main(int argc, char const *argv[]){
  Pilha *p1 = criaPilha();
  empilha(p1, 34);
  empilha(p1, 34);
  empilha(p1, 34);
  empilha(p1, 34);
  empilha(p1, 34);

  Pilha *p2 = criaPilha();
  empilha(p2, 42);
  empilha(p2, 42);
  empilha(p2, 42);
  empilha(p2, 42);
  empilha(p2, 42);

  int cmp_value = pilha_cmp(p1, p2);
  if(cmp_value != 0) printf("%s\n", cmp_value == 1 ?
    "A 2° pilha é maior que a 1°" : "A 1° pilha é maior que a 2°" );
  else printf("As pilhas possuem o mesmo tamanho\n");

}

int pilha_cmp(Pilha* p1, Pilha* p2){
  int temp;
  while(!pilhaVazia(p1) && !pilhaVazia(p2)){
    desempilha(p1, &temp);
    desempilha(p2, &temp);
  }
  if (pilhaVazia(p1) && pilhaVazia(p2)) return 0;
  else if (pilhaVazia(p1)) return 1;
  else return 2;
}
