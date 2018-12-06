#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void formataString(char texto[]);
void printVetor(char texto[],char **nomes, int n);
void selectionSort(char **a, int n);
/* includes */
int main(int argc, char const *argv[]){
  int n;
  printf("Entre com a quantidade de nomes: ");
  scanf("%d", &n);
  setbuf(stdin, NULL);

  char **nomes = (char**)malloc(n*sizeof(char*));
  for (int i = 0; i < n; i++) {
    nomes[i] = (char*)malloc(30*sizeof(char));
  }

  system("clear");
  for (int i = 0; i < n; i++) {
    printf("Digite o %d° nome: ", i+1);
    fgets(nomes[i], 29, stdin);
    setbuf(stdin, NULL);

    formataString(nomes[i]);
    system("clear");
  }
  selectionSort(nomes, n);
  printVetor("lista de nomes", nomes, n);
  return 0;
}
void selectionSort(char **a, int n){
  int menor;
  char aux[30];
  for (int i = 0; i < n; i++) {
    menor = i;
    for (int j = i+1; j < n; j++){
      if (strlen(a[j]) < strlen(a[menor])){
        menor = j;
      }
    }
    strcpy(aux, a[i]);
    strcpy(a[i], a[menor]);
    strcpy(a[menor], aux);
  }
}
void printVetor(char texto[], char **nomes, int n){
  printf("%s\n", texto);
  for (int i = 0; i < n; i++) {
    printf("\t%d° %s\n", i+1,nomes[i]);
  }
}
void formataString(char texto[]){
    int len = strlen(texto);
    if(texto[len-1] == '\n') texto[len-1] = 0;
}
