#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
/* includes */
int veri_lista_order(Lista*);

int main(int argc, char const *argv[]){
  Lista *lista = criarLista();
  insere_ultimoLista(lista, 1);
  insere_ultimoLista(lista, 2);
  insere_ultimoLista(lista, 3);
  insere_ultimoLista(lista, 45);
  insere_ultimoLista(lista, 54);
  insere_ultimoLista(lista, 63);
  insere_ultimoLista(lista, 71);
  printLista(lista);

  int order = veri_lista_order(lista);
  if(order == -1 || order == 1)
    printf("A lista está na ordem %s\n", (order == -1 ? "decrescente" : "crescente" ));
  else if(order == 2) printf("Todos os elementos da lista são iguais\n");
  else printf("A lista não está ordenada\n");
  return 0;
}
int veri_lista_order(Lista* l){
  Elemento *aux = l->inicio;
  int isset_asc = 1;
  int isset_desc = 1;

  int ant_value = aux->valor;

  aux = aux->proximo;
  while(aux != NULL){
    if(ant_value < aux->valor) isset_desc = 0;
    if(ant_value > aux->valor) isset_asc = 0;
    ant_value = aux->valor;
    aux = aux->proximo;
  }
  if(isset_asc && isset_desc) return 2;
  if(isset_asc) return 1;
  if(isset_desc) return -1;
  return 0;
}
