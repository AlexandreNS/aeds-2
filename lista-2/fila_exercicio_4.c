#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/filaDinamica_int.c"

void preenche_fila(Fila*, Fila*, Fila*);
void ordenaFila(Fila*);
void bubble_sort(int[], int);

int main(int argc, char const *argv[]){
  Fila *fila1, *fila2, *fila_ordenada;

  fila1 = criaFila();
  inserirFila(fila1, 5);
  inserirFila(fila1, 45);
  inserirFila(fila1, 15);
  inserirFila(fila1, 4);
  inserirFila(fila1, 22);
  ordenaFila(fila1);

  fila2 = criaFila();
  inserirFila(fila2, 321);
  inserirFila(fila2, 42);
  inserirFila(fila2, 213);
  inserirFila(fila2, 123);
  inserirFila(fila2, 1);
  inserirFila(fila2, 1);
  ordenaFila(fila2);

  fila_ordenada = criaFila();
  preenche_fila(fila1, fila2, fila_ordenada);

  int temp;
  while (!filaVazia(fila_ordenada)) {
    retirarFila(fila_ordenada, &temp);
    printf("Elemento retirado da fila: %d\n", temp);
  }

  return 0;
}

void preenche_fila(Fila* fila1, Fila* fila2, Fila* saida){
  int value_1, value_2;
  int isset_value1 = 0, isset_value2 = 0;
  while (!filaVazia(fila1) || !filaVazia(fila2)) {
    if (!isset_value1 && !filaVazia(fila1)){
      retirarFila(fila1, &value_1);
      isset_value1 = 1;
    }
    if (!isset_value2 && !filaVazia(fila2)){
      retirarFila(fila2, &value_2);
      isset_value2 = 1;
    }
    if(isset_value1 && isset_value2){
      if (value_1 < value_2){
        inserirFila(saida, value_1);
        isset_value1 = 0;
      }else{
        inserirFila(saida, value_2);
        isset_value2 = 0;
      }
    }else if(isset_value1){
      inserirFila(saida, value_1);
      isset_value1 = 0;
    }else if(isset_value2){
      inserirFila(saida, value_2);
      isset_value2 = 0;
    }
  }
}

void ordenaFila(Fila* fila){
  int *vetor = (int*)malloc(sizeof(int));
  int tam = 0;
  for(int i = 0; !filaVazia(fila); i++) {
    tam++;
    vetor = (int*)realloc(vetor, sizeof(int)*tam);
    retirarFila(fila, &vetor[i]);
  }
  bubble_sort(vetor, tam);
  for (int i = 0; i < tam; i++) {
    inserirFila(fila, vetor[i]);
  }
}

void bubble_sort(int vet[], int tamanho) {
  int aux;
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho-1; j++) {
      if (vet[j] > vet[j+1]) {
        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;
      }
    }
  }
}
