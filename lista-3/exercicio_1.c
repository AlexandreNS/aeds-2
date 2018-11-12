#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
/* includes */

Lista* concatena_lista(Lista*, Lista*);

int main(int argc, char const *argv[]){
  Lista *lista1 = criarLista();
  Lista *lista2 = criarLista();
  insere_ultimoLista(lista1, 1);
  insere_ultimoLista(lista1, 2);
  insere_ultimoLista(lista1, 3);
  insere_ultimoLista(lista1, 4);

  insere_ultimoLista(lista2, 5);
  insere_ultimoLista(lista2, 6);
  insere_ultimoLista(lista2, 7);

  Lista *lista_concatenada = concatena_lista(lista1, lista2);
  printf("\tDados da Lista 1\n");
  printLista(lista1);

  printf("\n\tDados da Lista 2\n");
  printLista(lista2);

  printf("\n\tDados da Lista Concatenada\n");
  printLista(lista_concatenada);
  return 0;
}

Lista* concatena_lista(Lista* l1, Lista* l2){
  Lista* lista_retorno = (Lista*)malloc(sizeof(Lista));
  lista_retorno->inicio = NULL;
  int count_retorno = 0;

  Elemento *aux_add = lista_retorno->inicio;
  Elemento *aux;
  aux = l1->inicio;

  while (aux != NULL) {
    Elemento *add;
    add = (Elemento*)malloc(sizeof(Elemento));
    add->valor = aux->valor;
    add->proximo = NULL;

    if(count_retorno == 0) lista_retorno->inicio = add;
    if(aux_add != NULL) aux_add->proximo = add;

    aux_add = add;
    aux = aux->proximo;
    count_retorno++;
  }
  aux = l2->inicio;

  while (aux != NULL) {
    Elemento *add;
    add = (Elemento*)malloc(sizeof(Elemento));
    add->valor = aux->valor;
    add->proximo = NULL;

    if(count_retorno == 0) lista_retorno->inicio = add;
    if(aux_add != NULL) aux_add->proximo = add;

    aux_add = add;
    aux = aux->proximo;
    count_retorno++;
  }
  return lista_retorno;
}
