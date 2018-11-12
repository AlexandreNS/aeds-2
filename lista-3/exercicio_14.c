#include <stdio.h>
#include <stdlib.h>
#include "libs/lista_estatica.c"

void insere_ordenado(Lista*, int);
/* includes */
int main(int argc, char const *argv[]){
  Lista* lista = criarLista();
  insere_ordenado(lista, 2);
  insere_ordenado(lista, 1);
  insere_ordenado(lista, 5);
  insere_ordenado(lista, 4);
  insere_ordenado(lista, 3);


  printLista(lista);
  return 0;
}
void insere_ordenado(Lista* l, int v){
  if(l->quant == 0){
    l->vetor[0] = v;
    l->quant++;
  }else{
    for (int i = l->quant+1; i > 0; i--) {
      if(i == 1) l->vetor[i-1] = v;
      else if(v >= l->vetor[i-2]){
        l->vetor[i-1] = v;
        break;
      }
      else l->vetor[i-1] = l->vetor[i-2];
    }
    l->quant++;
  }
}
