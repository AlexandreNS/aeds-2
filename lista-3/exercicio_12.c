#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
/* includes */
Lista* lista_vetor(int*, int);

int main(int argc, char const *argv[]){
  int vetor[5];
  for (int i = 0; i < 5; i++) vetor[i] = i*i+2*i+9;
  Lista *lista = lista_vetor(vetor, 5);

  printf("\tLista de Um vetor:\n");
  printLista(lista);

  return 0;
}
Lista* lista_vetor(int* vetor, int n){
  Lista *retorno = criarLista();
  for (int i = 0; i < n; i++) {
    insere_ultimoLista(retorno, vetor[i]);
  }
  return retorno;
}
