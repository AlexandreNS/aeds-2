#include <stdio.h>
#include <stdlib.h>
#include "libs/pilhaDinamica_int.c"

void inverte_pilha(Pilha*);

int main(int argc, char const *argv[]){
  Pilha *p = criaPilha();
  for (int i = 0; i < 10; i++) {
    printf("%d° item adicionado na Pilha comum: %d\n", i+1, i*10);
    empilha(p, i*10);
  }
  inverte_pilha(p);
  int temp;
  printf("\n");
  for (int i = 0; !pilhaVazia(p); i++) {
    desempilha(p, &temp);
    printf("%d° elemento da pilha invertida: %d\n", i+1, temp);
  }
}

void inverte_pilha(Pilha* pilha){
  int temp;
  Pilha *pilha_invertida = criaPilha();
  while(!pilhaVazia(pilha)){
    desempilha(pilha, &temp);
    empilha(pilha_invertida, temp);
  }
  free(pilha);
  *pilha = *pilha_invertida;
}
