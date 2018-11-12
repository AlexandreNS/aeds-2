#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"

int remove_ord_lista(Lista*, int);
/* includes */
int main(int argc, char const *argv[]){
  Lista *lista = criarLista();
  insere_ultimoLista(lista, 1);
  insere_ultimoLista(lista, 12);
  insere_ultimoLista(lista, 122);
  insere_ultimoLista(lista, 3321);

  printLista(lista);
  remove_ord_lista(lista, 122);
  printf("Lista com elemento 122 removido\n");
  printLista(lista);
  return 0;
}
int remove_ord_lista(Lista* l, int v){
  if(l->inicio == NULL) return 0;
  Elemento *aux = l->inicio;
  if(v == aux->valor){
    l->inicio = l->inicio->proximo;
    free(aux);
  }else{
    while (aux->proximo != NULL && aux->proximo->valor != v) {
      aux = aux->proximo;
    }
    Elemento *aux2 = aux->proximo;
    aux->proximo = aux->proximo->proximo;
    free(aux2);
  }
}
