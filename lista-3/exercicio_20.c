#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"

int countLista_rev(Elemento*);
/* includes */
int main(int argc, char const *argv[]){
  Lista *lista = criarLista();
  insere_ultimoLista(lista, 123);
  insere_ultimoLista(lista, 12);
  insere_ultimoLista(lista, 13);
  insere_ultimoLista(lista, 23);
  insere_ultimoLista(lista, 23);

  printLista(lista);
  printf("A lista tem %d elementos\n", countLista_rev(lista->inicio));
  return 0;
}

int countLista_rev(Elemento* e){
  if(e == NULL) return 0;
  if(e != NULL) return countLista_rev(e->proximo)+1;
}
