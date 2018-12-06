#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* includes */
void printVetor(char texto[], char a[], int n);
void particionar(int esq, int dir, int *i, int *j, char a[]);
void ordenar(int esq, int dir, char a[]);
void quickSort(char a[], int n);

int main(int argc, char const *argv[]){
  srand(time(NULL));
  char v[11];
  for (int i = 0; i < 10; i++) {
    v[i] = (rand()%26) + 65;
  }
  printf("String :%s\n", v);
  quickSort(v, 10);
  printf("String ordenada :%s\n", v);

  return 0;
}
void particionar(int esq, int dir, int *i, int *j, char a[]) {
  char x, temp;
  *i = esq;
  *j = dir;

  x = a[(*i + *j) / 2];
  do
  {
    while (x < a[*i]){
      (*i)++;
    }
    while (x > a[*j]){
      (*j)--;
    }
    if (*i <= *j){
      temp = a[*i];
      a[*i] = a[*j];
      a[*j] = temp;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}
void quickSort(char a[], int n){
  ordenar(0, n-1, a);
}
void ordenar(int esq, int dir, char a[]){
  int i, j;
  particionar(esq, dir, &i, &j, a);
  if(esq < j) ordenar(esq, j, a);
  if(i < dir) ordenar(i, dir, a);
}
void printVetor(char texto[], char a[], int n){
  printf("%s", texto);
  for (int i = 0; i < n; i++) {
    printf("%c\t", a[i]);
  }
  printf("\n");
}
