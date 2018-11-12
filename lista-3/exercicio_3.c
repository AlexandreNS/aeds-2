#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
/* includes */

int max_lista(Lista*, int*, int*);

int main(int argc, char const *argv[]){
  Lista *lista = criarLista();
  insere_ultimoLista(lista, 1);
  insere_ultimoLista(lista, 42);
  insere_ultimoLista(lista, 3);
  insere_ultimoLista(lista, 4);
  insere_ultimoLista(lista, 5);
  insere_ultimoLista(lista, 6);

  printf("\tDados da Lista\n");
  printLista(lista);
  int pos, val;
  if (max_lista(lista, &pos, &val)){
    printf("\nElemento[%d] = %d; é o maior da lista\n", pos, val);
  }else{
    printf("\nNão foi possivel encontrar o maior elemento da Lista\n");
  }

  return 0;
}

int max_lista(Lista* l, int* p, int* v){
  Elemento *aux = l->inicio;
  if(aux == NULL) return 0;
  else{
    int count = 2;
    *p = count;
    *v = aux->valor;
    aux = aux->proximo;
    while(aux != NULL){
      if(aux->valor > *v){
        *p = count;
        *v = aux->valor;
      }

      count++;
      aux = aux->proximo;
    }
    return 1;

  }
}
