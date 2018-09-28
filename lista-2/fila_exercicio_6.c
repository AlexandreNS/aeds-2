#include <stdio.h>
#include <stdlib.h>
#include "libs/elemento_int.c"
#include "libs/pilhaDinamica_int.c"
#include "libs/filaDinamica_int.c"
// Faz a mesma coisa que o "fila_exercicio_1.c"
void inverte(Fila*);

int main(int argc, char const *argv[]){
  int count;
  int temp;
  Fila *fila_teste = criaFila();

  printf("Quantos numeros deseja inserir:\n");
  scanf("%d", &count);
  setbuf(stdin, NULL);

  for(int i = 0; i < count; i++){
    printf("Digite o %d° numero\n", i+1);
    scanf("%d", &temp);
    inserirFila(fila_teste, temp);
    setbuf(stdin, NULL);
  }

  printf("\n");
  inverte(fila_teste);

  while (!filaVazia(fila_teste)) {
    retirarFila(fila_teste, &temp);
    printf("Elemento retirado da fila: %d\n", temp);
  }
  return 0;
}

void inverte(Fila* fila){
  Pilha *pilha = criaPilha();
  int temp;
  while(!filaVazia(fila)){
    retirarFila(fila, &temp);
    empilha(pilha, temp);
  }
  while(!pilhaVazia(pilha)){
    desempilha(pilha, &temp);
    inserirFila(fila, temp);
  }
}
