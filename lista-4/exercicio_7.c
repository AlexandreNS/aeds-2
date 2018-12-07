#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/struct_pessoa.c"
#include "libs/quickSort_pessoa.c"
#include "libs/mergeSort_pessoa.c"
#include "libs/bubbleSort_pessoa.c"
#include "libs/selectionSort_pessoa.c"
#include "libs/insertionSort_pessoa.c"

void formataString(char texto[]);
void preenchePessoa(Pessoa p[], int n);
void auto_preenchePessoa(Pessoa p[]);
void printPessoa(Pessoa p[], int n);

int main(int argc, char const *argv[]){
  // int n;
  // printf("Digite a quantidade de pessoas: ");
  // scanf("%d", &n);
  // setbuf(stdin, NULL);
  // system("clear");

  // Pessoa *alunos = (Pessoa*)malloc(n*sizeof(Pessoa));
  Pessoa *alunos = (Pessoa*)malloc(5*sizeof(Pessoa));

  // preenchePessoa(alunos, n);
  auto_preenchePessoa(alunos);
  quickSort_nota(alunos, 5);
  // printPessoa(alunos, n);
  printPessoa(alunos, 5);
  return 0;
}
void printPessoa(Pessoa p[], int n){
  for (int i = 0; i < n; i++) {
    printf("Dados da %d° pessoa:\n", i+1);
    printf("\tMatricula: %d\n", p[i].matricula);
    printf("\tNome: %s\n", p[i].nome);
    printf("\tNota: %f\n\n", p[i].nota);
  }
}
void preenchePessoa(Pessoa p[], int n){
  for (int i = 0; i < n; i++) {
    printf("Digite os dados da %d° pessoa\n", i+1);

    printf("\tMatricula: ");
    scanf("%d", &p[i].matricula);
    setbuf(stdin, NULL);

    printf("\tNome: ");
    fgets(p[i].nome, 29, stdin);
    formataString(p[i].nome);
    setbuf(stdin, NULL);

    printf("\tNota: ");
    scanf("%f", &p[i].nota);
    setbuf(stdin, NULL);

    system("clear");
  }
}
void auto_preenchePessoa(Pessoa p[]){
  float notas[] = {34.5, 11.6, 28,9, 22.5, 22.4};
  int matriculas[] = {101, 99, 201, 95, 89};
  char nomes[][30] = {"Eduardo", "Alexandre", "Carlos", "Joao", "Leandro"};
  for (int i = 0; i < 5; i++) {
    p[i].matricula = matriculas[i];
    strcpy(p[i].nome, nomes[i]);
    p[i].nota = notas[i];
  }
}
void formataString(char texto[]){
    int len = strlen(texto);
    if(texto[len-1] == '\n') texto[len-1] = 0;
}
