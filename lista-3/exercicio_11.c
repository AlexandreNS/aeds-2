#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
/* includes */
int inverte_lista(Lista*, Lista*);

int main(int argc, char const *argv[]){
  Lista *lista = criarLista();
  insere_ultimoLista(lista, 1);
  insere_ultimoLista(lista, 2);
  insere_ultimoLista(lista, 3);

  Lista *invertida = criarLista();

  inverte_lista(lista, invertida);
  printf("\tLista Orginal:\n");
  printLista(lista);

  printf("\n\tLista Invertida:\n");
  printLista(invertida);
  return 0;
}
int inverte_lista(Lista* l1, Lista* l2){
  int count = countLista(l1);
  for (int i = count; i > 0; i--) {
    int v;
    recupera_posicaoLista(l1, i, &v);
    insere_ultimoLista(l2, v);
  }
}
