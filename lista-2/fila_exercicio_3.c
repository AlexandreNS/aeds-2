#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/filaDinamica_int.c"

int fila_cmp(Fila*, Fila*);

int main(int argc, char const *argv[]){
  Fila *f1 = criaFila();
  inserirFila(f1, 1223);
  inserirFila(f1, 1223);
  inserirFila(f1, 1223);
  inserirFila(f1, 1223);
  inserirFila(f1, 1223);
  inserirFila(f1, 1223);

  Fila *f2 = criaFila();
  inserirFila(f2, 7);
  inserirFila(f2, 7);
  inserirFila(f2, 7);
  inserirFila(f2, 7);
  inserirFila(f2, 7);

  int cmp_value = fila_cmp(f1, f2);
  if(cmp_value != 0) printf("%s\n", cmp_value == 1 ?
    "A 2° fila é maior que a 1°" : "A 1° fila é maior que a 2°" );
  else printf("As filas possuem o mesmo tamanho\n");

}

int fila_cmp(Fila* f1, Fila* f2){
  int temp;
  while(!filaVazia(f1) && !filaVazia(f2)){
    retirarFila(f1, &temp);
    retirarFila(f2, &temp);
  }
  if (filaVazia(f1) && filaVazia(f2)) return 0;
  else if (filaVazia(f1)) return 1;
  else return 2;
}
