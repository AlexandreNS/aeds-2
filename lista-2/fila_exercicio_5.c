#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/filaDinamica_int.c"

void concatenar_filas(Fila*, Fila*);

int main(int argc, char const *argv[]){
  Fila *f1 = criaFila();
  inserirFila(f1, 1);
  inserirFila(f1, 2);
  inserirFila(f1, 3);
  inserirFila(f1, 4);
  inserirFila(f1, 5);
  inserirFila(f1, 6);

  Fila *f2 = criaFila();
  inserirFila(f2, 21);
  inserirFila(f2, 22);
  inserirFila(f2, 23);
  inserirFila(f2, 24);
  inserirFila(f2, 25);

  concatenar_filas(f1, f2);
  int temp;
  while (!filaVazia(f1)) {
    retirarFila(f1, &temp);
    printf("Elemento retirado da fila: %d\n", temp);
  }

  return 0;
}

void concatenar_filas(Fila* fila1, Fila* fila2){
  int temp;
  while (!filaVazia(fila2)) {
    retirarFila(fila2, &temp);
    inserirFila(fila1, temp);
  }
}
