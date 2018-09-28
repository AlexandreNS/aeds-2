#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/pilhaDinamica_int.c"

int count_impar_pilha(Pilha*);

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
  printf("\nA pilha apresenta %d numero(s) impar(es)\n", count_impar_pilha(pilha));
  return 0;
}

int count_impar_pilha(Pilha *pilha){
  int impares = 0;
  int temp;
  while (!pilhaVazia(pilha)) {
    desempilha(pilha, &temp);
    if(temp % 2 == 1) impares++;
  }
  return impares;
}
