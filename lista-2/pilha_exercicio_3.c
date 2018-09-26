#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica_int.c"

int min_max_media(Pilha*, int*, int*, int*);
void preen

int main(int argc, char const *argv[]){

  return 0;
}

int min_max_media(Pilha *pilha, int* min, int* max, int* media){
  if(pilhaVazia(pilha)) return 0;
  else{
    int count = 1, current, soma = 0;
    desempilha(pilha, &current);
    soma += current;
    *min = current;
    *max = current;
    while (!pilhaVazia(p)){
      desempilha(pilha, &current);
      if(current > *max) *max = current;
      if(current < *min) *min = current;
      soma += current;
      count++;
    }
    *media = soma/count;
  }
}
