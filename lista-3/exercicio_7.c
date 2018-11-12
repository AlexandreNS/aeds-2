#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
/* includes */
Lista* cria_lista_pares(Lista*);

int main(int argc, char const *argv[]){
  Lista *lista = criarLista();
  insere_ultimoLista(lista, 2);
  insere_ultimoLista(lista, 90);
  insere_ultimoLista(lista, 3);
  insere_ultimoLista(lista, 6);
  insere_ultimoLista(lista, 99);
  insere_ultimoLista(lista, 8);
  insere_ultimoLista(lista, 10);

  Lista *lista_pares = cria_lista_pares(lista);

  printf("\tDados da Lista Original:\n");
  printLista(lista);

  printf("\n\tDados da Lista com Pares:\n");
  printLista(lista_pares);
  return 0;
}

Lista* cria_lista_pares(Lista* l){
  Lista *retorno = criarLista();
  Elemento *aux = l->inicio;
  int count = 0;
  while(aux != NULL){
    if(aux->valor % 2 == 0) insere_ultimoLista(retorno, aux->valor);
    aux = aux->proximo;
  }
  return retorno;
}
