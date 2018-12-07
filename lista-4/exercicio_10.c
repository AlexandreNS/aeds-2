#include <stdio.h>
#include <stdlib.h>

void particionar(int esq, int dir, int *i, int *j, int a[]);
void quickSort(int a[], int n);
void ordenar(int esq, int dir, int a[]);
void insertionSort(int a[], int n);
void printVetor(char texto[], int a[], int n);

int main(int argc, char const *argv[]){
  int v[1000];
  for (int i = 1000; i > 0; i--) {
    v[1000-i] = i;
  }
  printVetor("Vetor: ", v, 1000);
  quickSort(v, 1000);
  printf("\n\n\n");
  printVetor("Vetor Ordenado: ", v, 1000);
  return 0;
}
void particionar(int esq, int dir, int *i, int *j, int a[]) {
  int x, temp;
  *i = esq;
  *j = dir;
  x = a[(*i + *j) / 2];
  do
  {
    while (x > a[*i]){
      (*i)++;
    }
    while (x < a[*j]){
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
void quickSort(int a[], int n){
  ordenar(0, n-1, a);
}
void ordenar(int esq, int dir, int a[]){
  int i, j;
  particionar(esq, dir, &i, &j, a);
  if(j-esq < 100) insertionSort(a+esq, j-esq);
  else if(esq < j) ordenar(esq, j, a);

  if(dir-i < 100) insertionSort(a+i, dir-i);
  else if(i < dir) ordenar(i, dir, a);
}
void insertionSort(int a[], int n){
  int j;
  int x;
  for(int i = 1; i < n; i++){
    x = a[i];
    j = i-1;
    while(x < a[j] && j >= 0){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = x;
  }
}
void printVetor(char texto[], int a[], int n){
  printf("%s", texto);
  for (int i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  printf("\n");
}
