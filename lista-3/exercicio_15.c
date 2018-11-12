#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
/* includes */
int insere_desc_lista(Lista*, int);

int main(int argc, char const *argv[]){
  Lista *lista = criarLista();
  insere_desc_lista(lista, 2);
  insere_desc_lista(lista, 5);
  insere_desc_lista(lista, 1);
  insere_desc_lista(lista, 3);
  insere_desc_lista(lista, 4);

  printf("\tLista Decrescente: \n");
  printLista(lista);

  return 0;
}
int insere_desc_lista(Lista* l, int v){
  Elemento *aux = l->inicio;
  int count = 1;
  while(aux != NULL){
    if(aux->valor <= v){
      break;
    }
    aux = aux->proximo;
    count++;
  }
  insere_posicaoLista(l, count, v);
}
