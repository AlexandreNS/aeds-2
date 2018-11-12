#include <stdio.h>
#include <stdlib.h>
#include "libs/lista_dupla_int.c"

/* includes */

ListaDupla* concatena_lista(ListaDupla*, ListaDupla*);

int main(int argc, char const *argv[]){
  ListaDupla *lista1 = criarListaDupla();
  ListaDupla *lista2 = criarListaDupla();
  insere_ultimoListaDupla(lista1, 1);
  insere_ultimoListaDupla(lista1, 2);
  insere_ultimoListaDupla(lista1, 3);
  insere_ultimoListaDupla(lista1, 4);

  insere_ultimoListaDupla(lista2, 5);
  insere_ultimoListaDupla(lista2, 6);
  insere_ultimoListaDupla(lista2, 7);

  ListaDupla *lista_concatenada = concatena_lista(lista1, lista2);
  printf("\tDados da ListaDupla 1\n");
  printListaDupla(lista1);

  printf("\n\tDados da ListaDupla 2\n");
  printListaDupla(lista2);

  printf("\n\tDados da ListaDupla Concatenada\n");
  printListaDupla(lista_concatenada);
  return 0;
}

ListaDupla* concatena_lista(ListaDupla* l1, ListaDupla* l2){
  ListaDupla* lista_retorno = (ListaDupla*)malloc(sizeof(ListaDupla));
  lista_retorno->inicio = NULL;
  int count_retorno = 0;

  ElementoDuplo *aux_add = lista_retorno->inicio;
  ElementoDuplo *aux;
  aux = l1->inicio;

  while (aux != NULL) {
    ElementoDuplo *add;
    add = (ElementoDuplo*)malloc(sizeof(ElementoDuplo));
    add->valor = aux->valor;
    add->proximo = NULL;
    add->anterior = aux_add;

    if(count_retorno == 0) lista_retorno->inicio = add;
    if(aux_add != NULL) aux_add->proximo = add;

    aux_add = add;
    aux = aux->proximo;
    count_retorno++;
  }
  aux = l2->inicio;

  while (aux != NULL) {
    ElementoDuplo *add;
    add = (ElementoDuplo*)malloc(sizeof(ElementoDuplo));
    add->valor = aux->valor;
    add->proximo = NULL;
    add->anterior = aux_add;

    if(count_retorno == 0) lista_retorno->inicio = add;
    if(aux_add != NULL) aux_add->proximo = add;

    aux_add = add;
    aux = aux->proximo;
    count_retorno++;
  }

  return lista_retorno;

}
