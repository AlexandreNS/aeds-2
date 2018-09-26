#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/pilhaDinamica_char.c"

int palindromo(char[]);
void formataString(char[]);

int main(int argc, char const *argv[]){
  char texto[100];
  printf("Digite uma palavra:\n");
  fgets(texto, 99, stdin);
  setbuf(stdin, NULL);

  printf("%s\n", palindromo(texto) ? "Esta palavra é um palíndromo" : "Esta palavra não é um palíndromo");
  return 0;
}

void formataString(char texto[]){
  int len = strlen(texto);
  if(texto[len-1] == '\n') texto[len-1] = 0;
}

int palindromo(char palavra[]){
  formataString(palavra);

  Pilha *invertido = criaPilha();
  for (int i = 0; palavra[i] != '\0'; i++) {
    empilha(invertido, palavra[i]);
  }
  for (int i = 0; palavra[i] != '\0'; i++) {
    char c;
    desempilha(invertido, &c);
    if (c != palavra[i]) return 0;
  }
  return 1;
}
