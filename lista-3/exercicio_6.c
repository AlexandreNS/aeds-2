#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
/* includes */
int num_pares_lista(Lista*);

int main(int argc, char const *argv[]){
  Lista *lista = criarLista();
  insere_ultimoLista(lista, 2);
  insere_ultimoLista(lista, 90);
  insere_ultimoLista(lista, 3);
  insere_ultimoLista(lista, 6);
  insere_ultimoLista(lista, 99);
  insere_ultimoLista(lista, 8);
  insere_ultimoLista(lista, 10);

  printf("\tDados da Lista:\n");
  printLista(lista);
  printf("\nExiste %d numeros pares.\n", num_pares_lista(lista));
  return 0;
}
int num_pares_lista(Lista* l){
  Elemento *aux = l->inicio;
  int count = 0;
  while(aux != NULL){
    if(aux->valor % 2 == 0) count++;
    aux = aux->proximo;
  }
  return count;
}
