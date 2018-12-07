#include <stdio.h>
#include <stdlib.h>

void shellSort(int a[], int n);
void printVetor(char texto[], int a[], int n);
/* includes */
int main(int argc, char const *argv[]){
  int v[10];
  for (int i = 10; i > 0; i--) {
    v[10-i] = i;
  }
  printVetor("Vetor: ", v, 10);
  shellSort(v, 10);
  printVetor("Vetor Ordenado: ", v, 10);
  return 0;
}

void shellSort(int a[], int n){
  int i, j, aux;
  int gap = 1;
  while (gap < n) {
    gap = 3*gap+1;
  }
  while(gap > 1){
    gap /= 3;
    for(i = gap; i < n; i++){
      aux = a[i];
      j = i;
      while (j >= gap && aux < a[j - gap]) {
        a[j] = a[j - gap];
        j = j - gap;
      }
      a[j] = aux;
    }
  }
}
void printVetor(char texto[], int a[], int n){
  printf("%s", texto);
  for (int i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  printf("\n");
}
