#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/filaDinamica_int.c"

int count_par_fila(Fila*);

int main(int argc, char const *argv[]){
  int count;
  float temp;
  Fila *fila = criaFila();

  printf("Quantos numeros deseja inserir:\n");
  scanf("%d", &count);
  setbuf(stdin, NULL);

  for(int i = 0; i < count; i++){

    printf("Digite o %d° numero\n", i+1);
    scanf("%f", &temp);
    inserirFila(fila, temp);
    setbuf(stdin, NULL);

  }
  printf("\nA fila apresenta %d numero(s) par(es)\n", count_par_fila(fila));
  return 0;
}

int count_par_fila(Fila *fila){
  int pares = 0;
  int temp;
  while (!filaVazia(fila)) {
    retirarFila(fila, &temp);
    if(temp % 2 == 0) pares++;
  }
  return pares;
}
