#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/lista_string.c"
/* includes */
void formataString(char texto[]);
void insertion_name(Lista*, char*);

int main(int argc, char const *argv[]){
  Lista* nomes = criarLista();
  char nome[30];
  int n;

  printf("Entre com a quantidade de nomes: ");
  scanf("%d", &n);
  setbuf(stdin, NULL);

  system("clear");
  for (int i = 0; i < n; i++) {
    printf("Digite o %d° nome: ", i+1);
    fgets(nome, 29, stdin);
    setbuf(stdin, NULL);

    formataString(nome);
    insertion_name(nomes, nome);

    system("clear");
  }
  printLista(nomes);
  return 0;
}

void insertion_name(Lista* l, char* nome){
  Elemento* aux = l->inicio;
  int p = 1;
  while(aux != NULL){
    if( strcmp(nome, aux->nome) <= 0 ) break;
    else p++;
    aux = aux->proximo;
  }
  insere_posicaoLista(l, p, nome);
}
void formataString(char texto[]){
    int len = strlen(texto);
    if(texto[len-1] == '\n') texto[len-1] = 0;
}
