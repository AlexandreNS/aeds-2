#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/lista_dinamica_int.c"
/* includes */
int inverte_lista(Lista*);
int troca_elementos(Lista*, int, int);
int main(int argc, char const *argv[]){
  Lista *lista = criarLista();
  insere_ultimoLista(lista, 1);
  insere_ultimoLista(lista, 2);
  insere_ultimoLista(lista, 3);
  insere_ultimoLista(lista, 4);
  insere_ultimoLista(lista, 5);

  printf("\tLista Original:\n");
  printLista(lista);

  inverte_lista(lista);

  printf("\n\tLista Invertida:\n");
  printLista(lista);
  return 0;
}
int inverte_lista(Lista* l){
  int count_A = countLista(l);
  int count_B = 1;
  while(count_A > count_B){
    troca_elementos(l, count_A, count_B);
    count_A--;
    count_B++;
  }
}

int troca_elementos(Lista* l, int p1, int p2){
    int count = countLista(l);
    if((count < p1 || count < p2) || (p1 == p2)) return 0;
    else{
      int aux_pos = p1;
      p1 = p1 < p2 ? p1 : p2;
      p2 = p2 > p1 ? p2 : aux_pos;

      if(p1 == 1){
        if(p1+1 == p2){
          Elemento *aux = l->inicio->proximo;
          l->inicio->proximo = aux->proximo;
          aux->proximo = l->inicio;
          l->inicio = aux;
        }else{
          Elemento *aux_ini = l->inicio;
          Elemento *aux_ini_prox = l->inicio->proximo;
          Elemento *aux_ant_p2 = l->inicio;
          int count_pos2 = 1;
          while (count_pos2 < p2-1) {
            aux_ant_p2 = aux_ant_p2->proximo;
            count_pos2++;
          }

          l->inicio->proximo = aux_ant_p2->proximo->proximo;
          aux_ant_p2->proximo->proximo = aux_ini_prox;
          l->inicio = aux_ant_p2->proximo;
          aux_ant_p2->proximo = aux_ini;
        }
      }else{
        if(p1+1 == p2){
          Elemento *aux_ant_p1 = l->inicio;
          int count_pos1 = 1;
          while (count_pos1 < p1-1) {
            aux_ant_p1 = aux_ant_p1->proximo;
            count_pos1++;
          }
          Elemento *aux_p1 = aux_ant_p1->proximo;
          Elemento *aux_p2 = aux_ant_p1->proximo->proximo;

          aux_p1->proximo = aux_p2->proximo;
          aux_p2->proximo = aux_p1;
          aux_p1 = aux_p2;
          aux_ant_p1->proximo = aux_p2;
        }else{
          Elemento *aux_ant_p1 = l->inicio;
          int count_pos1 = 1;
          while (count_pos1 < p1-1) {
            aux_ant_p1 = aux_ant_p1->proximo;
            count_pos1++;
          }

          Elemento *aux_p1 = aux_ant_p1->proximo;
          Elemento *aux_p1_prox = aux_ant_p1->proximo->proximo;

          Elemento *aux_ant_p2 = l->inicio;
          int count_pos2 = 1;
          while (count_pos2 < p2-1) {
            aux_ant_p2 = aux_ant_p2->proximo;
            count_pos2++;
          }

          aux_p1->proximo = aux_ant_p2->proximo->proximo;
          aux_ant_p2->proximo->proximo = aux_p1_prox;
          aux_ant_p1->proximo = aux_ant_p2->proximo;
          aux_ant_p2->proximo = aux_p1;
        }
      }
    }
    return 1;
}
