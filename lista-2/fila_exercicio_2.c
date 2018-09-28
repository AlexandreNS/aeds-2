#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_float.c"
#include "libs/filaDinamica_float.c"

int min_max_media(Fila*, float*, float*, float*);

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

  float min, max, media;
  if(min_max_media(fila, &min, &max, &media)){
    printf("Resultado\n");
    printf("\tMenor: %f\n", min);
    printf("\tMaior: %f\n", max);
    printf("\tMedia: %f\n", media);
  }
  return 0;
}

int min_max_media(Fila *fila, float* min, float* max, float* media){
  if(filaVazia(fila)) return 0;
  else{
    int count = 1;
    float current, soma = 0;
    retirarFila(fila, &current);
    soma += current;
    *min = current;
    *max = current;
    while (!filaVazia(fila)){
      retirarFila(fila, &current);
      if(current > *max) *max = current;
      if(current < *min) *min = current;
      soma += current;
      count++;
    }
    *media = soma/count;
    return 1;
  }
}
