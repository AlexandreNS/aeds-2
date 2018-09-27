#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_float.c"
#include "libs/pilhaDinamica_float.c"

int min_max_media(Pilha*, float*, float*, float*);

int main(int argc, char const *argv[]){
  int count;
  float temp;
  Pilha *pilha = criaPilha();

  printf("Quantos numeros deseja inserir:\n");
  scanf("%d", &count);
  setbuf(stdin, NULL);

  for(int i = 0; i < count; i++){

    printf("Digite o %d° numero\n", i+1);
    scanf("%f", &temp);
    empilha(pilha, temp);
    setbuf(stdin, NULL);

  }

  float min, max, media;
  if(min_max_media(pilha, &min, &max, &media)){
    printf("Resultado\n");
    printf("\tMenor: %f\n", min);
    printf("\tMaior: %f\n", max);
    printf("\tMedia: %f\n", media);
  }
  return 0;
}

int min_max_media(Pilha *pilha, float* min, float* max, float* media){
  if(pilhaVazia(pilha)) return 0;
  else{
    int count = 1;
    float current, soma = 0;
    desempilha(pilha, &current);
    soma += current;
    *min = current;
    *max = current;
    while (!pilhaVazia(pilha)){
      desempilha(pilha, &current);
      if(current > *max) *max = current;
      if(current < *min) *min = current;
      soma += current;
      count++;
    }
    *media = soma/count;
    return 1;
  }
}
