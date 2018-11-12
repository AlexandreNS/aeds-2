#include <stdio.h>
#include <stdlib.h>
#include "libs/lista_dupla_int.c"

int busca_lista(ListaDupla*, int);
/* includes */

int main(int argc, char const *argv[]){
  ListaDupla *lista = criarListaDupla();
  insere_ultimoListaDupla(lista, 1);
  insere_ultimoListaDupla(lista, 123);
  insere_ultimoListaDupla(lista, 22);
  insere_ultimoListaDupla(lista, 122);
  insere_ultimoListaDupla(lista, 321);

  printListaDupla(lista);

  printf("Elemeto 123 na posição %d \n", busca_lista(lista, 123));
  return 0;
}
int busca_lista(ListaDupla* l, int v){
  ElementoDuplo *aux = l->inicio;
  int count = 1;
  int retorno = -1;

  while(aux != NULL){
    if(aux->valor == v){
      retorno = count;
      break;
    }else{
      aux = aux->proximo;
      count++;
    }
  }
  return retorno;
}
