#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
/* includes */
int lista_cpy(Lista*, Lista*);

int main(int argc, char const *argv[]){
  Lista *lista = criarLista();
  insere_ultimoLista(lista, 1);
  insere_ultimoLista(lista, 2);
  insere_ultimoLista(lista, 3);
  insere_ultimoLista(lista, 45);
  insere_ultimoLista(lista, 54);
  insere_ultimoLista(lista, 63);
  insere_ultimoLista(lista, 71);

  Lista *copia = criarLista();

  lista_cpy(lista, copia);
  printf("\tLista Orginal:\n");
  printLista(lista);
  
  printf("\n\tLista Copia:\n");
  printLista(copia);
  return 0;
}
int lista_cpy(Lista* l1, Lista* l2){
  limparLista(l2);
  Elemento *aux = l1->inicio;
  while(aux != NULL){
    insere_ultimoLista(l2, aux->valor);
    aux = aux->proximo;
  }
}
