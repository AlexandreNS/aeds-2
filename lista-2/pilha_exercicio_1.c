#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/pilhaDinamica_char.c"

void inverte_string(char[], char[]);
void formataString(char[]);

int main(int argc, char const *argv[]){
  char texto_entrada[50], texto_saida[50];
  printf("Digite uma String para inverter palavra por palavra:\n\t");
  fgets(texto_entrada, 49, stdin);
  setbuf(stdin, NULL);

  inverte_string(texto_entrada, texto_saida);
  printf("String invertida:\n\t%s\n", texto_saida);
  return 0;
}

void inverte_string(char entrada[], char saida[]){
  formataString(entrada);

  Pilha *caracteres = criaPilha();
  for (int i = 0; entrada[i] != '.' && entrada[i] != '\0' ; i++) {
    if(entrada[i] == ' '){
      while(!pilhaVazia(caracteres)){
        desempilha(caracteres, &saida[strlen(saida)]);
      }
      saida[strlen(saida)] = ' ';
    }else{
      empilha(caracteres, entrada[i]);
    }
  }
  while(!pilhaVazia(caracteres)){
    desempilha(caracteres, &saida[strlen(saida)]);
  }
}
void formataString(char texto[]){
  int len = strlen(texto);
  if(texto[len-1] == '\n') texto[len-1] = 0;
}
