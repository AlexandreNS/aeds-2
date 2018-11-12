#include <stdio.h>
#include <stdlib.h>
#include "libs/lista_estatica.c"

void remove_ordenado(Lista*, int);
/* includes */
int main(int argc, char const *argv[]){
  Lista* lista = criarLista();
  insere_ultimoLista(lista, 11);
  insere_ultimoLista(lista, 22);
  insere_ultimoLista(lista, 33);
  insere_ultimoLista(lista, 44);
  insere_ultimoLista(lista, 55);
  printLista(lista);

  remove_ordenado(lista, 33);
  printLista(lista);

  return 0;
}
void remove_ordenado(Lista* l, int v){
  int isset_value = 0;
  for (int i = 0; i < l->quant; i++) {
    if(v == l->vetor[i]) isset_value = 1;
    if(isset_value && i != l->quant-1){
      l->vetor[i] = l->vetor[i+1];
    }
  }
  l->quant--;
}
