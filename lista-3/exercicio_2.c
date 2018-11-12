#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
/* includes */

int remover_n_elementos(Lista*, int);

int main(int argc, char const *argv[]){
  Lista *lista = criarLista();
  insere_ultimoLista(lista, 1);
  insere_ultimoLista(lista, 2);
  insere_ultimoLista(lista, 3);
  insere_ultimoLista(lista, 4);
  insere_ultimoLista(lista, 5);
  insere_ultimoLista(lista, 6);

  remover_n_elementos(lista, 4);

  printf("\tDados da Lista\n");
  printLista(lista);
  return 0;
}
int remover_n_elementos(Lista* l, int n){
  if(countLista(l) < n) return 0;
  else{
    int val;
    for (int i = 0; i < n; i++) {
      remove_posicaoLista(l, 1, &val);
    }

    return 1;
  }
}
