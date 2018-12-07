#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "libs/struct_pessoa.c"
#include "libs/quickSort_pessoa.c"
#include "libs/mergeSort_pessoa.c"
#include "libs/bubbleSort_pessoa.c"
#include "libs/selectionSort_pessoa.c"
#include "libs/insertionSort_pessoa.c"

void formataString(char texto[]);
void preenchePessoa(Pessoa **p, int n);
void auto_preenchePessoa(Pessoa **p);
void printPessoa(Pessoa p[], int n);

int main(int argc, char const *argv[]){
  clock_t ti_1, tf_1, ti_2, tf_2, ti_3, tf_3, ti_4, tf_4, ti_5, tf_5;
  double tempo_1, tempo_2, tempo_3, tempo_4, tempo_5;
  int n;
  srand(time(NULL));
  printf("Digite a quantidade de pessoas: ");
  scanf("%d", &n);
  setbuf(stdin, NULL);
  system("clear");
  // n = 5;
  Pessoa **alunos = (Pessoa**)malloc(5*sizeof(Pessoa*));
  for (int i = 0; i < 5; i++) alunos[i] = (Pessoa*)malloc(n*sizeof(Pessoa));

  preenchePessoa(alunos, n);
  // auto_preenchePessoa(alunos);
  int campo = 0;
  char nome_campo[][30] = {"MATRICULA", "NOME", "NOTA"};
  printf("Escolha o campo de ordenação: (MATRICULA-1, NOME-2, NOTA-3): ");
  scanf("%d", &campo);
  setbuf(stdin, NULL);
  system("clear");
  if (campo == MATRICULA) {

    ti_1 = clock();
    quickSort_matricula(alunos[0], n);
    tf_1 = clock();

    ti_2 = clock();
    mergeSort_matricula(alunos[1], n);
    tf_2 = clock();

    ti_3 = clock();
    bubbleSort_matricula(alunos[2], n);
    tf_3 = clock();

    ti_4 = clock();
    selectionSort_matricula(alunos[3], n);
    tf_4 = clock();

    ti_5 = clock();
    insertionSort_matricula(alunos[4], n);
    tf_5 = clock();

  } else if (campo == NOME) {

    ti_1 = clock();
    quickSort_nome(alunos[0], n);
    tf_1 = clock();

    ti_2 = clock();
    mergeSort_nome(alunos[1], n);
    tf_2 = clock();

    ti_3 = clock();
    bubbleSort_nome(alunos[2], n);
    tf_3 = clock();

    ti_4 = clock();
    selectionSort_nome(alunos[3], n);
    tf_4 = clock();

    ti_5 = clock();
    insertionSort_nome(alunos[4], n);
    tf_5 = clock();

  } else if (campo == NOTA){

    ti_1 = clock();
    quickSort_nota(alunos[0], n);
    tf_1 = clock();

    ti_2 = clock();
    mergeSort_nota(alunos[1], n);
    tf_2 = clock();

    ti_3 = clock();
    bubbleSort_nota(alunos[2], n);
    tf_3 = clock();

    ti_4 = clock();
    selectionSort_nota(alunos[3], n);
    tf_4 = clock();

    ti_5 = clock();
    insertionSort_nota(alunos[4], n);
    tf_5 = clock();

  }

  tempo_1 = ( (double) (tf_1 - ti_1) ) / CLOCKS_PER_SEC;
  tempo_2 = ( (double) (tf_2 - ti_2) ) / CLOCKS_PER_SEC;
  tempo_3 = ( (double) (tf_3 - ti_3) ) / CLOCKS_PER_SEC;
  tempo_4 = ( (double) (tf_4 - ti_4) ) / CLOCKS_PER_SEC;
  tempo_5 = ( (double) (tf_5 - ti_5) ) / CLOCKS_PER_SEC;

  printf("\tTempo para ordenar %s por quickSort: %f \n", nome_campo[campo-1], tempo_1);
  printf("\tTempo para ordenar %s por mergeSort: %f \n", nome_campo[campo-1], tempo_2);
  printf("\tTempo para ordenar %s por bubbleSort: %f \n", nome_campo[campo-1], tempo_3);
  printf("\tTempo para ordenar %s por selectionSort: %f \n", nome_campo[campo-1], tempo_4);
  printf("\tTempo para ordenar %s por insertionSort: %f \n", nome_campo[campo-1], tempo_5);
  printf("\n\n");

  // for (int i = 0; i < 5; i++) {
  //   printf("\n\n");
  //   printPessoa(alunos[i], n);
  //   printf("\n\n");
  // }
  for (int i = 0; i < 5; i++) {
    free(alunos[i]);
  }
  free(alunos);
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
void preenchePessoa(Pessoa **p, int n){
  for (int i = 0; i < n; i++) {
    char nome[20];
    int matricula;
    float nota;
    printf("Digite os dados da %d° pessoa\n", i+1);

    printf("\tMatricula: ");
    scanf("%d", &matricula);
    setbuf(stdin, NULL);

    printf("\tNome: ");
    fgets(nome, 29, stdin);
    formataString(nome);
    setbuf(stdin, NULL);

    printf("\tNota: ");
    scanf("%f", &nota);
    setbuf(stdin, NULL);

    for (int j = 0; j < 5; j++) {
      p[j][i].matricula = matricula;
      strcpy(p[j][i].nome, nome);
      p[j][i].nota = nota;
    }
    system("clear");
  }
}
void auto_preenchePessoa(Pessoa **p){
  float notas[] = {34.5, 11.6, 28,9, 22.5, 22.4};
  int matriculas[] = {101, 99, 201, 95, 89};
  char nomes[][30] = {"Eduardo", "Alexandre", "Carlos", "Joao", "Leandro"};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++){
      p[i][j].matricula = matriculas[j];
      strcpy(p[i][j].nome, nomes[j]);
      p[i][j].nota = notas[j];
    }
  }
}
void formataString(char texto[]){
  int len = strlen(texto);
  if(texto[len-1] == '\n') texto[len-1] = 0;
}
