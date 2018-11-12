#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
#include "libs/lista_dupla_int.c"

typedef struct ListaEstaticaTag{
  int quant;
  int vetor[100];

} ListaEstatica;
/* includes */
int insere_asc_value_lista(ListaDupla*, int);
int insere_asc_lista(ListaDupla*, Lista*, ListaEstatica*);

int main(int argc, char const *argv[]){
  Lista *lista1 = criarLista();
  insere_ultimoLista(lista1, 12);
  insere_ultimoLista(lista1, 3);
  insere_ultimoLista(lista1, 4);
  insere_ultimoLista(lista1, 6);

  ListaEstatica *lista2 = (ListaEstatica*)malloc(sizeof(ListaEstatica));
  lista2->quant = 10;
  for (int i = 0; i < 10; i++) {
    lista2->vetor[i] = i*i+2*i+10;
  }

  ListaDupla *lista_ord = criarListaDupla();
  insere_asc_lista(lista_ord, lista1, lista2);

  printf("\tLista Crescente: \n");
  printListaDupla(lista_ord);

  return 0;
}
int insere_asc_value_lista(ListaDupla* l, int v){
  ElementoDuplo *aux = l->inicio;
  int count = 1;
  while(aux != NULL){
    if(aux->valor >= v){
      break;
    }
    aux = aux->proximo;
    count++;
  }
  insere_posicaoListaDupla(l, count, v);
}
int insere_asc_lista(ListaDupla* lden, Lista* len, ListaEstatica* le){
  Elemento *aux_len = len->inicio;
  while(aux_len != NULL){
    insere_asc_value_lista(lden, aux_len->valor);
    aux_len = aux_len->proximo;
  }
  for (int i = 0; i < le->quant; i++) {
    insere_asc_value_lista(lden, le->vetor[i]);
  }
}
